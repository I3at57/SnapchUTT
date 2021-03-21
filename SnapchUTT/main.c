#include "main.h"

int main()
{
    printf("0\n");
    init_glossary(stutab, nbrStudent);
    printf("1\n");
    Student *ptr = glossary[1].beginList;
    printf("2\n");
    printf("%s", ptr->name);
/*
  int action;

    do {
        menu_display();
        printf("\nEnter your choise : ");
        scanf("%d", &action),
        printf("\n");
        switch(action){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf(
                       "Please enter a valid propostion !\n"
                       "\n\n\n\n\n\n\n\n\n"
                );
                break;
        }
    }while(action !=5);
    student_display(&stud1);
    printf("\n\n");
    student_display(&stud2);
*/
    return(0);
}
