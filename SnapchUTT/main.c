#include "main.h"

int main()
{
//Un commentaire
  int action;

  init_glossary();

  do {
    menu_display();
    scanf("d", &action),
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
            printf("Please enter a valid propostion !\n");
            break;
    }
  }while((action < 5)&&(action>0));

}
