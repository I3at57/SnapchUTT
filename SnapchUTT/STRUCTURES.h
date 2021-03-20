#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct FieldOfInterest {
    int nbr;
    char field[20];
}FieldOfInterest;

typedef struct Student {
  /* This is the main structure of the project*/
  char name [50];
  int age;
  int yearStudy;
  char fieldStudy [50];
  char cityResidence [100];
  struct Student *nextAlphaStudent;
  struct Student *followStudent;
  FieldOfInterest interest[3];
}Student;

typedef struct LineGlossary {
  char letter;
  Student *beginList;
}LineGlossary;

#endif // STRUCTURES_H_INCLUDED
