#include <stdio.h>

int main(){

    int cases;
    int N;
    int blocks[100];
    int perimeter = 0;
    int area = 0;
    int resarea = 0;
    int resperimeter = 0;
    int temp;
    int diff = 0;
    FILE *filePointer;
    filePointer = fopen("testdata.in", "r");
    fscanf(filePointer, "%d", &cases);
    
    for (int k = 0; k < cases; k++){
    fscanf(filePointer, "%d", &N);
        resperimeter = 0;
        resarea = 0;
        diff = 0;
        temp = 0;
        area = 0;
        perimeter = 0;
        for (int i = 0; i < N; i++){
            fscanf(filePointer, "%d", &blocks[i]);
        }
        resperimeter = 4 * N;
        temp = 2 * blocks[0] + 2 * blocks[N-1];
        resperimeter = resperimeter + temp;
        for (int i = 0; i < N-1; i++){
            if (blocks[i] > blocks[i+1]){
                diff = blocks[i] - blocks[i+1];
                resperimeter = resperimeter + 2 * diff;
            } else if (blocks[i] < blocks[i+1]){
                diff = blocks[i+1] - blocks[i];
                resperimeter = resperimeter + 2 * diff;
            } else if (blocks[i] == blocks[i+1]){}
            diff = 0;
        }

        for (int i = 0; i < N; i++){
            area = blocks[i] * 4;
            resarea = resarea + area;
        }
        printf("Case #%d: %d %d\n", k + 1, resperimeter, resarea);

    }
    fclose(filePointer);

}