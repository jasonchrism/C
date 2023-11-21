#include <stdio.h>

int rec(int value[], int tree){
    if (tree <= 0){
        return 0;
    }

    return (rec(value, tree - 1) + value[tree-1]);
}

int main(){

    int cases;
    scanf("%d", &cases);
    int tree;
    for (int i = 0; i < cases; i++){
        scanf("%d", &tree);
        int result = 0;
        int value[1000];
        for (int j = 0; j < tree; j++){
            scanf("%d", &value[j]);
        }
        printf("Case #%d: %d\n", i + 1, rec(value, tree));   
    }

}