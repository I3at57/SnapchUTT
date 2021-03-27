#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/*******************************************************************************
MENU.h contain all the menu fonction which call other functions
*******************************************************************************/

#include "CONST.h"

int main_menu() {
    /*main_menu() is the principal menu loop, it allow to navigate into other
    sub-menu*/
    int action;
    do {
        printf("%s", beaSep);   //Only display cf DISPLAY_FONC
        menu_display();   //Only display cf DISPLAY_FONC
        printf("\nEnter your choise : ");
        scanf("%d", &action),
        printf("\n");
        switch(action){
            case 1:
                /* sub-menu to add a student into glossary */
                printf("Work in progress ...\n");
                //add_menu();
                break;
            case 2:
                //printf("Work in progress ...\n");
                /*sub-menu find student, only for name based research*/
                find_one_menu();
                break;
            case 3:
                printf("Work in progress ...\n");
                /* sub menu to make a research by other field (age, field...)*/
                find_all_menu();
                break;
            case 4:
                printf("Work in progress ...\n");
                /**/
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
                        "Please enter a valid propostion !\n"
                        "\n\n\n\n\n\n\n\n\n"
                );
                break;
         }
    }while(action !=5);
}

int add_menu() {

    return(0);
}

int find_one_menu() {

    Student *eleve;
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
            student_display(eleve);
        }
    }while(eleve == NULL && compare_strings_simple(nameStr, quitString));
    /* If nameStr is 'Quit' the loop end and eleve = NULL
    else eleve point on a student in glossary. */

    if (compare_strings_simple(nameStr, quitString) == 0) {
        return(0);
    } else {
        do {
            printf("%s", beaSep);   //Only display cf DISPLAY_FONC
            find_menu_display();   //Only display cf DISPLAY_FONC
            printf("\nEnter your choise : ");
            scanf("%d", &action),
            printf("\n");
            switch(action){
                case 1:
                    printf("Work in progress ...\n");
                    /**/
                    break;
                case 2:
                    printf("Work in progress ...\n");
                    /**/
                    break;
                case 3:
                    printf("Work in progress ...\n");
                    /**/
                    break;
                case 4:
                    printf("Work in progress ...\n");
                    /**/
                    break;
                case 5:
                    printf("Work in progress ...\n");
                    /**/
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
                            "Please enter a valid propostion !\n"
                            "\n\n\n\n\n\n\n\n\n"
                    );
                    break;
            }
        }while(action !=6);
    }
}

int find_all_menu() {
    return(0);
}

int testzone () {
    Student *eleve = NULL;
    char str[sizeName];

    fflush(stdin);
    scanf("%[^\n%]*c", str);
    eleve = find_student(str);
    if (eleve == NULL) {
        printf("Not fund");
        student_display(eleve);
    } else {
        student_display(eleve);
    }
    return(0);
}

#endif // MENU_H_INCLUDED
