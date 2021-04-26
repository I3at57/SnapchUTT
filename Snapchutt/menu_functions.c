#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
All the menu functions which call other functions.
*******************************************************************************/


/*The main_menu is the main menu loop. It allows to navigate in othersub-menu*/
int main_menu()
{
    int action;
    char valid;
    do {
        printf("%s", menuSep); //Only display cf DISPLAY_FONC
        menu_display(); //Only display cf DISPLAY_FONC
        printf("\nEnter your choise : ");
        scanf("%d", &action);
        switch(action){
            case 1:
                /*Sub-menu to add a student to the glossary*/
                add_student(create_student());
                break;
            case 2:
                /*Sub-menu to find a student only on name-based research*/
                find_one_menu();
                break;
            case 3:
                /*Sub-menu to make a research by other field (age, field...)*/
                find_all_menu();
                break;
            case 4:
                /*Sub-menu to display all students by name*/
                printf("%s", actionSep);
                display_all_alpha();

                fflush(stdin);
                scanf("%c", &valid); //Enter a letter to continue
                break;
            case 5:
                /*quit is the only way to quit the application*/
                //quit();
                return(0);
                break;
            case 6:
                /*A test zone only for developer*/
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
    return 0;
}

/******************************************************************************/

/*
int add_menu() {
    add_student(create_student());
    return(0);
}*/

/******************************************************************************/

/*The find_one_menu function finds a student on name-based research*/
int find_one_menu()
{
    Student *eleve, *eleve2;
    char nameStr[sizeName];
    char valid;
    int action;

    do {
        /*A loop to research a specific student by name*/
        fflush(stdin);
        printf("\nEnter a name : ");
        scanf("%[^\n%]*c", nameStr);
        eleve = find_student(nameStr); //Give the pointer of a student
        if (eleve == NULL) {
            printf("\nThis student doesn't exist :/\n");
            printf("Enter 'Quit' to quit.\n");
        } else {
            printf("\n");
        }
    }while(eleve == NULL && compare_strings_simple(nameStr, quitString));
    /*If nameStr is 'Quit' the loop ends and eleve = NULL
    else eleve points on a student in glossary*/

    if (compare_strings_simple(nameStr, quitString) == 0) {
        return(1);
    } else {
        do {
            printf("%s", menuSep); //Only display cf DISPLAY_FONC
            student_display(eleve);
            printf("\n\n");
            find_menu_display(); //Only display cf DISPLAY_FONC
            printf("\nEnter your choise : ");
            scanf("%d", &action),
            printf("\n");
            switch(action){
                case 1:
                    /*Sub-menu to modify a student*/
                    modify_menu(eleve);
                    break;
                case 2:
                    /*Sub-menu to delete the current student*/
                    printf("\n%s got removed\n", eleve->name);
                    delete_student(eleve);
                    return 0;
                    break;
                case 3:
                    /*A function to add a follow in the list of follows
                    of a student*/
                    fflush(stdin);
                    printf("\nWho %s wants to follow ? : ", eleve->name);
                    scanf("%[^\n%]*c", nameStr);
                    printf("\n");
                    eleve2 = find_student(nameStr);
                    if (eleve2 == NULL){
                        printf("\nThis student doesn't exist :/\n");
                    } else {
                        add_follow(eleve, eleve2);
                        printf("\n%s follows %s\n", eleve->name, eleve2->name);
                    }
                    break;
                case 4:
                    /*A function to delete a follow in the list of follows
                    of a student*/
                    fflush(stdin);
                    printf("\nWho %s, wants to unfollow ? : ", eleve->name);
                    scanf("%[^\n%]*c", nameStr);
                    printf("\n");
                    eleve2 = find_student(nameStr);
                    if (eleve2 == NULL){
                        printf("\nThis student doesn't exist :/\n");
                    } else {
                        delete_follow(eleve, eleve2);
                        printf("\n%s unfollows %s\n", eleve->name, eleve2->name);
                    }
                    break;
                case 5:
                {
                    /*Sub-menu to suggest a list of follows*/
                    Student *suggestTab[5];
                    suggest_follows(eleve, suggestTab, 5);
                    printf("The computer suggests you to follow :\n\n");
                    for (int i = 0; i < 5; i++){
                        if (suggestTab[i] != NULL){
                            student_display(suggestTab[i]);
                            printf("\n\n");
                        }
                    }
                    fflush(stdin);
                    scanf("%c", &valid); //Enter a letter to continue
                    break;
                }
                case 6:
                    /*Display all students followed by 'eleve'*/
                    display_follow_list(eleve);
                    fflush(stdin);
                    scanf("%c", &valid); //Enter a letter to continue
                    break;
                case 7:
                    /*Quit this menu*/
                    return 0;
                    break;
                case 8:
                    /*A test zone only for developer*/
                    testzone();
                    break;
                default:
                    printf(
                        "%sPlease enter a valid propostion !\n",
                        actionSep
                    );
                    break;
            }
        }while(action !=7);
    }
    return 0;
}

/******************************************************************************/

/*The modify_menu function is used to modify some informations about a student *eleve*/
int modify_menu(Student *eleve)
{
  int action;
  int ind3, ind4, ind5;
  char tab1[sizeFieldStudi], tab2[sizeStudentCity];
  //int posi = researching_student(eleve);
  do {
      printf("%s", menuSep); //Only display cf DISPLAY_FONC
      student_display(eleve);
      printf("\n\n");
      modify_menu_display(); //Only display cf DISPLAY_FONC
      //int posi = researching_student(eleve);
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
              /*Change the field of studies*/
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
              /*Sub-menu to display all */
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
              return 0;
              break;
          default:
              printf(
                  "%sPlease enter a valid propostion !\n",
                  actionSep
              );
              break;
       }
        //errase_student(posi);
        //ecrire_student(eleve);
  }while(action !=6);
  return 0;
}

/******************************************************************************/

/*The find_all_menu function finds students on various type of research*/
int find_all_menu()
{
    int action, aGe, yAe, iTn;
    char valid;
    char cIt[sizeStudentCity];
    char sTu[sizeStudentCity];

    do {
        printf("%s", menuSep); //Only display cf DISPLAY_FONC
        display_perway_menu_display(); //Only display cf DISPLAY_FONC
        printf("\nEnter your choise : ");
        scanf("%d", &action),
        printf("\n");
        switch(action){
            case 1:
                /*Display all students in the glossary
                who have the same age*/
                fflush(stdin);
                printf("Enter an age : ");
                scanf("%d", &aGe);
                printf("\n");

                if (display_all_age(aGe)){
                    printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //Enter a letter to continue
                break;
            case 2:
                /*Display all students in the glossary
                who have the same year of study*/
                fflush(stdin);
                printf("Enter an year of study : ");
                scanf("%d", &yAe);
                printf("\n");

                if (display_all_year(yAe)){
                    printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //Enter a letter to continue
                break;
            case 3:
                /*Display all students in the glossary
                who have the same city*/
                fflush(stdin);
                printf("Enter city of residence : ");
                scanf("%[^\n%]*c", cIt);
                printf("\n");

                if (display_all_city(cIt)){
                    printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //Enter a letter to continue
                break;
            case 4:
                /*Display all students in the glossary
                who have the same field of studies*/
                fflush(stdin);
                printf("Enter field of studies : ");
                scanf("%[^\n%]*c", sTu);
                printf("\n");

                if(display_all_field(sTu)){
                   printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //Enter a letter to continue
                break;
            case 5:
                /*Display all students in the glossary
                who have the same interest*/
                display_interest(); printf("\n");
                printf("- "); scanf("%d", &iTn); printf("\n");

                if(display_all_inter(iTn)){
                    printf("\nNo one match with this information !\n");
                }

                printf("\n");
                fflush(stdin);
                scanf("%c", &valid); //Enter a letter to continue
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
    return(0);
}

/******************************************************************************/

int testzone () {
    printf("%d\n", researching_student(find_student("Clemence COTTIGNY")));
    errase_student(researching_student(find_student("Clemence COTTIGNY")));
    printf("%d\n", researching_student(find_student("Baptiste TOUSSAINT")));
    errase_student(researching_student(find_student("Baptiste TOUSSAINT")));
    return(0);
}
