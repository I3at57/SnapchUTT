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

  init_glossary();

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
}
