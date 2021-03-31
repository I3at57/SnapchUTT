/*******************************************************************************
STRUCTURES.h contain all personal types we have created.
It must be imported at firt during execution.
*******************************************************************************/

#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct FieldOfInterest {
    /*FieldOfInterest represents a field of interest a student can have. It is
    composed of : 'nbr' and 'field'. Links a field with a number make it easier
    to find, with this method we can made a research per int to find a field
    Cf CONST.h for more information.*/
    int nbr;
    char field[20]; //Ex : 'Art'
}FieldOfInterest;

typedef struct ListOfFollower {
    int maxElement;
    int nbrFollower;
    struct Student *listFollower[];
}ListOfFollower;

typedef struct Student {
    /*This is the main structure of the project.*/
    char name [50];
    int age;
    int yearStudy;
    char fieldStudy [50];
    char cityResidence [100];
    struct Student *nextAlphaStudent; //Next student per alphabetic.
    ListOfFollower follower;
    FieldOfInterest interest[3];
}Student;

typedef struct LineGlossary {
    /*We can associate a letter of the alphabet to a pointer in student*/
    char letter;
    Student *beginList;
}LineGlossary;

#endif // STRUCTURES_H_INCLUDED
