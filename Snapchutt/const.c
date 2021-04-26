#include <stdlib.h>
#include "CONST.h"

/*******************************************************************************
This file is used to declare constants
*******************************************************************************/

/*This 3 constants must be equal to the declaration of typedef Student in
STRUCTURES.h*/
const int sizeName = 50;
const int sizeFieldStudi = 50;
const int sizeStudentCity = 100;


char quitString[] = "Quit";
const char menuSep[]=
      "\n           ~~~~~     *********************     ~~~~~           \n\n";
const char actionSep[]=
      "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";;

const int nbrInterest = 13;
const FieldOfInterest interst1 = {1, "Sport"};
const FieldOfInterest interst2 = {2, "Cinema"};
const FieldOfInterest interst3 = {3, "Art"};
const FieldOfInterest interst4 = {4, "Health"};
const FieldOfInterest interst5 = {5, "Technology"};
const FieldOfInterest interst6 = {6, "DIY"};
const FieldOfInterest interst7 = {7, "Cooking"};
const FieldOfInterest interst8 = {8, "Travel"};
const FieldOfInterest interst9 = {9, "Sing"};
const FieldOfInterest interst10 = {10, "Videos Games"};
const FieldOfInterest interst11 = {11, "Reading"};
const FieldOfInterest interst12 = {12, "Politic"};
const FieldOfInterest interst13 = {13, "Economy"};
const FieldOfInterest interst14 = {14, "Robotic"};

const FieldOfInterest tabOfInterest [14] = {
    interst1, interst2, interst3, interst4, interst5, interst6, interst7,
    interst8, interst9, interst10, interst11, interst12, interst13, interst14
};


LineGlossary glossary[26] = {
    {'A', NULL}, {'B', NULL}, {'C', NULL}, {'D', NULL}, {'E', NULL},
    {'F', NULL}, {'G', NULL}, {'H', NULL}, {'I', NULL}, {'J', NULL},
    {'K', NULL}, {'L', NULL}, {'M', NULL}, {'N', NULL}, {'O', NULL},
    {'P', NULL}, {'Q', NULL}, {'R', NULL}, {'S', NULL}, {'T', NULL},
    {'U', NULL}, {'V', NULL}, {'W', NULL}, {'X', NULL}, {'Y', NULL},
    {'Z', NULL},
};
