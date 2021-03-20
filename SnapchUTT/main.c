//#include "main.h"
#include "DISPLAY_FONC.h"

int main()
{
    int action;
    //init_glossary();

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

    return(0);
}
