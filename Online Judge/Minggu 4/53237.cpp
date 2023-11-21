#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

    char name[10001];

    scanf("%[^\n]", name);
    
    for (int i = 0; i < (strlen(name)); i++){
        name[i] = toupper(name[i]);

        if (name[i] == 'I'){
            name[i] = '1';
        } 

        if (name[i] == 'R'){
            name[i] = '2';
        } 

        if (name[i] == 'E'){
            name[i] = '3';
        } 

        if (name[i] == 'A'){
            name[i] = '4';
        } 

        if (name[i] == 'S'){
            name[i] = '5';
        } 

        if (name[i] == 'G'){
            name[i] = '6';
        } 

        if (name[i] == 'T'){
            name[i] = '7';
        } 

        if (name[i] == 'B'){
            name[i] = '8';
        } 

        if (name[i] == 'P'){
            name[i] = '9';
        } 

        if (name[i] == 'O'){
            name[i] = '0';
        } 
    }
        printf("%s\n", name);




}