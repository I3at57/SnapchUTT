#ifndef STUDENTS_LIST_H_INCLUDED
#define STUDENTS_LIST_H_INCLUDED

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

int nbrStudent = 2;

Student *tab[2] = {
  &stud1,
  &stud2,
};

#endif // STUDENTS_LIST_H_INCLUDED
