#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

int researching_student(Student* target) {
    /*This function take a student pointer as argument and find his position
     in the file student-list.txt and return it*/

    char lastChar;
    int nbrStudent=0, compt=0, find=0, i=0;
    FILE* ptrFile = fopen("student-list.txt", "r");

    fscanf(ptrFile, "%d", &nbrStudent);
    fgetc(ptrFile); fgetc(ptrFile);  //read two '\n' and a '*'

    do {
        fgetc(ptrFile); fgetc(ptrFile); //read '*' and '\n'
        i = 0;
        if (fgetc(ptrFile) == target->name[i]) {
            do {
                i++;
                lastChar = fgetc(ptrFile);
            } while (lastChar == target->name[i] || lastChar != '\n');
            /* the loop break if one letter is different, so it's not the right
            right student or if the lastChar is '\n' then we fund the rigth
            student to delete
            */
            if (lastChar == '\n') {
                find = 1; //we have found the good one
            }
        } else {
            /*This student can't be the good one so let's read every char until
            we found the '*' which symbolise the end of this student
            in the file
            */
            do {
                lastChar = fgetc(ptrFile);
            } while (lastChar != '*');
            fgetc(ptrFile); //read '\n'
            // the variable find stay at value 0.
        }
        compt++;  // we had read the 'compt'th student
    } while (find == 0 && compt < nbrStudent);
    /*The loop end if :
        find == 1 -> we found the good student to delete in position 'compt'
        compt == nbrStudent && find == 0 -> the researching student
        doesn't exist
    */
    if (compt == nbrStudent && find == 0) {
        return(0);
    } else {
        return(compt);
    }
    fclose(ptrFile);
}

int errase_student(int position) {
    FILE* openFile = fopen("student-list.txt", "r");
    FILE* transFile = fopen("tran.txt", "w");

    int nbrStar = 0, nbrStudent = 0;
    char lastChar;

    fscanf(openFile, "%d", &nbrStudent);
    do {
        lastChar = fgetc(openFile);
        fprintf(transFile, "%d", lastChar);
        if (lastChar == '\*') {
            nbrStar++;
        }
    } while (nbrStar < (position-1)*2);
    fgetc(openFile); fgetc(openFile);
    while (fgetc(openFile) != '*');
    fgetc(openFile);
    while (feof(openFile)) {
        lastChar = fgetc(openFile);
        fprintf(transFile, "%d", lastChar);
    }

    fclose(openFile); fclose(transFile);

    openFile = fopen("student-list.txt", "w");
    transFile = fopen("tran.txt", "r");

    while (feof(openFile)) {
        lastChar = fgetc(openFile);
        fprintf(transFile, "%d", lastChar);
    }
}
