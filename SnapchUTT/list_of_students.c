#include <stdlib.h>
#include "CONST.h"

/*******************************************************************************
This list is the firt test of a file with data base of student.
init_glossary() (in STUDENTS_FONC.h) read this file to fil the glossary
To create a new student, just need to declare change the number of student and
add him in the tab
*******************************************************************************/

//const FieldOfInterest interst1 = {1, "Sport"};
//const FieldOfInterest interst2 = {2, "Cinema"};
//const FieldOfInterest interst3 = {3, "Art"};
//const FieldOfInterest interst4 = {4, "Health"};
//const FieldOfInterest interst5 = {5, "Technology"};
//const FieldOfInterest interst6 = {6, "DIY"};
//const FieldOfInterest interst7 = {7, "Cooking"};
//const FieldOfInterest interst8 = {8, "Travel"};
//const FieldOfInterest interst9 = {9, "Sing"};
//const FieldOfInterest interst10 = {10, "Videos Games"};
//const FieldOfInterest interst11 = {11, "Reading"};
//const FieldOfInterest interst12 = {12, "Politic"};
//const FieldOfInterest interst13 = {13, "Economie"};
//const FieldOfInterest interst14 = {14, "Robotic"};

LineGlossary glossary[26] = {
    {'A', NULL}, {'B', NULL}, {'C', NULL}, {'D', NULL}, {'E', NULL},
    {'F', NULL}, {'G', NULL}, {'H', NULL}, {'I', NULL}, {'J', NULL},
    {'K', NULL}, {'L', NULL}, {'M', NULL}, {'N', NULL}, {'O', NULL},
    {'P', NULL}, {'Q', NULL}, {'R', NULL}, {'S', NULL}, {'T', NULL},
    {'U', NULL}, {'V', NULL}, {'W', NULL}, {'X', NULL}, {'Y', NULL},
    {'Z', NULL},
};


Student stud1 = {
    "Baptiste TOUSSAINT", 19, 2020, "Industrial Engineering", "Lille",
    NULL, {0, 0, NULL}, {interst12, interst11, interst13}
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
    {interst14, interst5, interst7}
};

Student stud5 = {
    "Clemence COTTIGNY", 18, 2020, "Medicine", "Loos",
    NULL, {0, 0, NULL}, {interst7, interst9, interst6}
};

Student stud6 = {
    "Tancrede CATTEAU", 17, 2020, "Cinema", "Tournais",
    NULL, {0, 0, NULL}, {interst2, interst3, interst12}
};

Student stud7 = {
    "Louis FERRAND", 17, 2020, "Ingeniering", "Villeneuve d'Ascq",
    NULL, {0, 0, NULL}, {interst10, interst4, interst8}
};

int nbrStudent = 7;

const Student *stuTab[7] = {
    &stud1, &stud2, &stud3, &stud4, &stud5, &stud6, &stud7,
};
