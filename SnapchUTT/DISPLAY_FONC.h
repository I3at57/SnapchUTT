#ifndef DISPLAY_FONC_H_INCLUDED
#define DISPLAY_FONC_H_INCLUDED

#include <stdio.h>


void menu_display(){
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
    printf("**   5. Quit                                                 **\n");
    printf("**                                                           **\n");
    printf("***************************************************************\n");
    printf("***************************************************************\n");
}

void student_display(Student *stu){
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
//        array_char_display(stu->interest[0].field);
//        printf(", ");
//        array_char_display(stu->interest[1].field);
//        printf(", ");
//        array_char_display(stu->interest[2].field);
//        printf(", ");
    }
}

#endif // DISPLAY_FONC_H_INCLUDED]
