#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

int researching_student(Student* target)
{/*This function take a student pointer as argument and find his position.
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

void errase_student(int position)
{/*take the postion of a student in the file and errase it*/

    FILE* openFile = fopen("student-list.txt", "r");  //Student data-base file
    FILE* transFile = fopen("tran.txt", "w");
    //Create a file only use in this fonction

    int nbrStar = 0, nbrStudent = 0;
    char lastChar;

    fscanf(openFile, "%d", &nbrStudent);  //Compt the number of student
    fprintf(transFile, "%d", nbrStudent-1); //Copy it on the temporary file

    do {
        /*Every student comes with two star '*' to draw limit
        If I want to delete student in positon 5:
        I have to read 4 student so 8 stars '* '*/
        lastChar = fgetc(openFile);
        fprintf(transFile, "%c", lastChar);
        if (lastChar == '\*') {
            nbrStar++;
        }
    } while (nbrStar < (position-1)*2);
    fgetc(openFile); fgetc(openFile);
    //Read a '\n' and the 1st '*' of the erased student
    while (fgetc(openFile) != '*');
    //read and forget all the information off the reased student

    while (feof(openFile)==0) {
        //Copy the rest of the file
        lastChar = fgetc(openFile);
        if (feof(openFile) == 0) {
            fprintf(transFile, "%c", lastChar);
        }
    }
    //transFile contain now the new file with updates informations
    fclose(openFile); fclose(transFile);

    openFile = fopen("student-list.txt", "w");
    transFile = fopen("tran.txt", "r");

    while (feof(transFile) == 0) {
        //Copy all the informations in transFile into student-list
        lastChar = fgetc(transFile);
        if (feof(transFile) == 0) {
            fprintf(openFile, "%c", lastChar);
        }
    }

    fclose(openFile); fclose(transFile);
    remove ("tran.txt");  //delete the temporary file
}

int ecrire_student(Student* stud)
{
    FILE* openFile = fopen("student-list.txt", "a");
    fprintf(openFile, "*\n");
    fprintf(openFile, "%s\n", stud->name);
    fprintf(openFile, "%d\n", stud->age);
    fprintf(openFile, "%d\n", stud->yearStudy);
    fprintf(openFile, "%s\n", stud->fieldStudy);
    fprintf(openFile, "%s\n", stud->cityResidence);
    fprintf(openFile, "%d\n", stud->interest[0].nbr);
    fprintf(openFile, "%d\n", stud->interest[1].nbr);
    fprintf(openFile, "%d\n", stud->interest[2].nbr);
    fprintf(openFile, "*");
    fclose(openFile);
}
