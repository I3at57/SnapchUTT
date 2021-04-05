#ifndef STUDENTS_LIST_H_INCLUDED
#define STUDENTS_LIST_H_INCLUDED

/*******************************************************************************
This list is the firt test of a file with data base of student.
init_glossary() (in STUDENTS_FONC.h) read this file to fil the glossary
*******************************************************************************/

#include "STRUCTURES.h"
#include "CONST.h"

Student stud1 = {
    "Baptiste TOUSSAINT",
    19,
    2020,
    "Industrial Engineering",
    "Lille",
    NULL,
    NULL,
    {interst2, interst3, interst5}
};

Student stud2 = {
    "Lucas MARTINEZ",
    19,
    2020,
    "Mecanical Engineering",
    "Troyes",
    NULL,
    NULL,
    {interst5, interst8, interst1}
};

Student stud3 = {
    "Alexis POCHARD",
    19,
    2020,
    "Industrial Engineering",
    "Lille",
    NULL,
    NULL,
    {interst7, interst4, interst5}
};

Student stud4 = {
    "Florimon LALANDE",
    22,
    2016,
    "Industrial Engineering",
    "Lille",
    NULL,
    NULL,
    {interst5, interst6, interst7}
};

int nbrStudent = 4;

Student *stuTab[4] = {
    &stud1,
    &stud2,
    &stud3,
    &stud4,
};

#endif // STUDENTS_LIST_H_INCLUDED
