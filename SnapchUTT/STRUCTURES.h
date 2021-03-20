#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct Student Student;
struct Student {
  /* This is the main structure of the project*/
  char name [50];
  int age;
  int yearStudy;
  char fieldStudy [50];
  char cityResidence [100];
  int interest [8];
  Student *nextAlphaStudent;
  Student *followStudent;
};

typedef struct LineGlossary LineGlossary;
struct LineGlossary {
  char letter;
  Student *beginList;
};

#endif // STRUCTURES_H_INCLUDED
