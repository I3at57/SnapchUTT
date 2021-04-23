#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
All the functions to display students by a specific criteria from the glossary.
*******************************************************************************/

int display_all_alpha() {
    /*Displays all students in the glossary by name*/
    int ind;
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //For each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //the 1st element of the list
            do {
                student_display(voy);
                printf("\n\n");
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*when the last student of this list is displayed then left the loop
            and goes on the following letter*/
        }
    }
    return(0);
}

/******************************************************************************/

int display_all_age(int dage) {
    /*Displays all students in the glossary who have the same age 'dage'*/
    int ind, presence = 1; //at the begining no student are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //For each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //the 1st element of the list
            do {
                if (voy->age == dage) {
                //Then this student must be displayed
                    student_display(voy);
                    presence = 0; //minimum 1 element has been displayed
                    printf("\n\n");
                }
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*when the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}

/******************************************************************************/

int display_all_year(int dyear) {
    /*Displays all students in the glossary who have the same
    year of study 'dyear'*/
    int ind, presence = 1;  //at the begining no student are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //for each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //the 1st element of the list
            do {
                if (voy->yearStudy == dyear) {
                //Then this student must be displayed
                    student_display(voy);
                    presence = 0; //minimum 1 element has been displayed
                    printf("\n\n");
                }
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*when the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}

/******************************************************************************/

int display_all_city(char *dcity) {
    /*Displays all students in the glossary whose have the same city 'dcity'*/
    int ind, presence = 1;  //at the begining no student are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //for each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //the 1st element of the list
            do {
                if (compare_strings_simple(voy->cityResidence, dcity) == 0) {
                    //Then this student must be displayed
                    student_display(voy);
                    presence = 0; //minimum 1 element has been displayed
                    printf("\n\n");
                }
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*when the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}

/******************************************************************************/

int display_all_field(char *dfield) {
    /*Display all students in the glossary who have the same
    field of studies 'dfield'*/
    int ind, presence = 1;  //at the begining no student are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //for each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //the 1st element of the list
            do {
                if (compare_strings_simple(voy->fieldStudy, dfield) == 0) {
                //Then this student must be displayed
                    student_display(voy);
                    presence = 0; //minimum 1 element has been displayed
                    printf("\n\n");
                }
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*when the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}

/******************************************************************************/

int display_all_inter(int dinter) {
    /*Displays all students in the glossary who
    have the same interest 'dinter'*/
    int ind, ix, presence = 1;  //at the begining no students are displayed
    Student *voy = NULL;

    for(ind=0; ind<26; ind++) {
    //for each letter of the glossary
        if (glossary[ind].beginList != NULL) {
        //If this letter is not empty
            voy = glossary[ind].beginList;  //the 1st element of the list
            do {
                ix = -1;
                do {
                    ix +=1;
                    if (voy->interest[ix].nbr == dinter) {
                    //test the ix'th element of interest for this student
                        student_display(voy);
                        presence = 0; //minimum 1 element has been displayed
                        printf("\n\n");
                    }
                } while (voy->interest[ix].nbr != dinter && ix<2);
                /*If the researching FieldOfInterest is found does't test the
                other. This loop is left if the third element has been tested or
                we found the researching element*/
                voy = voy->nextAlphaStudent;
            } while(voy != NULL);
            /*when the last student of this list is tested then left the loop
            and goes on the following letter*/
        }
    }
    return(presence);
}
