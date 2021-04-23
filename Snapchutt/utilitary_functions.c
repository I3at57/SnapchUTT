#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
All useful fonctions wee use that ar not relative to structure
*******************************************************************************/

int compare_strings(char *str1, char *str2)
{/*Returns -1 if str1<str2 ; Returns 1 if str1>str2 ; Returns 0 if str1=str2*/

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

/******************************************************************************/

int compare_strings_simple(char str1[], char str2[])
{/*Returns 0 if str1 = str2 otherwise returns 1*/

    int k = 1;
    while (str1[k] == str2[k] && str1[k] != '\0' && str2[k] != '\0'){
        k++;
    }
    if (str1[k] == str2[k]) {
        return(0); //equal
    } else {
        return(1); //non equal
    }
}

/******************************************************************************/

int copy_array_char(char *targetArray, char *contentArray, int lth1, int lth2)
{/*Copies the content of 'contentArray' in 'targetArray'*/

    if (lth2 > lth1){
        return 1;
    }
    int i = 0;
    char lastChar;
    do {
        lastChar = contentArray[i];
        targetArray[i] = lastChar;
        i++;
    } while (lastChar != '\0');
    return 0;
}

/******************************************************************************/

int compare_fields_of_interest(Student * stud1, Student *stud2)
{/*Returns the number of interests in common between two students*/

    int sameInterest = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (stud1->interest[i].nbr == stud2->interest[j].nbr){
                sameInterest++;
            }
        }
    }
    return sameInterest;
}

/******************************************************************************/

void fget_line(FILE* fptr, char* str){
    char lastCharacter;
    int i = 0;
    while ((lastCharacter = fgetc(fptr)) != '\n'){
        str[i] = lastCharacter;
        i++;
    }
}
