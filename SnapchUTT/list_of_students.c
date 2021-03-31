#include <stdlib.h>
#include "CONST.h"

int sizeName = 50;
int sizeFieldStudi = 50;
int sizeStudentCity = 100;

char quitString[] = "Quit";
char beaSep[]=
      "\n\n\n"
      "           ~~~~~     *********************     ~~~~~           \n\n";

const FieldOfInterest interst1 = {1, "Sport"};
const FieldOfInterest interst2 = {2, "Cinema"};
const FieldOfInterest interst3 = {3, "Art"};
const FieldOfInterest interst4 = {4, "Health"};
const FieldOfInterest interst5 = {5, "Technology"};
const FieldOfInterest interst6 = {6, "DIY"};
const FieldOfInterest interst7 = {7, "Cooking"};
const FieldOfInterest interst8 = {8, "Travel"};

FieldOfInterest tabOfInterest [8] = {
    interst1, interst2, interst3, interst4, interst5, interst6, interst7,
    interst8
};

LineGlossary glossary[26] = {
    {'A', NULL}, {'B', NULL}, {'C', NULL}, {'D', NULL}, {'E', NULL},
    {'F', NULL}, {'G', NULL}, {'H', NULL}, {'I', NULL}, {'J', NULL},
    {'K', NULL}, {'L', NULL}, {'M', NULL}, {'N', NULL}, {'O', NULL},
    {'P', NULL}, {'Q', NULL}, {'R', NULL}, {'S', NULL}, {'T', NULL},
    {'U', NULL}, {'V', NULL}, {'W', NULL}, {'X', NULL}, {'Y', NULL},
    {'Z', NULL},
};

Student stud1 = {
    "Baptiste TOUSSAINT",
    19,
    2020,
    "Industrial Engineering",
    "Lille",
    NULL,
    {0, 0, NULL},
    {interst2, interst3, interst5}
};


Student stud2 = {
    "Lucas MARTINEZ",
    19,
    2020,
    "Mecanical Engineering",
    "Troyes",
    NULL,
    {0, 0, NULL},
    {interst5, interst8, interst1}
};

Student stud3 = {
    "Alexis POCHARD",
    19,
    2020,
    "Industrial Engineering",
    "Lille",
    NULL,
    {0, 0, NULL},
    {interst7, interst4, interst5}
};

Student stud4 = {
    "Florimon LALANDE",
    22,
    2016,
    "Industrial Engineering",
    "Lille",
    NULL,
    {0, 0, NULL},
    {interst5, interst6, interst7}
};

int nbrStudent = 4;

Student *stuTab[4] = {
    &stud1,
    &stud2,
    &stud3,
    &stud4,
};
