#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
All the functions related to the management of students variables.
*******************************************************************************/


/*The create_student function creates a Student variable
and returns its pointer*/
Student *create_student()
{
    Student *stud;
    stud = malloc(sizeof(Student));
    char str1[sizeName], str2[sizeFieldStudi], str3[sizeStudentCity];
    int ind1, ind2, ind3, ind4, ind5;

    fflush(stdin);  //Security
    //The user enters all informations about the new student
    printf("\nName : "); scanf("%[^\n%]*c", str1);
    printf("\nAge : "); scanf("%d", &ind1);
    printf("\nYear of study : "); scanf("%d", &ind2);
    fflush(stdin);
    printf("\nField of study : "); scanf("%[^\n%]*c", str2);
    fflush(stdin);
    printf("\nCity of residence : "); scanf("%[^\n%]*c", str3);
    display_interest(); printf("\n");
    fflush(stdin);
    printf("- "); scanf("%d", &ind3);
    printf("- "); scanf("%d", &ind4);
    printf("- "); scanf("%d", &ind5);

    //Create this new student
    Student stur={
        .age = ind1, .yearStudy = ind2, .interest = {
        tabOfInterest[ind3-1], tabOfInterest[ind4-1], tabOfInterest[ind5-1]},
        .follower.maxElement = 0, .follower.nbrFollower = 0,
        .follower.known = 0, .follower.suggestionCount = 0,
    };
    copy_array_char(stur.name, str1, sizeName, sizeName);
    copy_array_char(stur.fieldStudy, str2, sizeFieldStudi, sizeFieldStudi);
    copy_array_char(
        stur.cityResidence, str3, sizeStudentCity, sizeStudentCity
    );

    /* Copy of the new student in the returned address */
    *stud = stur;
    ecrire_student(stud);
    return(stud);
}


/*The add_student function takes the pointer of a student as argument
and adds this student to the glossary*/
int add_student(Student *stud)
{
    //Finding the right chapter in the glossary
    char readChar = stud->name[0];
    int i = 0;
    while (readChar != glossary[i].letter && i < 27){
        i++;
    }
    if (readChar == glossary[i].letter){
        //If the chapter of glossary does not contain any element
        if (glossary[i].beginList == NULL){
            stud->nextAlphaStudent = NULL;
            glossary[i].beginList = stud;
            return 0;
        } else {
            Student *ptr = glossary[i].beginList;
            int compare = compare_strings(stud->name, ptr->name);
            //If the chapter contains one element that comes after stud
            if (compare == -1 || compare == 0){
                stud->nextAlphaStudent = glossary[i].beginList;
                glossary[i].beginList = stud;
                //Necessary step because glossary[i].beginList is not a Student
                return 0;
            } else {
                while (ptr->nextAlphaStudent != NULL){
                    Student nextElement = *(ptr->nextAlphaStudent);
                    int compare = compare_strings(stud->name, nextElement.name);
                    //If stud comes before nextElement
                    if (compare == -1 || compare == 0){
                        stud->nextAlphaStudent = ptr->nextAlphaStudent;
                        ptr->nextAlphaStudent = stud;
                        return 0;
                    } else {
                        //If stud comes after nextElement
                        ptr = ptr->nextAlphaStudent;
                    }
                }
                //If stud is the last element of the chapter
                if (ptr->nextAlphaStudent == NULL){
                    stud->nextAlphaStudent = NULL;
                    ptr->nextAlphaStudent = stud;
                    return 0;
                }
            }
        }
    } else {
        //The chapter for stud has not been found
        return 1;
    }
}

/******************************************************************************/

/*The find_student function takes a character string as argument
and returns wether the pointer to the student who have the character string as name
or NULL if none of the students have the character string as name*/
Student *find_student(char *name)
{
    Student *foundStudent;
    int i = 0;
    //Find the right chapter in the glossary that matches with the 1st letter of the name
    while (glossary[i].letter != name[0] && i < 27){
        i++;
    }
    if (glossary[i].letter == name[0]){
        if (glossary[i].beginList == NULL){
            //The student does not exist
            return (NULL);
        } else {
            /*This section compares the name given as parameter
            with the first element of the right chapter in the glossary*/
            int compare = compare_strings(glossary[i].beginList->name, name);
            //Return wether 0, 1 or -1
            if (compare == 0){
                //The student has been found
                foundStudent = glossary[i].beginList;
                return (foundStudent);
            } else if (compare == -1){
                //The student does not exist because the glossary is in alphabetical order
                return (NULL);
            } else {
                /*This section compares the name given as parameter
                with every element of the right chapter in the glossary*/
                Student *ptr = glossary[i].beginList->nextAlphaStudent;
                while (ptr != NULL){
                    compare = compare_strings(ptr->name, name);
                    if (compare == 0){
                        //The student has been found
                        foundStudent = ptr;
                        return (foundStudent);
                    } else if (compare == -1){
                        //The student does not exist because the glossary is in alphabetical order
                        return (NULL);
                    } else {
                        ptr = ptr->nextAlphaStudent;
                    }
                }
                if (ptr == NULL){
                    //The student does not exist in the chapter where he was supposed to be
                    return (NULL);
                }
            }
        }
    }
    printf("Invalid syntax\n"); //The entered name is not a name
    return (NULL);
}

/******************************************************************************/

/*The add_follow function takes two pointers of students as arguments
and adds the *follow student to the list of follows of the *stud student*/
void add_follow(Student *stud, Student *follow)
{
    if (follow != stud){
        if (stud->follower.maxElement == 0){
            /*
            If *stud has no space in its list of follows
            10 follow slots are allocated
            */
            stud->follower.listFollower = (Student**)malloc(10 * sizeof(Student*));
            stud->follower.maxElement = 10;
            stud->follower.listFollower[stud->follower.nbrFollower] = follow; //Add follow to the list of follows of *stud
            stud->follower.nbrFollower++;
        } else if (stud->follower.nbrFollower < stud->follower.maxElement){
            /*If *stud has enough space in its list of follows*/
            stud->follower.listFollower[stud->follower.nbrFollower] = follow; //Add follow to the list of follows of *stud
            stud->follower.nbrFollower++;
        } else {
            /*If *stud has not enough space in its list of follows
            5 follow slots are allocated
            */
            stud->follower.listFollower = (Student**)realloc(stud->follower.listFollower, 5 * sizeof(Student*));
            stud->follower.maxElement += 5;
            stud->follower.listFollower[stud->follower.nbrFollower] = follow; //Add follow to the list of follows of *stud
            stud->follower.nbrFollower++;
        }
    } else {
        printf("You cannot follow yourself\n");
    }
}


/*The delete_follow function takes two pointers of students as arguments
and deletes the *follow student from the list of follows of the *stud student*/
void delete_follow(Student* stud, Student* follow)
{
    int i = 0;
    //Find follow in the list of follow of *stud
    while (stud->follower.listFollower[i] != follow && i < stud->follower.nbrFollower){
        i++;
    }
    if (stud->follower.listFollower[i] == follow){
        //Remove the follow and reorganize the list of follows of *stud
        for (int j = i; j < stud->follower.nbrFollower; j++){
            stud->follower.listFollower[j] = stud->follower.listFollower[j+1];
        }
        stud->follower.listFollower[stud->follower.nbrFollower] = NULL;
        stud->follower.nbrFollower--;
        printf("\nThis student got removed from your list of follows\n");
    } else {
        printf("\nYou are not currently following this student\n");
    }
}


/*The suggest_follows function takes a pointer to a student, an array of pointers to students
and a number of suggestions as arguments, it returns the array containing follows suggestions.
The number of suggestions is can reach a maximum of nbrSuggestion
depending on the number of links already existing.
If the student whose pointer is given does not follow anyone
then the suggestions will be based on fields of interest*/
void suggest_follows(Student *stud,Student **suggestionTab, int nbrSuggestion){
    //Initialize the array of suggestions
    for (int t = 0; t < nbrSuggestion; t++){
        suggestionTab[t] = NULL;
    }
    if (stud->follower.nbrFollower > 0){
        //If *stud follows at least one student
        int max = 0;
        Student *bestFollow = NULL;
        Student *linkDeg1, *linkDeg2, *linkDeg3, *linkDeg4;
        /*Every student in the list of follows of *stud are spotted*/
        stud->follower.known = 1;
        for (int i = 0; i < stud->follower.nbrFollower; i++){
            stud->follower.listFollower[i]->follower.known = 1;
        }

        /*This part gives every student amongst the follows of follows of follows of follows of *stud
        a score that corresponds to the chance he has to be known by *stud*/
        for (int i = 0; i < stud->follower.nbrFollower; i++){
            linkDeg1 = stud->follower.listFollower[i];
            /*Browse the follows of *stud follows*/
            for (int j = 0; j < linkDeg1->follower.nbrFollower; j++){
                linkDeg2 = linkDeg1->follower.listFollower[j];
                if (linkDeg2->follower.known != 1){
                    //If this student is not already followed
                    linkDeg2->follower.suggestionCount += 3; //Increase the chances that *stud would know this student
                    if (linkDeg2->follower.suggestionCount > max){
                        //If this student has the highest chance to be known
                        max = linkDeg2->follower.suggestionCount; //Increase the highest chance
                        bestFollow = linkDeg2;
                    }
                }
                if (linkDeg2 != stud){
                    for (int k = 0; k < linkDeg2->follower.nbrFollower; k++){
                        linkDeg3 = linkDeg2->follower.listFollower[k];
                        /*Browse the follows of the follows of *stud follows*/
                        if (linkDeg3->follower.known != 1){
                            //If this student is not already followed
                            linkDeg3->follower.suggestionCount += 2; //Increase the chances that *stud would know this student
                            if (linkDeg3->follower.suggestionCount > max){
                                //If this student has the highest chance to be known
                                max = linkDeg3->follower.suggestionCount; //Increase the highest chance
                                bestFollow = linkDeg3;
                            }
                        }
                        if (linkDeg3 != stud){
                            for (int l = 0; l < linkDeg3->follower.nbrFollower; l++){
                                linkDeg4 = linkDeg3->follower.listFollower[l];
                                /*Browse the follows of the follows of the follows of *stud follows*/
                                if (linkDeg4->follower.known != 1){
                                    //If this student is not already followed
                                    linkDeg4->follower.suggestionCount += 1; //Increase the chances that *stud would know this student
                                    if (linkDeg4->follower.suggestionCount > max){
                                        //If this student has the highest chance to be known
                                        max = linkDeg4->follower.suggestionCount; //Increase the highest chance
                                        bestFollow = linkDeg4;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        bestFollow->follower.known = 1;
        suggestionTab[0] = bestFollow; //Put the best suggestion of follow in the first place of the array

        /*This part searches for the best students to suggest
        and fill the array with them*/
        int t = 1;
        while (max > 0 && t < nbrSuggestion){
            for (int i = 0; i < stud->follower.nbrFollower; i++){
                linkDeg1 = stud->follower.listFollower[i];
                if (t < nbrSuggestion && linkDeg1 != stud){
                    //If the array is not full yet and the student is not *stud
                    for (int j = 0; j < linkDeg1->follower.nbrFollower; j++){
                        linkDeg2 = linkDeg1->follower.listFollower[j];
                        /*Browse the follows of *stud follows*/
                        if (linkDeg2->follower.known != 1){
                            //If the student is not known
                            if (linkDeg2->follower.suggestionCount == max){
                                //If this student has the highest chance to be known
                                suggestionTab[t] = linkDeg2; //Fill the array
                                suggestionTab[t]->follower.known = 1;
                                t++;
                            }
                        }
                    }
                    if (t < nbrSuggestion && linkDeg2 != stud){
                        //If the array is not full yet and the student is not *stud
                        for (int k = 0; k < linkDeg2->follower.nbrFollower; k++){
                            linkDeg3 = linkDeg2->follower.listFollower[k];
                            /*Browse the follows of the follows of *stud follows*/
                            if (linkDeg3->follower.known != 1){
                                //If the student is not known
                                if (linkDeg3->follower.suggestionCount == max){
                                    //If this student has the highest chance to be known
                                    suggestionTab[t] = linkDeg3; //Fill the array
                                    suggestionTab[t]->follower.known = 1;
                                    t++;
                                }
                            }
                            if (t < nbrSuggestion && linkDeg3 != stud){
                                //If the array is not full yet and the student is not *stud
                                for (int l = 0; l < linkDeg3->follower.nbrFollower; l++){
                                    linkDeg4 = linkDeg3->follower.listFollower[l];
                                    /*Browse the follows of the follows of the follows of *stud follows*/
                                    if (linkDeg4->follower.known != 1){
                                        //If student is not known
                                        if (linkDeg4->follower.suggestionCount == max){
                                            //If this student has the highest chance to be known
                                            suggestionTab[t] = linkDeg4; //Fill the array
                                            suggestionTab[t]->follower.known = 1;
                                            t++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            max--; //Decrease the highest chance for someone to be known
        }

        /*This part puts to 0 every suggestionCount and every known fields
        of every manipulated student*/
        stud->follower.known = 0;
        for (int i = 0; i < stud->follower.nbrFollower; i++){
            linkDeg1 = stud->follower.listFollower[i];
            /*Browse *stud follows*/
            linkDeg1->follower.suggestionCount = 0;
            linkDeg1->follower.known = 0;
            for (int j = 0; j < linkDeg1->follower.nbrFollower; j++){
                linkDeg2 = linkDeg1->follower.listFollower[j];
                /*Browse the follows of *stud follows*/
                if (linkDeg2->follower.suggestionCount != 0
                    || linkDeg2->follower.known !=0){
                    linkDeg2->follower.suggestionCount = 0;
                    linkDeg2->follower.known = 0;
                }
                if (linkDeg2 != stud){
                    for (int k = 0; k < linkDeg2->follower.nbrFollower; k++){
                        linkDeg3 = linkDeg2->follower.listFollower[k];
                        /*Browse the follows of the follows of *stud follows*/
                        if (linkDeg3->follower.suggestionCount != 0
                            || linkDeg3->follower.known != 0){
                            linkDeg3->follower.suggestionCount = 0;
                            linkDeg3->follower.known = 0;
                        }
                        if (linkDeg3 != stud){
                            for (int l = 0; l < linkDeg3->follower.nbrFollower; l++){
                                linkDeg4 = linkDeg3->follower.listFollower[l];
                                /*Browse the follows of the follows of the follows of *stud follows*/
                                if (linkDeg4->follower.suggestionCount != 0
                                    || linkDeg4->follower.known != 0){
                                    linkDeg4->follower.suggestionCount = 0;
                                    linkDeg4->follower.known = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        //If *stud does not follow anyone
        int max = 0;
        stud->follower.known = 1;

        /*This part compare the fields of interest of *stud and every student
        of the glossary in order to find a good suggestion*/
        for (int i = 0; i < 27; i++){
            /*Browse the students of the glossary*/
            Student *ptr = glossary[i].beginList;
            while (ptr != NULL){
                int compare = compare_fields_of_interest(stud, ptr); //Compare fields of interest
                if (ptr->follower.known != 1 && compare > max){
                    max = compare; //Increase the highest score
                    ptr->follower.known = 1;
                    if (suggestionTab[0] != NULL){
                        suggestionTab[0]->follower.known = 0;
                    }
                    suggestionTab[0] = ptr; //Put the best suggestion of follow in the first place of the array
                }
                ptr = ptr->nextAlphaStudent;
            }
        }

        /*This part searches for the best students to suggest
        and fill the array with them*/
        int t = 1;
        while (max > 0 && t < nbrSuggestion){
            for (int i = 0; i < 27; i++){
                /*Browse the students of the glossary*/
                Student *ptr = glossary[i].beginList;
                while (t < nbrSuggestion && ptr != NULL){
                    //While the array in not full yet
                    int compare = compare_fields_of_interest(stud, ptr); //Compare fields of interest
                    if (ptr->follower.known != 1 && compare == max){
                        //If the student is not in the array and has the highest score
                        ptr->follower.known = 1;
                        suggestionTab[t] = ptr; //Fill the array
                        t++;
                    }
                    ptr = ptr->nextAlphaStudent;
                }
            }
            max--; //Decrease the highest score
        }

        /*This part puts to 0 every known field of every manipulated student*/
        stud->follower.known = 0;
        for (int i = 0; i < nbrSuggestion; i++){
            if (suggestionTab[i] != NULL){
                suggestionTab[i]->follower.known = 0;
            }
        }
    }
}

/******************************************************************************/

/*The delete_student function takes a pointer as argument
and delete the student pointed to the pointer in the glossary*/
int delete_student(Student *stud)
{

    errase_student(researching_student(stud->name));

    char readChar = stud->name[0];
    int i = 0;
    //Find the right chapter in the glossary
    while (readChar != glossary[i].letter && i < 27){
        i++;
    }
    if (readChar == glossary[i].letter){
        if (glossary[i].beginList == NULL){
            //There is no student in the chapter of the glossary
            return 1;
        } else {
            Student *ptr = glossary[i].beginList;
            if (ptr == stud){
                //The student has been found
                glossary[i].beginList = stud->nextAlphaStudent;
                clear_links(stud); //Remove the student in avery list of follows of every student
                free(stud); //Free the pointer
                return 0;
            } else {
                while (ptr->nextAlphaStudent != stud &&
                       ptr->nextAlphaStudent != NULL &&
                       compare_strings(stud->name, ptr->nextAlphaStudent->name) >= 0){
                    ptr = ptr->nextAlphaStudent;
                }
                if (ptr->nextAlphaStudent == stud){
                    //The student has been found
                    ptr->nextAlphaStudent = stud->nextAlphaStudent;
                    clear_links(stud); //Remove the student in avery list of follows of every student
                    free(stud); //Free the pointer
                    return 0;
                } else if (ptr->nextAlphaStudent == NULL ||
                           compare_strings(stud->name, ptr->nextAlphaStudent->name) < 0){
                    //The student has not been found
                    return 1;
                }
            }
        }
    }
    return 1;
}

/******************************************************************************/

/*The clear_links function takes a pointer to a student as argument
and remove all pointers equal to this one in every list of follows of every student
(this function allows to close the application properly)*/
void clear_links(Student *stud)
{
    for (int i = 0; i < 27; i++){
        Student *ptr = glossary[i].beginList;
        while (ptr != NULL){
            for (int j = 0; j < ptr->follower.nbrFollower; j++){
                if (ptr->follower.listFollower[j] == stud){
                    ptr->follower.listFollower[j] = NULL;
                }
            }
            ptr = ptr->nextAlphaStudent;
        }
    }
    free(stud->follower.listFollower);
}


/*The quit function saves the student-list.txt and follows.txt files
with the current state of variables and for each student, it clears all pointers
and free the pointer to the variables*/
void quit(){
    save_follows();
    for (int i = 0; i < 27; i++){
        while (glossary[i].beginList != NULL){
            Student *ptr = glossary[i].beginList;
            clear_links(ptr);
            glossary[i].beginList = glossary[i].beginList->nextAlphaStudent;
            free(ptr);
        }
    }
}


/*The suggest_follows function takes */
/*
void suggest_follows(Student *stud,Student **suggestionTab, int nbrSuggestion){
    for (int t = 0; t < nbrSuggestion; t++){
        suggestionTab[t] = NULL;
    }
    if (stud->follower.nbrFollower > 0){
        int max = 0;
        Student *bestFollow = NULL;
        stud->follower.known = 1;
        for (int i = 0; i < stud->follower.nbrFollower; i++){
            stud->follower.listFollower[i]->follower.known = 1;
        }
        for (int i = 0; i < stud->follower.nbrFollower; i++){
            for (int j = 0; j < stud->follower.listFollower[i]->follower.nbrFollower; j++){
                if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.known != 1){
                    stud->follower.listFollower[i]->follower.listFollower[j]->follower.suggestionCount += 3;
                    if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.suggestionCount > max){
                        max = stud->follower.listFollower[i]->follower.listFollower[j]->follower.suggestionCount;
                        bestFollow = stud->follower.listFollower[i]->follower.listFollower[j];
                    }
                }
                if (stud->follower.listFollower[i]->follower.listFollower[j] != stud){
                    for (int k = 0; k < stud->follower.listFollower[i]->follower.listFollower[j]->follower.nbrFollower; k++){
                        if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.known != 1){
                            stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.suggestionCount += 2;
                            if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.suggestionCount > max){
                                max = stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.suggestionCount;
                                bestFollow = stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k];
                            }
                        }
                        if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k] != stud){
                            for (int l = 0; l < stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.nbrFollower; l++){
                                if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.known != 1){
                                    stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.suggestionCount += 1;
                                    if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.suggestionCount > max){
                                        max = stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.suggestionCount;
                                        bestFollow = stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        bestFollow->follower.known = 1;
        suggestionTab[0] = bestFollow;
        int t = 1;
        while (max > 0 && t < nbrSuggestion){
            for (int i = 0; i < stud->follower.nbrFollower; i++){
                // if (t < 5){}
                for (int j = 0; j < stud->follower.listFollower[i]->follower.nbrFollower; j++){
                    if (t < 5 && stud->follower.listFollower[i]->follower.listFollower[j]->follower.known != 1){
                        if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.suggestionCount == max){
                            suggestionTab[t] = stud->follower.listFollower[i]->follower.listFollower[j];
                            suggestionTab[t]->follower.known = 1;
                            t++;
                        }
                    }
                    if (t < 5 && stud->follower.listFollower[i]->follower.listFollower[j] != stud){
                        for (int k = 0; k < stud->follower.listFollower[i]->follower.listFollower[j]->follower.nbrFollower; k++){
                            if (t < 5 && stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.known != 1){
                                if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.suggestionCount == max){
                                    suggestionTab[t] = stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k];
                                    suggestionTab[t]->follower.known = 1;
                                    t++;
                                }
                            }
                            if (t < 5 && stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k] != stud){
                                for (int l = 0; l < stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.nbrFollower; l++){
                                    if (t < 5 && stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.known != 1){
                                        if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.suggestionCount == max){
                                            suggestionTab[t] = stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l];
                                            suggestionTab[t]->follower.known = 1;
                                            t++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            max--;
        }
        stud->follower.known = 0;
        for (int i = 0; i < stud->follower.nbrFollower; i++){
            for (int j = 0; j < stud->follower.listFollower[i]->follower.nbrFollower; j++){
                if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.suggestionCount != 0 || stud->follower.listFollower[i]->follower.listFollower[j]->follower.known !=0){
                    stud->follower.listFollower[i]->follower.listFollower[j]->follower.suggestionCount = 0;
                    stud->follower.listFollower[i]->follower.listFollower[j]->follower.known = 0;
                }
                if (stud->follower.listFollower[i]->follower.listFollower[j] != stud){
                    for (int k = 0; k < stud->follower.listFollower[i]->follower.listFollower[j]->follower.nbrFollower; k++){
                        if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.suggestionCount != 0 || stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.known != 0){
                            stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.suggestionCount = 0;
                            stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.known = 0;
                        }
                        if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k] != stud){
                            for (int l = 0; l < stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.nbrFollower; l++){
                                if (stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.suggestionCount != 0 || stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.known != 0){
                                    stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.suggestionCount = 0;
                                    stud->follower.listFollower[i]->follower.listFollower[j]->follower.listFollower[k]->follower.listFollower[l]->follower.known = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        int max = 0;
        stud->follower.known = 1;
        for (int i = 0; i < 27; i++){
            Student *ptr = glossary[i].beginList;
            while (ptr != NULL){
                int compare = compare_fields_of_interest(stud, ptr);
                if (ptr->follower.known != 1 && compare > max){
                    max = compare;
                    ptr->follower.known = 1;
                    if (suggestionTab[i] != NULL){
                        suggestionTab[i]->follower.known = 0;
                    }
                    suggestionTab[0] = ptr;
                }
                ptr = ptr->nextAlphaStudent;
            }
        }
        int t = 1;
        while (max > 0 && t < nbrSuggestion){
            for (int i = 0; i < 27; i++){
                Student *ptr = glossary[i].beginList;
                while (t < 5 && ptr != NULL){
                    int compare = compare_fields_of_interest(stud, ptr);
                    if (ptr->follower.known != 1 && compare == max){
                        ptr->follower.known = 1;
                        suggestionTab[t] = ptr;
                        t++;
                    }
                    ptr = ptr->nextAlphaStudent;
                }
            }
            max--;
        }
        stud->follower.known = 0;
        for (int i = 0; i < nbrSuggestion; i++){
            if (suggestionTab[i] != NULL){
                suggestionTab[i]->follower.known = 0;
            }
        }
    }
}
*/

