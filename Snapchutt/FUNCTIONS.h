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

extern int compare_fields_of_interest(Student * stud1, Student *stud2);

extern void fget_line(FILE* fptr, char* str);

/* Menu functions */

extern int main_menu();

extern int add_menu();

extern int find_one_menu();

extern int modify_menu(Student *eleve);

extern int find_all_menu();

extern int testzone();

/* To display */

extern void array_char_display(char tab[]);

extern void display_interest();

extern void menu_display();

extern void find_menu_display();

extern void display_perway_menu_display();

extern void modify_menu_display();

extern void student_display(Student *stu);

extern void display_follow_list(Student *stud);

/* To manipulate students */

extern Student *create_student();

extern int add_student(Student *stud);

extern void init_glossary();

extern void init_followers();

extern Student *find_student(char *name);

extern void add_follow(Student *stud, Student *follow);

extern void suggest_follows(Student *stud,Student **suggestionTab, int nbrSuggestion);

extern int delete_student(Student *stud);

extern void clear_links(Student *stud);

extern void quit();

/* To displays all student by specifics criteria*/

extern int display_all_alpha();

extern int display_all_age(int dage);

extern int display_all_year(int dyear);

extern int display_all_city(char *dcity);

extern int display_all_field(char *dfield);

extern int display_all_inter(int dinter);

/* To read and wright in the file for student*/

extern int researching_student(Student* target);

extern void errase_student(int position);

extern int ecrire_student(Student* stud);

extern void fremove_line(FILE* fptr, int line);

#endif // FUNCTIONS_H_INCLUDED
