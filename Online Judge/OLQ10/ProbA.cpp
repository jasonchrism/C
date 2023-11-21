#include <stdio.h>
#include <string.h>

int main(){

    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        int hour, minutes;
        char symbol;
        char time[10];
        scanf("%d%c%d %s", &hour, &symbol, &minutes, time); getchar();
        if (strcmp("am", time) == 0){
            if (hour >= 12){
                printf("Case #%d: %.2d%c%.2d\n", i + 1, hour-12, symbol, minutes);
            } else {
                printf("Case #%d: %.2d%c%.2d\n", i + 1, hour, symbol, minutes);
            }
        }

        if (strcmp("pm", time) == 0){
            if (hour < 12){
                printf("Case #%d: %.2d%c%.2d\n", i + 1, hour + 12, symbol, minutes);
            } else {
                printf("Case #%d: %.2d%c%.2d\n", i + 1, hour, symbol, minutes);
            }
        }
    }

}