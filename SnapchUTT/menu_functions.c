#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
MENU.h contain all the menu fonction which call other functions
*******************************************************************************/

int main_menu() {
    /*main_menu() is the main menu loop, it allow to navigate into other
    sub-menu*/
    int action;
    char valid;
    do {
        printf("%s", menuSep);   //Only display cf DISPLAY_FONC
        menu_display();   //Only display cf DISPLAY_FONC
        printf("\nEnter your choise : ");
        scanf("%d", &action);
        switch(action){
            case 1:
                /*sub-menu to add a student into glossary */
                add_menu();
                break;
            case 2:
                /*sub-menu find student, only on name based research*/
                find_one_menu();
                break;
            case 3:
                /*sub menu to make a research by other field (age, field...)*/
                find_all_menu();
                break;
            case 4:
                /*sub-menu to display all by name*/
                printf("%s", actionSep);
                display_all_alpha();

                fflush(stdin);
                scanf("%c", &valid); //enter a letter to continue
                break;
            case 5:
                /* quit() is the only way to quit the application */
                //quit();
                return(0);
                break;
            case 6:
                /* A test zone only for developer*/
                testzone();
                break;
            default:
                printf(
                    "%sPlease enter a valid propostion !\n",
                    actionSep
                );
                break;
         }
    }while(action !=5);
}

/******************************************************************************/

int add_menu() {
    add_student(create_student());
    return(0);
}

/******************************************************************************/

int find_one_menu() {

    Student *eleve, *eleve2;
    char nameStr[sizeName];
    int action;

    do {
        /* A loop to research for a specific student by name*/
        fflush(stdin);
        printf("\nEnter a name : ");
        scanf("%[^\n%]*c", nameStr);
        eleve = find_student(nameStr);    // give the pointer of a student
        if (eleve == NULL) {
            printf("\nThis student doesn't exist :/\n");
            printf("Enter 'Quit' to quit.\n");
        } else {
            printf("\n");
        }
    }while(eleve == NULL && compare_strings_simple(nameStr, quitString));
    /* If nameStr is 'Quit' the loop end and eleve = NULL
    else eleve point on a student in glossary. */

    if (compare_strings_simple(nameStr, quitString) == 0) {
        return(1);
    } else {
        do {
            printf("%s", menuSep);   //Only display cf DISPLAY_FONC
            student_display(eleve);
            printf("\n\n");
            find_menu_display();   //Only display cf DISPLAY_FONC
            printf("\nEnter your choise : ");
            scanf("%d", &action),
            printf("\n");
            switch(action){
                case 1:
                    /*Sub-menu to modify a student*/
                    modify_menu(eleve);
                    break;
                case 2:
                    printf("\n%s got removed\n", eleve->name);
                    delete_student(eleve);
                    return 0;
                    /*Delete the current student*/
                    break;
                case 3:
                    /*A fontion to add a follow in a followinglist
                    of a student*/
                    fflush(stdin);
                    printf("\nWho %s want to follow ? : ", eleve->name);
                    scanf("%[^\n%]*c", nameStr);
                    printf("\n");
                    eleve2 = find_student(nameStr);
                    if (eleve2 == NULL){
                        printf("\nThis student doesn't exist :/\n");
                    } else {
                        add_follow(eleve, eleve2);
                    }
                    break;
                case 4:
                    /**/
                    break;
                case 5:
                    /*Display all student that the current student
                    'eleve' follow*/
                    display_follow_list(eleve);
                    break;
                case 6:
                    /* quit() is the only way to quit the application */
                    return(0);
                    break;
                case 7:
                    /* A test zone only for developer*/
                    //testzone();
                    break;
                default:
                    printf(
                        "%sPlease enter a valid propostion !\n",
                        actionSep
                    );
                    break;
            }
        }while(action !=6);
    }
}

/******************************************************************************/

int modify_menu(Student *eleve){
  /*This menu is used to modify some information about a student *eleve*/
  int action;
  int ind3, ind4, ind5;
  char tab1[sizeFieldStudi], tab2[sizeStudentCity];
  do {
      printf("%s", menuSep);   //Only display cf DISPLAY_FONC
      student_display(eleve);
      printf("\n\n");
      modify_menu_display();   //Only display cf DISPLAY_FONC
      printf("\nEnter your choise : ");
      scanf("%d", &action),
      printf("\n");
      switch(action){
          case 1:
              /*Change the age of this student*/
              printf("Current age : %d\nEnter new age : ", eleve->age);
              fflush(stdin);
              scanf("%d", &eleve->age);
              printf("\n");
              break;
          case 2:
              /*Change the year of studies of this student*/
              printf(
                  "Current year of studies : %d\nEnter a new year : ",
                  eleve->yearStudy
              );
              fflush(stdin);
              scanf("%d", &eleve->yearStudy);
              printf("\n");
              break;
          case 3:
              /*Change the field of Studies*/
              printf(
                  "Current field of studies : %s\nEnter field of studies : ",
                  eleve->fieldStudy
              );
              fflush(stdin);
              scanf("%[^\n%]*c", tab1);
              copy_array_char(
                  eleve->fieldStudy, tab1, sizeFieldStudi, sizeFieldStudi
              );
              printf("\n");
              break;
          case 4:
              /*sub-menu to display all */
              printf(
                  "Current city of residence : %s\nEnter city of residence : ",
                  eleve->cityResidence
              );
              fflush(stdin);
              scanf("%[^\n%]*c", tab2);
              copy_array_char(
                  eleve->cityResidence, tab2, sizeStudentCity, sizeStudentCity
              );
              printf("\n");
              break;
          case 5:
              /*Change field of interest*/
              printf(
                  "Current fiel of interest :\n%s\n%s\n%s\n\n"
                  "Enter nex field of interest :\n",
                  eleve->interest[0].field,
                  eleve->interest[1].field,
                  eleve->interest[2].field
              );
              display_interest(); printf("\n");
              fflush(stdin);
              printf("- "); scanf("%d", &ind3);
              printf("- "); scanf("%d", &ind4);
              printf("- "); scanf("%d", &ind5);
              eleve->interest[0] = tabOfInterest[ind3-1];
              eleve->interest[1] = tabOfInterest[ind4-1];
              eleve->interest[2] = tabOfInterest[ind5-1];
              break;
          case 6:
              /*Quit this menu*/
              return(0);
              break;
          default:
              printf(
                  "%sPlease enter a valid propostion !\n",
                  actionSep
              );
              break;
       }
  }while(action !=6);
}

/******************************************************************************/

int find_all_menu() {
    int action, aGe, yAe, iTn;
    char valid;
    char cIt[sizeStudentCity];
    char sTu[sizeStudentCity];

    do {
        printf("%s", menuSep);   //Only display cf DISPLAY_FONC
        display_perway_menu_display();   //Only display cf DISPLAY_FONC
        printf("\nEnter your choise : ");
        scanf("%d", &action),
        printf("\n");
        switch(action){
            case 1:
                /*Display all student in the glossary whose have the same age*/
                fflush(stdin);
                printf("Enter an age : ");
                scanf("%d", &aGe);
                printf("\n");

                if (display_all_age(aGe)){
                    printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //enter a letter to continue
                break;
            case 2:
                /*Display all student in the glossary whose have the same
                year of study*/
                fflush(stdin);
                printf("Enter an year of study : ");
                scanf("%d", &yAe);
                printf("\n");

                if (display_all_year(yAe)){
                    printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //enter a letter to continue
                break;
            case 3:
                /*Display all student in the glossary whose have the same city*/
                fflush(stdin);
                printf("Enter city of residence : ");
                scanf("%[^\n%]*c", cIt);
                printf("\n");

                if (display_all_city(cIt)){
                    printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //enter a letter to continue
                break;
            case 4:
                /*Display all student in the glossary whose have the same
                fiel of studies*/
                fflush(stdin);
                printf("Enter field of studies : ");
                scanf("%[^\n%]*c", sTu);
                printf("\n");

                if(display_all_field(sTu)){
                   printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //enter a letter to continue
                break;
            case 5:
                /*Display all student in the glossary whose
                have the same interest*/
                display_interest(); printf("\n");
                printf("- "); scanf("%d", &iTn); printf("\n");

                if(display_all_inter(iTn)){
                    printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //enter a letter to continue
                break;
            case 6:
                /*Quit*/
                return(0);
                break;
            default:
                printf(
                    "%sPlease enter a valid propostion !\n",
                    actionSep
                );
                break;
        }
    }while(action !=6);
    return(0);
}

/******************************************************************************/

int testzone () {


    return(0);
}
