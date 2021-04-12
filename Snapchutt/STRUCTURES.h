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

typedef struct Follow {
    int maxElement;
    int nbrFollower;
    struct Student **listFollower;
    int known;
    int suggestionCount;
}Follow;

typedef struct Student {
    /*This is the main structure of the project.*/
    char name [50];   //name of this student
    int age;    //age of this student
    int yearStudy;    //year of studies begin
    char fieldStudy [50];   //name of the fild studied
    char cityResidence [50];   //city of this student
    struct Student *nextAlphaStudent; //Next student per alphabetic.
    Follow follower;    //pointer to the follow list.
    FieldOfInterest interest[3];    //hobbys
}Student;

typedef struct LineGlossary {
    /*We can associate a letter of the alphabet to a pointer in student*/
    char letter;
    Student *beginList;
}LineGlossary;

#endif // STRUCTURES_H_INCLUDED
