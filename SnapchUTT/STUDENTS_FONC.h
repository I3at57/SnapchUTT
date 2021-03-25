/*******************************************************************************
STUDENTS_FONC.h contain all the fonction relative to the gestion of a student.
*******************************************************************************/

#ifndef STUDENTS_FONC_H_INCLUDED
#define STUDENTS_FONC_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#include "UTILITARY_FONC.h"
#include "CONST.h"
#include "STUDENTS_LIST.h"
#include "DISPLAY_FONC.h"

Student *create_student(){
    /*This fonction is used to create a Student variable and return is pointer*/

    Student *stud;
    stud = malloc(sizeof(Student));

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

    Student stur={
        .age = ind1,
        .yearStudy = ind2,
        .interest = {
          tabOfInterest[ind3-1], tabOfInterest[ind4-1], tabOfInterest[ind5-1]
        },
    };
    copy_array_char(&stur.name, &str1, 50, 50);
    copy_array_char(&stur.fieldStudy, &str2, 50, 50);
    copy_array_char(&stur.cityResidence, &str3, 50, 50);

    *stud = stur;

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

int init_glossary(Student *tab[],int nbrStudent){
    // Those parameters could be removed by using global variables
    for (int i = 0; i < nbrStudent; i++){
        add_student(tab[i]);
    }
    return 0;
}

int find_student(Student *foundStudent,char *name){
    int i = 0;
    while (glossary[i].letter != name[0] && i < 27){
        i++;
    }
    if (glossary[i].letter == name[0]){
        if (glossary[i].beginList == NULL){
            return 1;
        } else {
            int compare = compare_strings(glossary[i].beginList->name, name);
            if (compare == 0){
                foundStudent = glossary[i].beginList;
                return 0;
            } else if (compare == -1){
                return 1;
            } else {
                Student *ptr = glossary[i].beginList->nextAlphaStudent;
                while (ptr != NULL){
                    compare = compare_strings(ptr->name, name);
                    if (compare == 0){
                        foundStudent = ptr;
                        return 0;
                    } else if (compare == -1){
                        return 1;
                    } else {
                        ptr = ptr->nextAlphaStudent;
                    }
                }
                if (ptr == NULL){
                    return 1;
                }
            }
        }
    } else {
        printf("Invalid syntax\n");
        return 1;
    }
}

#endif // STUDENTS_FONC_H_INCLUDED
