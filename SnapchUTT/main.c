#include "main.h"

int main()
{
    /*
    printf("0\n");
    init_glossary(stuTab, nbrStudent);
    printf("1\n");
    Student *ptr = glossary[1].beginList;
    printf("2\n");
    printf("%s", ptr->name);
    */
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

Student studf = {
    "Lucos MARTINEZ",
    19,
    2120,
    "Meamical Engineering",
    "Troes",
    NULL,
    NULL,
    {interst5, interst8, interst1}
};


    Student *eleve;
    eleve = create_student();
    student_display(eleve);
    free(eleve);
    return(0);
}
