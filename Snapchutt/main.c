#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

int main()
{
    //Un commentaire
    /*Put every student of STUDENTS_LIST in glossary*/
    printf("0\n");
    init_glossary();
    printf("1\n");
    init_followers();
    printf("2\n");
    main_menu();//The main menu of the application
    quit();
    return(0);
}
