#include <stdio.h>

int main (){
    
    int cases=0;
    scanf ("%d", &cases);
    for (int i = 1; i <= cases; i++){
        int N = 0, K = 0;
        scanf ("%d", &N);
        scanf ("%d", &K);
        double matriks[N][N] = {};
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                scanf ("%lf", &matriks [j][k]);
            }
        }

        int process = 0;
        process = N - K + 1;
        double hasil[process][process]={};
        //untuk perulangan sebanyak process
		for (int l = 0; l < process; l++){
        	for (int m = 0; m < process; m++){
        		//untuk penjumlahan
        		for (int n = l; n < (l + K); n++){
        			for (int o = m; o < (m + K); o++){        				
        				hasil[l][m] += matriks[n][o];
					}
				}
			}
		}
		
		//untuk print hasil
		for (int p = 0; p < process; p++){
			int spasi = 0;
			for (int q = 0; q < process; q++){
				printf ("%s%.2lf", spasi == 0 ? "" : " ", hasil[p][q] / (K*K));
				spasi++;
			}
			printf ("\n");
		}
    }
    return 0;
}