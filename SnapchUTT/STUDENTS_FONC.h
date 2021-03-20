#ifndef STUDENTS_FONC_H_INCLUDED
#define STUDENTS_FONC_H_INCLUDED

#include "CONST.h"
#include "STUDENTS_LIST.h"

int compare_strings(char *str1, char *str2){
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
    // Finding the right chapter in the Glossary
    char readChar = stud->name[0];
    printf("readChar = %c", readChar);
    int i = 0;
    while (readChar != Glossary[i].letter && i < 27){
        i++;
    }
    printf("%d", i);
    if (readChar == Glossary[i].letter){
        // If the chapter of Glossary does not contain any element
        if (Glossary[i].beginList == NULL){
            stud->nextAlphaStudent = NULL;
            Glossary[i].beginList = stud;
            return 0;
        } else {
            travelPtr = Glossary[i].beginList;
            int compare = compare_strings(stud->name, travelPtr->name);
            // If the chapter contains 1 element that comes after stud
            if (compare == -1 && compare == 0){
                stud->nextAlphaStudent = Glossary[i].beginList;
                Glossary[i].beginList = stud; // necessary step because Glossary[i].beginList is not a Student element
                return 0;
            } else {
                while (travelPtr->nextAlphaStudent != NULL){
                    Student nextElement = *(travelPtr->nextAlphaStudent);
                    int compare = compare_strings(stud->name, nextElement.name);
                    // If stud comes before nextElement
                    if (compare == -1 && compare == 0){
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

int init_glossary(Student* tab[],int nbrStudent){ // Those parameters could be removed by using global variables
    for (int i = 0; i < nbrStudent; i++){
        printf("01\n");
        add_student(tab[i]);
    }
    return 0;
}

#endif // STUDENTS_FONC_H_INCLUDED
