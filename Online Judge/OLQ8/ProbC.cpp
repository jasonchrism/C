#include <stdio.h>

    int cases;
    char codeDos[100][100][40];
    char nameDos[100][100][40];
    char genderDos[100][100][40];
    char countMhs[100];

    char codeMhs[100][100][40];
    char nameMhs[100][100][40];
    char genderMhs[100][100][40];
    char dad[100][100][40];
    char mom[100][100][40];
    int siblings[100][100];
    int index;

int main(){

    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%s %s %s %d", codeDos[i], nameDos[i], genderDos[i], &countMhs[i]);
        for (int j = 0; j < countMhs[i]; j++){
            scanf("%s %s %s %s %s %d", codeMhs[i][j], nameMhs[i][j], genderMhs[i][j], dad[i][j], mom[i][j], &siblings[i][j]);
        }
    }
    scanf("%d", &index);
    int res = index - 1;
    printf("Kode Dosen: %s\n", codeDos[res]);
    printf("Nama Dosen: %s\n", nameDos[res]);
    printf("Gender Dosen: %s\n", genderDos[res]);
    printf("Jumlah Mahasiswa: %d\n", countMhs[res]);
    for (int j = 0; j < countMhs[res]; j++){
        printf("Kode Mahasiswa: %s\n", codeMhs[res][j]);
        printf("Nama Mahasiswa: %s\n", nameMhs[res][j]);
        printf("Gender Mahasiswa: %s\n", genderMhs[res][j]);
        printf("Nama Ayah: %s\n", dad[res][j]);
        printf("Nama Ibu: %s\n", mom[res][j]);
        printf("Jumlah Saudara Kandung: %d\n", siblings[res][j]);
    }

}