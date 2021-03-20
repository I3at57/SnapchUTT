#include "main.h"
#include "STRUCTURES.h"
#include "CONST.h"
#include "STUDENTS_FONC.h"
#include "STUDENTS_LIST.h"

int main()
{
    printf("0\n");
    init_glossary(*tab, nbrStudent);
    printf("1\n");
    Student *ptr = Glossary[1].beginList;
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
    }while(action !=5);*/

  do {
    menu_display();
    scanf("d", &action);
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
            action++;
            break;
        default:
            printf("Please enter a valid propostion !\n");
            break;
    }
  }while((action < 5)&&(action>0));
*/
  return(0);
    student_display(&stud1);
    printf("\n\n");
    student_display(&stud2);

    return(0);
}
