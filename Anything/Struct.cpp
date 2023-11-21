#include <stdio.h>

struct student{
	char sCode[35]={};
	char sName[35]={};
	char sGen[35]={};
	char father[35]={};
	char mother[35]={};
	int sibling=0;
};

struct lecture{
	char lCode[35]={};
	char lName[35]={};
	char lGen[35]={};
	int jumlahMahasiswa=0;
	student m[105];
};

	lecture d[100];

int main ()
{
	int kasus;
	scanf ("%d", &kasus);
	for (int i=0; i<kasus;i++)
	{
		scanf ("%s", d[i].lCode); getchar();
		scanf ("%s", d[i].lName); getchar();
		scanf ("%s", d[i].lGen); getchar();
		scanf ("%d",&d[i].jumlahMahasiswa); getchar();
		for (int j=0;j<d[i].jumlahMahasiswa;j++)
		{
			scanf ("%s", d[i].m[j].sCode); getchar ();
			scanf ("%s", d[i].m[j].sName); getchar ();
			scanf ("%s", d[i].m[j].sGen); getchar ();
			scanf ("%s", d[i].m[j].father); getchar ();
			scanf ("%s", d[i].m[j].mother); getchar ();
			scanf ("%d", &d[i].m[j].sibling); getchar ();
		}
		
	}
	int lectureTaken;
	scanf ("%d", &lectureTaken);
	int lectureNumber=lectureTaken-1;
	printf ("Kode Dosen: %s\n", d[lectureNumber].lCode);
	printf ("Nama Dosen: %s\n", d[lectureNumber].lName);
	printf ("Gender Dosen: %s\n", d[lectureNumber].lGen);
	printf ("Jumlah Mahasiswa: %d\n", d[lectureNumber].jumlahMahasiswa);
	for (int i=0; i<d[lectureNumber].jumlahMahasiswa; i++)
	{
		printf ("Kode Mahasiswa: %s\n", d[lectureNumber].m[i].sCode);
		printf ("Nama Mahasiswa: %s\n", d[lectureNumber].m[i].sName);
		printf ("Gender Mahasiswa: %s\n", d[lectureNumber].m[i].sGen);
		printf ("Nama Ayah: %s\n", d[lectureNumber].m[i].father);
		printf ("Nama Ibu: %s\n", d[lectureNumber].m[i].mother);
		printf ("Jumlah Saudara Kandung: %d\n", d[lectureNumber].m[i].sibling);
	}
	return 0;
}