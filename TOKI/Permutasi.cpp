// #include <stdio.h>

// // int main(){
// //     long long int n;
// //     long long int p;
// //     long long int x1 = 1;
// //     long long int x2 = 1;
// //     long long int hasil = 0;

// //     printf("Masukan nilai n : ");
// //     scanf("%lld", &n);
// //     printf("Masukan nilai p : ");
// //     scanf("%lld", &p);
// //     for(int i = 1; i <= n; i++){
// //         x1 = x1 * i;
// //     }
// //     for(int i = 1; i <= n - p; i++){
// //         x2 = x2 * i;
// //     }

// //     //rumus permutasi
// //     hasil = x1 / x2;
// //     printf("Nilai Permutasi %d diambil %d adalah %d ", n, p, hasil);
    
// // }

// #include <stdio.h>
// #include <string.h>

// /* Function to swap values at two pointers */
// void swap(char* x, char* y)
// {
//     char temp;
//     temp = *x;
//     *x = *y;
//     *y = temp;
// }

// /* Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string. */
// void permute(char* a, int l, int r)
// {
//     int i;
//     if (l == r) {
//         printf("%s\n", a);
//     } else {
//         for (i = l; i <= r; i++) {
//             swap((a + l), (a + i));
//             permute(a, l + 1, r);
//             swap((a + l), (a + i)); // backtrack
//         }
//     }
// }

// /* Driver code */
// int main(){
//     char str[] = "ABC";
//     int n = strlen(str);
//     permute(str, 0, n - 1);
// }

#include <stdio.h>

int fact(int);


int fact(int n){
    int i, f = 1;
    // for(i = 1; i <= n; i++){
    //     f = f * i;
    // }
    // return f;
    if (i > n){
        return f;
    } else {
        f = f * i;
        return fact(i+1);
    }
}

int main(){
	int n, r, npr;
  	printf("Enter a number n\n");
  	scanf("%d", &n);
 	printf("Enter a number r\n");
  	scanf("%d", &r);
  	npr = fact(n) / fact(n-r);
    printf("Value of %dP%d = %d\n", n, r, npr);
}