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

Student stud3 = {
  "Baptist TOUSSAINT",
  19,
  2020,
  "Industrial Engineering",
  "Lille",
  NULL,
  NULL,
  {interst4, interst6, interst5}
};

Student stud4 = {
  "Baptistee TOUSSAINT",
  19,
  2020,
  "Industrial Engineering",
  "Lille",
  NULL,
  NULL,
  {interst2, interst8, interst5}
};

int nbrStudent = 4;

Student *tab[4] = {
  &stud1,
  &stud2,
  &stud3,
  &stud4,
};

#endif // STUDENTS_LIST_H_INCLUDED
