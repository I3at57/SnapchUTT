#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
All the functions related to the display. If a feature has to display something
the related function is here.
*******************************************************************************/


/*The array_char_display function is used to display an entire array of characters on the screen.
This function does not include '\n' so we must use some prints in complement*/
void array_char_display(char tab[])
{
    if(tab[0] != '\0'){
        int i=0;
        char nextChar = tab[i];
        do{
            printf("%c", nextChar);
            i++;
            nextChar = tab[i];
        }while(nextChar != '\0');
    }
}

/******************************************************************************/

/*The display_interest displays all fields of interest of a specific student*/
void display_interest()
{
    int i;
    for (i=0; i<nbrInterest; i++){
        printf("%d- %s\n", i+1, tabOfInterest[i].field);
    }
}

/******************************************************************************/

void menu_display()
{
    printf("***************************************************************\n");
    printf("***************************************************************\n");
    printf("**                                                           **\n");
    printf("**            ----- Welcome to Snapch'UTT ! -----            **\n");
    printf("**                                                           **\n");
    printf("**                                                           **\n");
    printf("**   There is several things to do here :                    **\n");
    printf("**                                                           **\n");
    printf("**   1. Add a student in the database                        **\n");
    printf("**   2. Find a specific student                              **\n");
    printf("**   3. Do a research by category                            **\n");
    printf("**   4. Display all students by name                         **\n");
    printf("**   5. Quit                                                 **\n");
    printf("**                                                           **\n");
    printf("***************************************************************\n");
    printf("***************************************************************\n");
}

void find_menu_display()
{
    printf("***************************************************************\n");
    printf("***************************************************************\n");
    printf("**                                                           **\n");
    printf("**            ----- What do you want to Do ? -----           **\n");
    printf("**                                                           **\n");
    printf("**                                                           **\n");
    printf("**   There is several things to do with this Student :       **\n");
    printf("**                                                           **\n");
    printf("**   1. Modify                                               **\n");
    printf("**   2. Delete                                               **\n");
    printf("**   3. Add a Follow                                         **\n");
    printf("**   4. Delete a follow                                      **\n");
    printf("**   5. Suggest some Students to follow                      **\n");
    printf("**   6. Display the list of follows                          **\n");
    printf("**   7. Quit                                                 **\n");
    printf("**                                                           **\n");
    printf("***************************************************************\n");
    printf("***************************************************************\n");
}

void display_perway_menu_display()
{
    printf("***************************************************************\n");
    printf("***************************************************************\n");
    printf("**                                                           **\n");
    printf("**         ----- What do you want to Research ? -----        **\n");
    printf("**                                                           **\n");
    printf("**                                                           **\n");
    printf("**   1. Age                                                  **\n");
    printf("**   2. Year of studies                                      **\n");
    printf("**   3. City of residence                                    **\n");
    printf("**   4. Field of studies                                     **\n");
    printf("**   5. Field of interest                                    **\n");
    printf("**   6. Quit                                                 **\n");
    printf("**                                                           **\n");
    printf("***************************************************************\n");
    printf("***************************************************************\n");
}

void modify_menu_display()
{
    printf("***************************************************************\n");
    printf("***************************************************************\n");
    printf("**                                                           **\n");
    printf("**          ----- What do you want to Change ? -----         **\n");
    printf("**                                                           **\n");
    printf("**                                                           **\n");
    printf("**   1. Age                                                  **\n");
    printf("**   2. Year of studies                                      **\n");
    printf("**   3. Field of studies                                     **\n");
    printf("**   4. City of residence                                     **\n");
    printf("**   5. Field of interest                                    **\n");
    printf("**   6. Quit                                                 **\n");
    printf("**                                                           **\n");
    printf("***************************************************************\n");
    printf("***************************************************************\n");
}

/******************************************************************************/

/*The student_display function displays all the informations about a student*/
void student_display(Student *stu)
{

    if (stu != NULL){
        printf("**   ");  // two '*' for better display
        array_char_display(stu->name);
        printf("\n");
        printf("**   Age : %d\n", stu->age);
        printf("**   Year of study : %d\n", stu->yearStudy);
        printf("**   ");
        array_char_display(stu->fieldStudy);
        printf("\n");
        printf("**   ");
        array_char_display(stu->cityResidence);
        printf("\n");
        printf("**   Interst in : ");
        array_char_display(stu->interest[0].field);
        printf(", ");
        array_char_display(stu->interest[1].field);
        printf(", ");
        array_char_display(stu->interest[2].field);
    }
    else {
        printf("\nNo informations about this person. \n");
    }
}

/******************************************************************************/

/*The display_follow_list displays all students that a student follows*/
void display_follow_list(Student *stud)
{
    for (int i = 0; i < stud->follower.nbrFollower; i++){
        student_display(stud->follower.listFollower[i]);
        printf("\n\n");
    }
}
