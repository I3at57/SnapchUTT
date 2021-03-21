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
    Student *travelPtr;
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
            travelPtr = glossary[i].beginList;
            int compare = compare_strings(stud->name, travelPtr->name);
            // If the chapter contains 1 element that comes after stud
            if (compare == -1 || compare == 0){
                printf("ok2\n");
                stud->nextAlphaStudent = glossary[i].beginList;
                glossary[i].beginList = stud;
                // necessary step because glossary[i].beginList is not a Student
                // element
                return 0;
            } else {
                while (travelPtr->nextAlphaStudent != NULL){
                    Student nextElement = *(travelPtr->nextAlphaStudent);
                    int compare = compare_strings(stud->name, nextElement.name);
                    // If stud comes before nextElement
                    if (compare == -1 || compare == 0){
                        printf("ok3\n");
                        stud->nextAlphaStudent = travelPtr->nextAlphaStudent;
                        travelPtr->nextAlphaStudent = stud;
                        return 0;
                    } else {
                        // If stud comes after nextElement
                        travelPtr = travelPtr->nextAlphaStudent;
                    }
                }
                // If stud is the last element of the chapter
                if (travelPtr->nextAlphaStudent == NULL) {
                    printf("ok4\n");
                    stud->nextAlphaStudent = NULL;
                    travelPtr->nextAlphaStudent = stud;
                    return 0;
                }
            }
        }
    } else {
        // The chapter for stud has not been found
        return 1;
    }
}

int init_glossary(Student *tab[],int nbrStudent){
    // Those parameters could be removed by using global variables
    for (int i = 0; i < nbrStudent; i++){
        printf("01\n");
        add_student(tab[i]);
    }
    return 0;
}

#endif // STUDENTS_FONC_H_INCLUDED
