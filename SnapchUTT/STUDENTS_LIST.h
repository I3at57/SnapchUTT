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
  "Martinez LUCAS",
  19,
  2020,
  "Mecanical Engineering",
  "Troyes",
  {5, 8, 1},
  NULL,
  NULL,
};

int nbrStudent = 2;

Student tab[2] = {
  stud1,
  stud2,
}

#endif // STUDENTS_LIST_H_INCLUDED
