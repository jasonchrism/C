#include<stdio.h> 
#include<string.h> 


struct student{ 
    char name[100]; 
    int value[100]; 
    int count;
}; 

int  searching(student temp[],char student[], int left, int right){ 
    if(left >= right)return -1;
    int mid = left + (right - left)/2;

    if(strcmp(temp[mid].name, student) == 0){
        return mid; 
	} else if(strcmp(temp[mid].name, student) < 0){ 
        return searching(temp, student, mid+1, right); 
    } else {	
    return searching(temp,student,left,mid -1);
	}
}

int main(){ 
    int jumlah = 0;
    FILE* file; 
    file = fopen("testdata.in","r"); 
    fscanf(file,"%d\n",&jumlah); 
    student students[jumlah]; 

    for(int i = 0; i<jumlah; i++)
    {   
        fscanf(file,"%[^\n]\n",students[i].name); 
        fscanf(file,"%d\n", &students[i].count); 
        for(int j = 0; j<students[i].count; j++){
            fscanf(file,"%d",&students[i].value[j]); fgetc(file);
        }
    }
    int input = 0;
    fscanf(file,"%d\n",&input); 
    for(int i = 0; i<input; i++){ 
        char user[100] = {};
        fscanf(file,"%[^\n]\n",user); 

        int index = searching(students,user,0,jumlah); 
        if(index == -1){ 
            printf("Invalid Name\n"); 
        } else { 
            int i = students[index].count;
            int average = 0;
            for(int j = 0; j < i; j++){
                average += students[index].value[j];
            }
            average = average/students[index].count; 
            printf("%d\n",average); 
        }
    }
    fclose(file);
    
    return 0;
}
