#ifndef CONST_H_INCLUDED
#define CONST_H_INCLUDED

#include "STRUCTURES.h"

/*This file is used to declare constants*/

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

#endif // CONST_H_INCLUDED
