/*******************************************************************************
STRUCTURES.h contain all personal type we've created.
It must be import at firts during execution.
*******************************************************************************/

#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct FieldOfInterest {
    /*FieldOfInterest represent a field of interest a student can have. It is
    compose by : 'nbr' and 'field'. Links a field with a number make it easier
    to find, with this methode we can made a recherche per int to find a field
    Cf CONST.h for more information.*/
    int nbr;
    char field[20]; //Ex : 'Art'
}FieldOfInterest;

typedef struct Student {
    /*This is the main structure of the project.*/
    char name [50];
    int age;
    int yearStudy;
    char fieldStudy [50];
    char cityResidence [100];
    struct Student *nextAlphaStudent; //Next student per alphabetic.
    struct Student *followStudent; //pointer to the follow list.
    FieldOfInterest interest[3];
}Student;

typedef struct LineGlossary {
    /*We can associate a letter of the alphabet to a pointer in student*/
    char letter;
    Student *beginList;
}LineGlossary;

#endif // STRUCTURES_H_INCLUDED
