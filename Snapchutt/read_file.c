#include <stdio.h>
#include <stdlib.h>
#include "FUNCTIONS.h"

/*******************************************************************************
All the functions related to reading and writing in the files.
*******************************************************************************/


/*The init_glossary function reads the student-list.txt file,
creates every student, adds them to the glossary*/
void init_glossary()
{
    FILE *fileptr = fopen("student-list.txt", "r"); //Open the file
    if (fileptr) {
        char singleLine[100];
        char lastChar;
        int nbrStudent = 0, j;
        fscanf(fileptr, "%d", &nbrStudent); //Read the number of students
        fgetc(fileptr); fgetc(fileptr); //Read two '\n'

        for (int i=0; i<nbrStudent; i++) {
            /*
            Every student has the same structure in the file :

            *
            <Name>
            <Age>
            <Year of studies>
            <Field of studies>
            <City of residence>
            <Hobby 1>
            <Hobby 2>
            <Hobby 3>
            *

            We also know that there is 2*'nbrStudent' stars '*' in the file
            */
            fgetc(fileptr);fgetc(fileptr);  //Read the '*' and a '\n'
            Student *stud = (Student*)malloc(sizeof(Student));

            //All the pointers take NULL value to avoid bugs
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

            add_student(stud); //Add the student in the glossary
        }
    }
    fclose(fileptr);
}


/*The researching_student function takes a student pointer as argument,
finds its position in the student-list.txt file and returns it*/
int researching_student(Student* target)
{
    char lastChar;
    int nbrStudent=0, compt=0, find=0, i=0;
    FILE* ptrFile = fopen("student-list.txt", "r");

    fscanf(ptrFile, "%d", &nbrStudent);
    fgetc(ptrFile); fgetc(ptrFile); //Read two '\n' and a '*'

    do {
        fgetc(ptrFile); fgetc(ptrFile); //Read '*' and '\n'
        i = 0;
        if (fgetc(ptrFile) == target->name[i]) {
            do {
                i++;
                lastChar = fgetc(ptrFile);
            } while (lastChar == target->name[i] || lastChar != '\n');
            /*
            The loop breaks if one letter is different, so it's not the right
            right student or if the lastChar is '\n' then we find the right
            student to delete
            */
            if (lastChar == '\n') {
                find = 1; //We have found the good one
            }
        } else {
            /*
            This student cannot be the good one so we read every character until
            we found the '*' which represents the end of this student
            in the file
            */
            do {
                lastChar = fgetc(ptrFile);
            } while (lastChar != '*');
            fgetc(ptrFile); //Read '\n'
            //The variable find stays at value 0.
        }
        compt++;  //We had read the 'compt'th student
    } while (find == 0 && compt < nbrStudent);
    /*The loop end if :
        find == 1 -> we found the right student to delete in position compt
        compt == nbrStudent && find == 0 -> the searched student
        does not exist
    */
    if (compt == nbrStudent && find == 0) {
        return(0);
    } else {
        return(compt);
    }
    fclose(ptrFile);
}

/*******************************************************************************/

/*The errase_student function takes the position of a student in the file and erases it*/
void errase_student(int position)
{
    FILE* openFile = fopen("student-list.txt", "r"); //Student data-base file
    FILE* transFile = fopen("tran.txt", "w");
    //Create a file only used in this function

    int nbrStar = 0, nbrStudent = 0;
    char lastChar;

    fscanf(openFile, "%d", &nbrStudent); //Read the number of students
    fprintf(transFile, "%d", nbrStudent-1); //Copy it on the temporary file

    do {
        /*
        Every student comes with two stars '*' to draw limit
        If I want to delete the student in position 5:
        I have to read 4 students e.i 8 stars '*'
        */
        lastChar = fgetc(openFile);
        fprintf(transFile, "%c", lastChar);
        if (lastChar == '*') {
            nbrStar++;
        }
    } while (nbrStar < (position-1)*2);
    fgetc(openFile); fgetc(openFile);
    //Read a '\n' and the 1st '*' of the erased student
    while (fgetc(openFile) != '*');
    //Read and forget all the informations about the erased student

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
    remove ("tran.txt"); //Delete the temporary file
}


/*The ecrire_student function takes the pointer of a student as argument
and writes the informations about this student at the end of the file*/
int ecrire_student(Student* stud)
{
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

void save_students(){
    int nbrStudent = 0;
    Student* ptr;
    for (int i = 0; i < 27; i++){
        ptr = glossary[i].beginList;
        while (ptr != NULL){
            nbrStudent++;
            ptr = ptr->nextAlphaStudent;
        }
    }
    FILE* fptr = fopen("student-list.txt", "w");
    if (fptr){
        fprintf(fptr, "%d\n", nbrStudent);
        fprintf(fptr, "\n");
        for (int i = 0; i < 27; i++){
            ptr = glossary[i].beginList;
            while (glossary != NULL){
                fprintf(openFile, "*\n");
                fprintf(openFile, "%s\n", ptr->name);
                fprintf(openFile, "%d\n", ptr->age);
                fprintf(openFile, "%d\n", ptr->yearStudy);
                fprintf(openFile, "%s\n", ptr->fieldStudy);
                fprintf(openFile, "%s\n", ptr->cityResidence);
                fprintf(openFile, "%d\n", ptr->interest[0].nbr);
                fprintf(openFile, "%d\n", ptr->interest[1].nbr);
                fprintf(openFile, "%d\n", ptr->interest[2].nbr);
                fprintf(openFile, "*\n");
                ptr = ptr->nextAlphaStudent;
            }
        }
        fclose(fptr);
    }
}

/*******************************************************************************/

/*The init_followers function reads the follows.txt file and adds every follow
to the list of follow of each existing student*/
void init_followers()
{
    FILE* fptr = fopen("follows.txt", "r");
    if (fptr){
        int i, k, j = 2;
        char studName[50];
        char followName[50];
        char c;
        fscanf(fptr, "%d", &i); //Read the number of follow links in the file
        getc(fptr); getc(fptr); //Read two '\n'
        while (!feof(fptr) && j < i+2){
            k = 0;
            //Read the student
            while ((c = fgetc(fptr)) != '>'){
                studName[k] = c;
                k++;
            }
            studName[k] = '\0';
            k = 0;
            //Read the follow of the previous student
            while ((c = fgetc(fptr)) != '\n'){
                followName[k] = c;
                k++;
            }
            followName[k] = '\0';
            Student* stud = find_student(studName); //Find the pointer of the student
            Student* follow = find_student(followName); //Find the pointer of the follow
            if (stud != NULL && follow != NULL){
                add_follow(stud, follow);
                //Add the follow to the list of follows of the student if they both exist
            }
            j++;
        }
    fclose(fptr);
    } else {
        printf("This file does not exist\n");
    }
}


/*The save_follows function saves the updated follows.txt file
when the application is closed*/
void save_followers()
{
    FILE* fptr = fopen("follows.txt", "w");
    if (fptr){
        Student* sptr;
        int linkCount = 0;
        for (int i = 0; i < 27; i++){
            sptr = glossary[i].beginList;
            /*
            For each follow in every list of follows the number of links
            between all students is increased
            */
            while (sptr != NULL){
                linkCount += sptr->follower.nbrFollower;
                sptr = sptr->nextAlphaStudent;
            }
        }
        fprintf(fptr, "%d\n", linkCount); //Write the number of links between all students
        fprintf(fptr, "\n");
        for (int i = 0; i < 27; i++){
            sptr = glossary[i].beginList;
            //Write each link in the file
            while (sptr != NULL){
                for (int j = 0; j < sptr->follower.nbrFollower; j++){
                    fprintf(fptr, "%s>%s\n", sptr->name, sptr->follower.listFollower[j]->name);
                }
                sptr = sptr->nextAlphaStudent;
            }
        }
        fclose(fptr);
    }
}
