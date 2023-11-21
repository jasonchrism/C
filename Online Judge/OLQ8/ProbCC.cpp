#include <stdio.h>
#include <string.h>

int main(){

    int index = 0;
    int cases;
    char codeDos[100];
    char nameDos[100];
    char genderDos[100];
    int countMhs;
    char codeDoss[100][100];
    char nameDoss[100][100];
    char genderDoss[100][100];
    int countMhss[100];

    char codeMhs[100];
    char nameMhs[100];
    char genderMhs[100];
    char dadName[100];
    char momName[100];
    int siblings;
    char codeMhss[100][100];
    char nameMhss[100][100];
    char genderMhss[100][100];
    char dadNames[100][100];
    char momNames[100][100];
    int siblingss[100];
    
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%s", codeDos);
        scanf("%s", nameDos); getchar();
        scanf("%s", genderDos); getchar();
        scanf("%d", &countMhs);

        strcpy(codeDoss[i], codeDos);
        strcpy(nameDoss[i], nameDos);
        strcpy(genderDoss[i], genderDos);
        countMhss[i] = countMhs;
        index++;

        for (int j = 0; j < countMhs; j++){
            scanf("%s", codeMhs); 
            scanf("%s", nameMhs); getchar();
            scanf("%s", genderMhs); getchar();
            scanf("%s", dadName); getchar();
            scanf("%s", momName); getchar();
            scanf("%d", &siblings);

            strcpy(codeMhss[j], codeMhs);
            strcpy(nameMhss[j], nameMhs);
            strcpy(genderMhss[j], genderMhs);
            strcpy(dadNames[j], dadName);
            strcpy(momNames[j], momName);
            siblingss[j] = siblings;
        }
    }
        int result;
        scanf("%d", &result);
        for (int j = result-1; j < index; j++){
            printf("Kode Dosen: %s\n", codeDoss[j]);
            printf("Nama Dosen: %s\n", nameDoss[j]);
            printf("Gender Dosen: %s\n", genderDoss[j]);
            printf("Jumlah Mahasiswa: %d\n", countMhss[j]);
            for (int k = 0; k < countMhss[j]; k++){
                printf("Kode Mahasiswa: %s\n", codeMhss[k]);
                printf("Nama Mahasiswa: %s\n", nameMhss[k]);
                printf("Gender Mahasiswa: %s\n", genderMhss[k]);
                printf("Nama Ayah: %s\n", dadNames[k]);
                printf("Nama Ibu: %s\n", momNames[k]);
                printf("Jumlah Saudara Kandung: %d\n", siblingss[k]);
            }
        }

}