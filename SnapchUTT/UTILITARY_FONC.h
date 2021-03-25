#ifndef UTILITARY_FONC_H_INCLUDED
#define UTILITARY_FONC_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

int compare_strings(char *str1, char *str2){
    /**/
    int k = 1;
    while (str1[k] == str2[k] && str1[k] != '\0' && str2[k] != '\0'){
        k++;
    }
    if (str1[k] < str2[k] || (str1[k] == '\0' && str2[k] != '\0')){
        return -1; // str1 comes before str2
    } else if (str1[k] > str2[k] || (str1[k] != '\0' && str2[k] == '\0')){
        return 1; // str1 comes after str2
    } else {
        return 0; // str1 is equal to str2
    }
}

int copy_array_char(char *targetArray, char *contentArray, int lth1, int lth2){
    if (lth2>lth1){
        return(1);
    }
    else {
        int i = 0;
        char lastChar;
        do {
            lastChar = contentArray[i];
            targetArray[i] = lastChar;
            i++;
        } while (lastChar != '\0');
    }
}

#endif // UTILITARY_FONC_H_INCLUDED
