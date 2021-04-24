#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
All the functions to display students by a specific criteria from the glossary.
*******************************************************************************/


/*The display_all_alpha function displays all students in the glossary by name*/
int display_all_alpha()
{
    int ind;
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //For each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList; //The first element of the list
            do {
                student_display(voy);
                printf("\n\n");
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*When the last student of this list is displayed then left the loop
            and goes on the following letter*/
        }
    }
    return(0);
}

/******************************************************************************/

/*The display_all_age function displays all students in the glossary
who have the same age 'dage'*/
int display_all_age(int dage)
{
    int ind, presence = 1; //At the beginning no student are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //For each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //The first element of the list
            do {
                if (voy->age == dage) {
                //Then this student must be displayed
                    student_display(voy);
                    presence = 0; //Minimum one element has been displayed
                    printf("\n\n");
                }
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*When the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}

/******************************************************************************/

/*The display_all_year function displays all students in the glossary
who have the same year of study 'dyear'*/
int display_all_year(int dyear)
{
    int ind, presence = 1;  //At the beginning no student are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //For each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //The first element of the list
            do {
                if (voy->yearStudy == dyear) {
                //Then this student must be displayed
                    student_display(voy);
                    presence = 0; //Minimum one element has been displayed
                    printf("\n\n");
                }
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*When the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}

/******************************************************************************/

/*The display_all_city function displays all students in the glossary
who have the same city 'dcity'*/
int display_all_city(char *dcity) {

    int ind, presence = 1;  //At the beginning no student are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //For each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //The first element of the list
            do {
                if (compare_strings_simple(voy->cityResidence, dcity) == 0) {
                    //Then this student must be displayed
                    student_display(voy);
                    presence = 0; //Minimum one element has been displayed
                    printf("\n\n");
                }
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*When the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}

/******************************************************************************/

/*The display_all_field function displays all students in the glossary
who have the same field of studies 'dfield'*/
int display_all_field(char *dfield)
{
    int ind, presence = 1;  //At the beginning no student are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //For each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //the first element of the list
            do {
                if (compare_strings_simple(voy->fieldStudy, dfield) == 0) {
                //Then this student must be displayed
                    student_display(voy);
                    presence = 0; //Minimum one element has been displayed
                    printf("\n\n");
                }
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*When the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}

/******************************************************************************/

/*The display_all_inter function displays all students in the glossary
who have the same interest 'dinter'*/
int display_all_inter(int dinter)
{
    int ind, ix, presence = 1;  //At the beginning no students are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //For each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //The first element of the list
            do {
                ix = -1;
                do {
                    ix +=1;
                    if (voy->interest[ix].nbr == dinter) {
                    //Test the ix'th element of interest for this student
                        student_display(voy);
                        presence = 0; //Minimum one element has been displayed
                        printf("\n\n");
                    }
                } while (voy->interest[ix].nbr != dinter && ix<2);
                /*If the researched FieldOfInterest is found does not test the
                other. This loop is left if the third element has been tested or
                we found the researched element*/
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*When the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}
