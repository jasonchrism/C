#include <stdio.h>

int main(){

    int cases;
    char name[100];
    int nim, age, pos, siblings, height, rek;
    char birth[100];
    char place[100];
    char almet[100];
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%s", name);
        scanf("%d", &nim);
        scanf("%d", &age);
        scanf("%d", &pos);
        scanf("%s", place); getchar();
        scanf("%s", birth); getchar();
        scanf("%[^\n]", almet); getchar();
        scanf("%d", &siblings);
        scanf("%d", &height);
        scanf("%d", &rek);

        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: %s\n", name);
        printf("NIM: %d\n", nim);
        printf("Umur: %d\n", age);
        printf("Kode Pos: %d\n", pos);
        printf("Tempat Lahir: %s\n", place);
        printf("Tanggal Lahir: %s\n", birth);
        printf("Almamater SMA: %s\n", almet);
        printf("Jumlah Saudara Kandung: %d\n", siblings);
        printf("Tinggi Badan: %d\n", height);
        printf("NOMOR REKENING: %d\n", rek);
    }



}