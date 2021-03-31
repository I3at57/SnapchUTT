#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

void array_char_display(char tab[]){
    /*This fonction is used to display an entire array of character at screen.
    This fonction dont include '\n' so we must use some print in complement*/
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

void menu_display(){
    /*This fonction display the main menu of Snapch'UTT. */
    printf("***************************************************************\n");
    printf("***************************************************************\n");
    printf("**                                                           **\n");
    printf("**            ----- Welcome in Snapch'UTT ! -----            **\n");
    printf("**                                                           **\n");
    printf("**                                                           **\n");
    printf("**   There is several things to do here :                    **\n");
    printf("**                                                           **\n");
    printf("**   1. Add a student in the database                        **\n");
    printf("**   2. Find a specific student                              **\n");
    printf("**   3. Do a research by cathegorize                         **\n");
    printf("**   4. Display student by name                              **\n");
    printf("**   5. Quit                                                 **\n");
    printf("**                                                           **\n");
    printf("***************************************************************\n");
    printf("***************************************************************\n");
}

void find_menu_display(){
    printf("***************************************************************\n");
    printf("***************************************************************\n");
    printf("**                                                           **\n");
    printf("**            ----- What do you want to do ? -----           **\n");
    printf("**                                                           **\n");
    printf("**                                                           **\n");
    printf("**   There is several things to with this Student :          **\n");
    printf("**                                                           **\n");
    printf("**   1. Modify                                               **\n");
    printf("**   2. Delete                                               **\n");
    printf("**   3. Add a Follow                                         **\n");
    printf("**   4. Propose Student to Follows                           **\n");
    printf("**   5. Display the list of follow                           **\n");
    printf("**   6. Quit                                                 **\n");
    printf("**                                                           **\n");
    printf("***************************************************************\n");
    printf("***************************************************************\n");
}

void student_display(Student *stu){
    /*This fonction display all information about a student, exept the follow
    List.*/
    if (stu != NULL){
        printf("**   ");
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
        printf(", ");
    }
    else {
        printf("\nNo informations about this person. \n");
    }
}

void list_of_students_display(Student *stud){
    for (int i = 0; i < stud->follower.nbrFollower; i++){
        array_char_display(stud->follower.listFollower[i]->name);
        printf("\n\n");
    }
}