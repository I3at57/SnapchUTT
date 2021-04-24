#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

int main()
{
    /*Put every student of STUDENTS_LIST in glossary*/
    init_glossary();
    init_followers();
    main_menu();//The main menu of the application
    quit();
    return(0);
}
