#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
All the functions relative to read and wright in the file.
*******************************************************************************/


void init_glossary()
{/*Read the 'student-list.txt', create every student, it to the glossary*/

    FILE *fileptr = fopen("student-list.txt", "r"); //Open the file
    if (fileptr) {
        char singleLine[100];
        char lastChar;
        int nbrStudent = 0, j;
        fscanf(fileptr, "%d", &nbrStudent); //Read the nbr of student
        fgetc(fileptr); fgetc(fileptr); //Read 2 '\n'

        for (int i=0; i<nbrStudent; i++) {
            /*
            Every student has the same stucture in the file :

            *
            <Name>
            <Age>
            <Year of studies>
            <Field of studies>
            <City of residence>
            <Hobbys 1>
            <Hobbys 2>
            <Hobbys 3>
            *

            We also know that there is 2*'nbrStudent' stars '*' in the file
            */
            fgetc(fileptr);fgetc(fileptr);  //Read the '*' and a '\n'
            Student *stud = (Student*)malloc(sizeof(Student));

            //All the pointer at NULL to avoid bugs
            stud->follower.known = 0;
            stud->follower.suggestionCount = 0;
            stud->follower.maxElement = 0;
            stud->follower.nbrFollower = 0;
            stud->follower.listFollower = NULL;
            stud->nextAlphaStudent = NULL;

            j = 0;
            while ((lastChar=fgetc(fileptr)) != '\n') {
                //Read a line until '\n'
                singleLine[j] = lastChar;
                j++;
            }
            singleLine[j] = '\0';
            copy_array_char(stud->name, singleLine, 50, 50);
            fscanf(fileptr, "%d", &stud->age); fgetc(fileptr);
            fscanf(fileptr, "%d", &stud->yearStudy); fgetc(fileptr);
            j = 0;
            while ((lastChar=fgetc(fileptr)) != '\n') {
                //Read a line until '\n'
                singleLine[j] = lastChar;
                j++;
            }
            singleLine[j] = '\0';
            copy_array_char(stud->fieldStudy, singleLine, 50, 50);
            j = 0;
            while ((lastChar=fgetc(fileptr)) != '\n') {
                //Read a line until '\n'
                singleLine[j] = lastChar;
                j++;
            }
            singleLine[j] = '\0';
            copy_array_char(stud->cityResidence, singleLine, 50, 50);
            fscanf(fileptr, "%d", &j); fgetc(fileptr);
            stud->interest[0]=tabOfInterest[j-1];
            fscanf(fileptr, "%d", &j); fgetc(fileptr);
            stud->interest[1]=tabOfInterest[j-1];
            fscanf(fileptr, "%d", &j); fgetc(fileptr);
            stud->interest[2]=tabOfInterest[j-1];
            fgetc(fileptr);fgetc(fileptr);

            add_student(stud);  //Add the student in the glossary
        }
    }
    fclose(fileptr);
}


int researching_student(Student* target)
{/*This function takes a student pointer as argument and find his position.
  in the file student-list.txt and returns it*/

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
            /* the loop breaks if one letter is different, so it's not the right
            right student or if the lastChar is '\n' then we find the right
            student to delete
            */
            if (lastChar == '\n') {
                find = 1; //we have found the good one
            }
        } else {
            /*This student can't be the good one so let's read every char until
            we found the '*' which represents the end of this student
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

/*******************************************************************************/


void errase_student(int position)
{/*takes the position of a student in the file and erase it*/

    FILE* openFile = fopen("student-list.txt", "r");  //Student data-base file
    FILE* transFile = fopen("tran.txt", "w");
    //Create a file only use in this function

    int nbrStar = 0, nbrStudent = 0;
    char lastChar;

    fscanf(openFile, "%d", &nbrStudent);  //Compt the number of students
    fprintf(transFile, "%d", nbrStudent-1); //Copy it on the temporary file

    do {
        /*Every student comes with two star '*' to draw limit
        If I want to delete student in position 5:
        I have to read 4 students so 8 stars '*'*/
        lastChar = fgetc(openFile);
        fprintf(transFile, "%c", lastChar);
        if (lastChar == '*') {
            nbrStar++;
        }
    } while (nbrStar < (position-1)*2);
    fgetc(openFile); fgetc(openFile);
    //Read a '\n' and the 1st '*' of the erased student
    while (fgetc(openFile) != '*');
    //Read and forget all the informations off the erased student

    while (feof(openFile)==0) {
        //Copy the rest of the file
        lastChar = fgetc(openFile);
        if (feof(openFile) == 0) {
            fprintf(transFile, "%c", lastChar);
        }
    }
    //transFile now contains the new file with updated informations
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
{/*Write a student at the end of the file, takes the pointer as argument*/

    int nbrStudent = 0;

    FILE* openFile = fopen("student-list.txt", "r");
    fscanf(openFile, "%d", &nbrStudent);
    fclose(openFile);

    openFile = fopen("student-list.txt", "r+");
    fprintf(openFile, "%d", nbrStudent+1);
    fclose(openFile);

    openFile = fopen("student-list.txt", "a");
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

void init_followers(){
    FILE* fptr = fopen("follows.txt", "r");
    if (fptr){
        int i, k, j = 2;
        char studName[50];
        char followName[50];
        char c;
        fscanf(fptr, "%d", &i);
        getc(fptr); getc(fptr);
        while (!feof(fptr) && j < i+2){
            k = 0;
            while ((c = fgetc(fptr)) != '>'){
                studName[k] = c;
                k++;
            }
            studName[k] = '\0';
            k = 0;
            while ((c = fgetc(fptr)) != '\n'){
                followName[k] = c;
                k++;
            }
            followName[k] = '\0';
            Student* stud = find_student(studName);
            Student* follow = find_student(followName);
            if (stud != NULL && follow != NULL){
                add_follow(stud, follow);
            }
            j++;
        }
    fclose(fptr);
    } else {
        printf("This file does not exist\n");
    }
}

void save_file(){
    FILE* fptr = fopen("follows.txt", "w");
    Student* sptr;
    int linkCount = 0;
    for (int i = 0; i < 27; i++){
        sptr = glossary[i].beginList;
        while (sptr != NULL){
            linkCount += sptr->follower.nbrFollower;
            sptr = sptr->nextAlphaStudent;
        }
    }
    fprintf(fptr, "%d\n", linkCount);
    fprintf(fptr, "\n");
    for (int i = 0; i < 27; i++){
        sptr = glossary[i].beginList;
        while (sptr != NULL){
            for (int j = 0; j < sptr->follower.nbrFollower; j++){
                fprintf("%s>%s\n", sptr->follower.listFollower[j]->name);
            }
            sptr = sptr->nextAlphaStudent;
        }
    }
    fclose(fptr);
}


/*
else {
                fremove_line(fptr, j);
            }


void fremove_line(FILE* fptr, int line){
    FILE* transFile = fopen("tran.txt", "w");
    fseek(fptr, 0, SEEK_SET);
    int i = 0;
    char c;
    while (i < line && !feof(fptr)){
        while ((c = fgetc(fptr)) != '\n'){
            fprintf(transFile, "%c", c);
        }
        fprintf(transFile, "%c", c);
        i++;
    }
    while ((c = fgetc(fptr)) != '\n' && !feof(fptr)){
    }
    while ((c = fgetc(fptr)) != EOF){
        //c = fgetc(fptr);
        fprintf(transFile, "%c", c);
    }
    fseek(transFile, 0, SEEK_SET);
    fseek(fptr, 0, SEEK_SET);
    while (!feof(transFile)){
        c = fgetc(transFile);
        fprintf(fptr, "%c", c);
    }
    fclose(transFile);
    remove("tran.txt");
}


if (fileptr){
            int nbrFollow;
            fscanf(fileptr, "%d", &nbrFollow);
            int found = 0;
            int j = 2, k;
            char lastCharacter;
            char studName[50];
            char followName[50];
            getc(fileptr); getc(fileptr);
            while (found == 0 && j < nbrFollow && !feof(fileptr)){
                k = 0;
                while ((lastCharacter = getc(fileptr)) != '>'){
                    studName[k] = lastCharacter;
                    k++;
                }
                studName[k] = '\0';
                k = 0;
                while ((lastCharacter = getc(fileptr)) != '\n'){
                    followName[k] = lastCharacter;
                    k++;
                }
                followName[k] = '\0';
                if (compare_strings(stud->name, studName) == 0 && compare_strings(follow->name, followName) == 0){
                    found = 1;
                    fremove_line(fileptr, j);
                } else {
                    j++;
                }
            }
            printf("This student got removed from your follows\n");
            fclose(fileptr);
        } else {
            printf("This file does not exist\n");
        }
*/
