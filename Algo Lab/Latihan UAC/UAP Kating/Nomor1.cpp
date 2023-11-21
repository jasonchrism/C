#include <stdio.h>
#include <string.h>

long long int dataCount = 0;

struct Data{
	char ID[255];
	char name[255];
	char major[255];
	double GPA;
	char position[255];
}data[100];


int partition(int low, int high){
	int i = low - 1;
	int j = low;
//	Data pivot[100];
	double pivot = data[high].GPA;
	while (j < high){
		if (data[j].GPA < pivot){
			i++;
			Data temp = data[j];
			data[j] = data[i];
			data[i] = temp; 
		}
		j++;
	}
	Data temp = data[i+1];
	data[i+1] = data[j];
	data[j] = temp;
	return(i+1);
}

void quickSort(int low, int high){
	if (low < high){
		int pos = partition(low, high);
		quickSort(low, pos-1);
		quickSort(pos + 1, high);
	}
}

int main(){
	FILE* fp = fopen("NOMOR1.txt", "r");
	while (!feof(fp)){
		fscanf(fp, "%[^#]#%[^#]#%[^#]#%lf#%[^\n]\n", data[dataCount].ID, data[dataCount].name, data[dataCount].major, &data[dataCount].GPA, data[dataCount].position);
		dataCount++;
	}
	
	char request[100] = {};
	scanf("%[^\n]", request); getchar();
	quickSort(0, dataCount - 1);
	for (int i = 0; i < dataCount; i++){
		if (strcmp(data[i].position, request) == 0){
			printf("%s %s %s %lf %s\n", data[dataCount].ID, data[dataCount].name, data[dataCount].major, &data[dataCount].GPA, data[dataCount].position);
		}
	}
}

