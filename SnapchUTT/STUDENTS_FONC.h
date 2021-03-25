/*******************************************************************************
STUDENTS_FONC.h contain all the fonction relative to the gestion of a student.
*******************************************************************************/

#ifndef STUDENTS_FONC_H_INCLUDED
#define STUDENTS_FONC_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#include "CONST.h"
#include "STUDENTS_LIST.h"

Student *create_student(){
    /*This fonction is used to create a Student variable and return is pointer*/

    char str1[50], str2[50], str3[100];
    int ind1, ind2, ind3, ind4, ind5;

    fflush(stdin);
    printf("\nName : ");
    scanf("%[^\n%]*c", str1);
    printf("\nAge : ");
    scanf("%d", &ind1);
    printf("\nYear of study : ");
    scanf("%d", &ind2);
    fflush(stdin);
    printf("\nField of study : ");
    scanf("%[^\n%]*c", str2);
    fflush(stdin);
    printf("\nCity of residence : ");
    scanf("%[^\n%]*c", str3);
    printf(
        "\nChoose one field of interest :\n\t1. Sport\n\t2. Cinema"
        "\n\t3. Art\n\t4. Health\n\t5. Technology\n\t6. DIY"
        "\n\t7. Cooking\n\t8. Travel\n\n"
    );
    fflush(stdin);
    printf("- ");
    scanf("%d", &ind3);
    printf("- ");
    scanf("%d", &ind4);
    printf("- ");
    scanf("%d", &ind5);

    printf("%s\n", str1);
    printf("%d\n", ind1);
    printf("%d\n", ind2);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%s %s %s", tabOfInterest[ind3-1].field, tabOfInterest[ind4-1].field, tabOfInterest[ind5-1].field);

    Student stur {
        str1,
        ind1,
        ind2,
        str2,
        str3,
        {tabOfInterest[ind3-1], tabOfInterest[ind4-1], tabOfInterest[ind5-1]}
    };

    return(&stur);
}

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
