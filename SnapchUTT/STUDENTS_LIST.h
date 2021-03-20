#ifndef STUDENTS_LIST_H_INCLUDED
#define STUDENTS_LIST_H_INCLUDED

#include "STRUCTURES.h"

Student stud1 = {
  "Baptiste TOUSSAINT",
  19,
  2020,
  "Industrial Engineering",
  "Lille",
  {2, 3, 5},
  NULL,
  NULL,
};

Student stud2 = {
  "Lucas MARTINEZ",
  19,
  2020,
  "Mecanical Engineering",
  "Troyes",
  {5, 8, 1},
  NULL,
  NULL,
};

Student stud3 = {
  "Baptist TOUSSAINT",
  19,
  2020,
  "Industrial Engineering",
  "Lille",
  {2, 3, 5},
  NULL,
  NULL,
};

Student stud4 = {
  "Baptistee TOUSSAINT",
  19,
  2020,
  "Industrial Engineering",
  "Lille",
  {2, 3, 5},
  NULL,
  NULL,
};

int nbrStudent = 4;

Student *tab[4] = {
  &stud1,
  &stud2,
  &stud3,
  &stud4,
};

#endif // STUDENTS_LIST_H_INCLUDED
