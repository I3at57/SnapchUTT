/*******************************************************************************
FUNCTION.h contains all the functions that we use.
*******************************************************************************/

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "CONST.h"
#include "STRUCTURES.h"

/* Utility functions */

extern int compare_strings(char *str1, char *str2);

extern int compare_strings_simple(char str1[], char str2[]);

extern int copy_array_char(char *targetArray, char *contentArray, int lth1, int lth2);

/* Menu functions */

extern int main_menu();

extern int add_menu();

extern int find_one_menu();

extern int find_all_menu();

extern int testzone ();

/* To display */

extern void array_char_display(char tab[]);

extern void menu_display();

extern void find_menu_display();

extern void student_display(Student *stu);

extern void list_of_students_display(Student *stud);

/* To manipulate students */

extern Student *create_student();

extern int add_student(Student *stud);

extern int init_glossary(Student *tab[],int nbrStudent);

extern Student *find_student(char *name);

extern int delete_student(Student *stud);

extern void clear_links(Student *stud);

extern void quit();

#endif // FUNCTIONS_H_INCLUDED
