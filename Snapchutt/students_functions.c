#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
STUDENTS_FONC.h contain all the fonction relative to the gestion of a student.
*******************************************************************************/


Student *create_student(){
    /*This fonction is used to create a Student variable and return is pointer*/
    Student *stud;
    stud = malloc(sizeof(Student));
    char str1[sizeName], str2[sizeFieldStudi], str3[sizeStudentCity];
    int ind1, ind2, ind3, ind4, ind5;

    fflush(stdin);  //Security
    /* Enter all information of the new student */
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

    /* Create this new student */
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

    /* Copy of the new student in the returned adress */
    *stud = stur;
    ecrire_student(stud);
    return(stud);
}


int add_student(Student *stud){
    // Finding the right chapter in the glossary
    char readChar = stud->name[0];
    int i = 0;
    while (readChar != glossary[i].letter && i < 27){
        i++;
    }
    if (readChar == glossary[i].letter){
        // If the chapter of glossary does not contain any element
        if (glossary[i].beginList == NULL){
            stud->nextAlphaStudent = NULL;
            glossary[i].beginList = stud;
            return 0;
        } else {
            Student *ptr = glossary[i].beginList;
            int compare = compare_strings(stud->name, ptr->name);
            // If the chapter contains 1 element that comes after stud
            if (compare == -1 || compare == 0){
                stud->nextAlphaStudent = glossary[i].beginList;
                glossary[i].beginList = stud;
                // necessary step because glossary[i].beginList is not a Student
                // element
                return 0;
            } else {
                while (ptr->nextAlphaStudent != NULL){
                    Student nextElement = *(ptr->nextAlphaStudent);
                    int compare = compare_strings(stud->name, nextElement.name);
                    // If stud comes before nextElement
                    if (compare == -1 || compare == 0){
                        stud->nextAlphaStudent = ptr->nextAlphaStudent;
                        ptr->nextAlphaStudent = stud;
                        return 0;
                    } else {
                        // If stud comes after nextElement
                        ptr = ptr->nextAlphaStudent;
                    }
                }
                // If stud is the last element of the chapter
                if (ptr->nextAlphaStudent == NULL){
                    stud->nextAlphaStudent = NULL;
                    ptr->nextAlphaStudent = stud;
                    return 0;
                }
            }
        }
    } else {
        // The chapter for stud has not been found
        return 1;
    }
}

/******************************************************************************/


Student *find_student(char *name){
    Student *foundStudent;
    int i = 0;
    while (glossary[i].letter != name[0] && i < 27){
        i++;
    }
    if (glossary[i].letter == name[0]){
        if (glossary[i].beginList == NULL){
            return (NULL);
        } else {
            int compare = compare_strings(glossary[i].beginList->name, name);
            if (compare == 0){
                foundStudent = glossary[i].beginList;
                return (foundStudent);
            } else if (compare == -1){
                return (NULL);
            } else {
                Student *ptr = glossary[i].beginList->nextAlphaStudent;
                while (ptr != NULL){
                    compare = compare_strings(ptr->name, name);
                    if (compare == 0){
                        foundStudent = ptr;
                        return (foundStudent);
                    } else if (compare == -1){
                        return (NULL);
                    } else {
                        ptr = ptr->nextAlphaStudent;
                    }
                }
                if (ptr == NULL){
                    return (NULL);
                }
            }
        }
    }
    printf("Invalid syntax\n");
    return (NULL);
}

/******************************************************************************/


void add_follow(Student *stud, Student *follow){
    if (follow != stud){
            if (stud->follower.maxElement == 0){
            stud->follower.listFollower = (
                Student **)malloc(10 * sizeof(Student *));
            stud->follower.maxElement = 10;
            stud->follower.listFollower[stud->follower.nbrFollower] = follow;
            stud->follower.nbrFollower++;
        } else if (stud->follower.nbrFollower < stud->follower.maxElement){
            stud->follower.listFollower[stud->follower.nbrFollower] = follow;
            stud->follower.nbrFollower++;
        } else {
            stud->follower.listFollower = (
                Student **)realloc(
                    stud->follower.listFollower, 5 * sizeof(Student *));
            stud->follower.maxElement += 5;
            stud->follower.listFollower[stud->follower.nbrFollower] = follow;
            stud->follower.nbrFollower++;
        }
    } else {
        //printf("you cannot follow yourself");
    }
}


void suggest_follows(Student *stud,Student **suggestionTab, int nbrSuggestion){
    for (int t = 0; t < nbrSuggestion; t++){
        suggestionTab[t] = NULL;
    }
    if (stud->follower.nbrFollower != 0){
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

/******************************************************************************/


int delete_student(Student *stud){
    // Finding the right chapter in the glossary
    char readChar = stud->name[0];

    errase_student(researching_student(stud->name));

    int i = 0;
    while (readChar != glossary[i].letter && i < 27){
        i++;
    }
    if (readChar == glossary[i].letter){
        if (glossary[i].beginList == NULL){
            return 1;
        } else {
            Student *ptr = glossary[i].beginList;
            if (ptr == stud){
                glossary[i].beginList = stud->nextAlphaStudent;
                clear_links(stud);
                free(stud);
                return 0;
            } else {
                while (ptr->nextAlphaStudent != stud
                    && ptr->nextAlphaStudent != NULL && compare_strings(
                        stud->name, ptr->nextAlphaStudent->name) >= 0)
                {
                    ptr = ptr->nextAlphaStudent;
                }
                if (ptr->nextAlphaStudent == stud){
                    ptr->nextAlphaStudent = stud->nextAlphaStudent;
                    clear_links(stud);
                    free(stud);
                    return 0;
                } else if (ptr->nextAlphaStudent == NULL
                      || compare_strings(
                          stud->name, ptr->nextAlphaStudent->name) < 0)
                {
                    return 1;
                }
            }
        }
    }
    return 1;
}


void clear_links(Student *stud){
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


void quit(){
    for (int i = 0; i < 27; i++){
        while (glossary[i].beginList != NULL){
            Student *ptr = glossary[i].beginList;
            clear_links(ptr);
            glossary[i].beginList = glossary[i].beginList->nextAlphaStudent;
            free(ptr);
        }
    }
}
