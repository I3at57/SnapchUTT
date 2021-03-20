#ifndef STUDENTS_FONC_H_INCLUDED
#define STUDENTS_FONC_H_INCLUDED

#include "CONST.h"
#include "STUDENTS_LIST"

int compare_strings(char *str1, char *str2){
    int k = 1;
    while (str1[k] == str2[k] && str1[k] != '\0' && str2[k] != '\0'){
        k++;
    }
    if (str1[k] < str2[k] || (str1[k] == '\0' && str2[k] != '\0')){
        return -1;
    } else if (str1[k] > str2[k] || (str1[k] != '\0' && str2[k] == '\0')){
        return 1;
    } else {
        return 0;
    }
}

int add_student(student *stud){
    student *travelPtr;
    char readChar = *stud.name[0];
    int i = 0;
    while (readChar != Glossary[i].letter && i < 27){
        i++;
    }
    if (readChar == Glossary[i].letter){
        if (Glossary[i].beginList == NULL){
            (*stud).nextAlphaStudent = NULL;
            Glossary[i].beginList = stud;
            return 0;
        } else {
            travelPtr = Glossary[i].beginList;
            int compare = compareStrings(*stud.name, *travelPtr.name)
            if (compare == -1 && compare == 0){
                (*stud).nextAlphaStudent = Glossary[i].beginList;
                Glossary[i].beginList = stud; // necessary step because Glossary[i].beginList is not a Student element
                return 0;
            } else {
                while ((*travelPtr).nextStudentAlpha != NULL){
                    Student nextElement = (*travelPtr).nextStudentAlpha
                    int compare = compareStrings(*stud.name, nextElement.name)
                    if (compare == -1 && compare == 0){
                        (*stud).nextAlphaStudent = (*travelPtr).nextStudentAlpha;
                        (*travelPtr).nextAlphaElement = stud;
                        return 0;
                    } else {
                        travelPtr = (*travelPtr).nextStudentAlpha;
                    }
                }
                if ((*travelPtr).nextStudentAlpha == NULL) {
                    (*stud).nextAlphaStudent = NULL;
                    (*travelPtr).nextStudentAlpha = stud;
                    return 0;
                }
            }
        }
    }
}

int init_glossary(){

}

#endif // STUDENTS_FONC_H_INCLUDED
