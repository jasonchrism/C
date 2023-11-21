#include <stdio.h>
#include <string.h>

int input;

struct Applicants{
    char ID[10];
    char name[50];
    char major[50];
    double GPA;
    char position[30];
}data[500];

int find(char askPosition[], char askMajor[], double askGPA){
    int count = 0;
    for (int i = 0; i < input; i++){
        if (strcmp(askPosition, data[i].position) == 0 && strcmp(askMajor, data[i].major) == 0 && askGPA <= data[i].GPA)
        count++;
    }
    return count;
}

int main(){

    scanf("%d", &input);getchar();
    for (int i = 0; i < input; i++){
        scanf("%s", data[i].ID); getchar();
        scanf("%[^\n]", data[i].name); getchar();
        scanf("%s", data[i].major); getchar();
        scanf("%lf", &data[i].GPA); getchar();
        scanf("%s", data[i].position); getchar();
    }
    
    int ask;
    scanf("%d", &ask); getchar();
    for (int i = 0; i < ask; i++){
        char askPosition[50];
        char askMajor[50];
        double askGPA;
        scanf("%s %s %lf", askPosition, askMajor, &askGPA); getchar();
        printf("CASE#%d: %d", i + 1, find(askPosition, askMajor, askGPA));
    }

}