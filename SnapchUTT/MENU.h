#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "CONST.h"

int main_menu() {
    int action;
    do {
        printf("%s", beaSep);
        menu_display();
        printf("\nEnter your choise : ");
        scanf("%d", &action),
        printf("\n");
        switch(action){
            case 1:
                printf("Work in progress ...\n");
                //add_menu();
                break;
            case 2:
                printf("Work in progress ...\n");
                find_one_menu();
                break;
            case 3:
                printf("Work in progress ...\n");
                find_all_menu();
                break;
            case 4:
                //quit();
                return(0);
                break;
            case 5:
                testzone();
                break;
            default:
                printf(
                        "Please enter a valid propostion !\n"
                        "\n\n\n\n\n\n\n\n\n"
                );
                break;
         }
    }while(action !=4);
}

int add_menu() {

    return(0);
}

int find_one_menu() {

//    Student *eleve;
//    char nameStr[50];
//    int ind = 1;
//
//    do {
//        fflush(stdin);
//        printf("\nEnter a name : ");
//        scanf("%[^\n%]*c", nameStr);
//        if (find_student(eleve, nameStr) == 0) {
//            student_display(eleve);
//            ind++;
//        }
//        else {
//            printf("\nThis student doesn't exist :/\n");
//        }
//    }while(ind == 1);

    return(0);
}

int find_all_menu() {
    return(0);
}

int testzone () {
    Student *eleve = NULL;
    char str[50];

    fflush(stdin);
    scanf("%[^\n%]*c", str);
    eleve = find_student(str);
    if (eleve == NULL) {
        printf("Not fund");
        student_display(eleve);
    }
    else {
        student_display(eleve);
    }
    return(0);
}

#endif // MENU_H_INCLUDED
