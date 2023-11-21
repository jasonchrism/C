#include <stdio.h> 

int main(){ 

    int cases; 
    int stud;
    scanf("%d",&cases); 
    for (int i = 0; i < cases; i++){ 
        scanf("%d", &stud);
        int arr[stud] ={}; 
        int max = 0;
        for (int j = 0; j < stud; j++){ 
            scanf("%d", &arr[j]); 
            if (max < arr[j]){
                max = arr[j]; 
            }    
        }   

        int counter = 0;
        for(int i = 0; i< stud; i++){ 
            if (max == arr[i]){
                counter++;
            }
        }
        printf("Case #%d: %d\n",i + 1, counter); 
    }
}