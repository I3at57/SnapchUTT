#include "main.h"

int main()
{
    init_glossary(stuTab, nbrStudent);

    Student *eleve = NULL;
    find_student(eleve, "Baptiste TOUSSAINT");


//    int action;
//    do {
//        menu_display();
//        printf("\nEnter your choise : ");
//        scanf("%d", &action),
//        printf("\n");
//        switch(action){
//            case 1:
//                break;
//            case 2:
//                break;
//            case 3:
//                break;
//            case 4:
//                break;
//            case 5:
//                break;
//            default:
//                printf(
//                        "Please enter a valid propostion !\n"
//                        "\n\n\n\n\n\n\n\n\n"
//                );
//                break;
//        }
//    }while(action !=5);
//    student_display(stuTab[0]);
//    printf("\n\n");
//    student_display(stuTab[1]);
//    printf("\n\n");
//    student_display(stuTab[2]);
//    printf("\n\n");
//    student_display(stuTab[3]);
//    printf("\n\n");

    return(0);
}
