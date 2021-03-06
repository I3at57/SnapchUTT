#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
All useful functions we use that are not related to structures.
*******************************************************************************/


/*The compare_strings returns -1 if str1<str2 ; Returns 1 if str1>str2 ; Returns 0 if str1=str2*/
int compare_strings(char *str1, char *str2)
{
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

/*The compare_strings_simple returns 0 if str1 = str2 else returns 1*/
int compare_strings_simple(char str1[], char str2[])
{
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

/*The copy_array_char function copies the content of contentArray in targetArray*/
int copy_array_char(char *targetArray, char *contentArray, int lth1, int lth2)
{
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

/*The compare_fields_of_interest returns the number of interests in common between two students*/
int compare_fields_of_interest(Student * stud1, Student *stud2)
{
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
