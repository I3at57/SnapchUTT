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


/*The save_students function saves the updated student-list.txt file
when the application is closed*/
void save_students()
{
    FILE* fptr = fopen("student-list.txt", "w");
    if (fptr){
        int nbrStudent = 0;
        Student* ptr;
        /*Count every student in the database*/
        for (int i = 0; i < 27; i++){
            ptr = glossary[i].beginList;
            while (ptr != NULL){
                nbrStudent++;
                ptr = ptr->nextAlphaStudent;
            }
        }
        fprintf(fptr, "%d\n", nbrStudent); //Write the number of links between all students
        fprintf(fptr, "\n");
        for (int i = 0; i < 27; i++){
            ptr = glossary[i].beginList;
            while (ptr != NULL){
                //Write each student in the file
                fprintf(fptr, "*\n");
                fprintf(fptr, "%s\n", ptr->name);
                fprintf(fptr, "%d\n", ptr->age);
                fprintf(fptr, "%d\n", ptr->yearStudy);
                fprintf(fptr, "%s\n", ptr->fieldStudy);
                fprintf(fptr, "%s\n", ptr->cityResidence);
                fprintf(fptr, "%d\n", ptr->interest[0].nbr);
                fprintf(fptr, "%d\n", ptr->interest[1].nbr);
                fprintf(fptr, "%d\n", ptr->interest[2].nbr);
                fprintf(fptr, "*\n");
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
