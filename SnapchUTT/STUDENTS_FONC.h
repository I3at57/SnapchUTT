/*******************************************************************************
STUDENTS_FONC.h contain all the fonction relative to the gestion of a student.
*******************************************************************************/

#ifndef STUDENTS_FONC_H_INCLUDED
#define STUDENTS_FONC_H_INCLUDED

#include "CONST.h"
#include "STUDENTS_LIST.h"

int compare_strings(char *str1, char *str2){
    /**/
    int k = 1;
    while (str1[k] == str2[k] && str1[k] != '\0' && str2[k] != '\0'){
        k++;
    }
    if (str1[k] < str2[k] || (str1[k] == '\0' && str2[k] != '\0')){
        return -1; // str1 comes before str2
    } else if (str1[k] > str2[k] || (str1[k] != '\0' && str2[k] == '\0')){
        return 1; // str1 comes after str2
    } else {
        return 0; // str1 is equal to str2
    }
}

int add_student(Student *stud){
    printf("001\n");
    // Finding the right chapter in the glossary
    char readChar = stud->name[0];
    printf("readChar = %c\n", readChar);
    int i = 0;
    while (readChar != glossary[i].letter && i < 27){
        i++;
    }
    printf("%d", i);
    if (readChar == glossary[i].letter){
        // If the chapter of glossary does not contain any element
        if (glossary[i].beginList == NULL){
            stud->nextAlphaStudent = NULL;
            glossary[i].beginList = stud;
            printf("ok1\n");
            return 0;
        } else {
            Student *ptr = glossary[i].beginList;
            int compare = compare_strings(stud->name, ptr->name);
            // If the chapter contains 1 element that comes after stud
            if (compare == -1 || compare == 0){
                printf("ok2\n");
                stud->nextAlphaStudent = glossary[i].beginList;
                glossary[i].beginList = stud; // necessary step because glossary[i].beginList is not a Student element
                return 0;
            } else {
                while (ptr->nextAlphaStudent != NULL){
                    Student nextElement = *(ptr->nextAlphaStudent);
                    int compare = compare_strings(stud->name, nextElement.name);
                    // If stud comes before nextElement
                    if (compare == -1 || compare == 0){
                        printf("ok3\n");
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
                    printf("ok4\n");
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

int init_glossary(Student *tab[],int nbrStudent){ // Those parameters could be removed by using global variables
    for (int i = 0; i < nbrStudent; i++){
        printf("01\n");
        add_student(tab[i]);
    }
    return 0;
}

int find_student(char *name){
    int i = 0;
    while (glossary[i].letter != name[0] && i < 27){
        i++;
    }
    if (glossary[i].letter == name[0]){
        if (glossary[i].beginList == NULL){
            printf("This student does not exist\n");
            // Return not found
        } else {
            int compare = compare_strings(glossary[i].beginList->name, name);
            if (compare == 0){
                // Display informations
                // Return informations
            } else if (compare == -1){
                printf("This student does not exist\n");
                // Return not found
            } else {
                Student *ptr = glossary[i].beginList->nextAlphaStudent;
                while (ptr != NULL){
                    compare = compare_strings(ptr->name, name);
                    if (compare == 0){
                        // Display informations
                        // Return informations
                    } else if (compare == -1){
                        printf("This student does not exist\n");
                        // Return not found
                    } else {
                        ptr = ptr->nextAlphaStudent;
                    }
                }
                if (ptr == NULL){
                    printf("This student does not exist\n");
                    // Return not found
                }
            }
        }
    } else {
        printf("Invalid syntax\n")
    }
}

#endif // STUDENTS_FONC_H_INCLUDED
