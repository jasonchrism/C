#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

struct Shopai{
	char code[100];
	char name[100];
	char type[100];
	int price;
	int quantity;
}shopai[100];

int dataCount = 0;

char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
int randNum;

int part(int low, int high){
	int i = low - 1;
	int j = low;
	char pivot[100];
	strcpy(pivot, shopai[high].name);
	while (j < high){
		if (strcmp(shopai[j].name, pivot) > 0){
			i++;
			char temp[100];
			strcpy(temp, shopai[j].name);
			strcpy(shopai[j].name, shopai[i].name);
			strcpy(shopai[i].name, temp);
		}
		j++;
	}
	strcpy(shopai[j].name, shopai[i+1].name);
	strcpy(shopai[i+1].name, pivot);
	return (i+1);
}

void quickSortHouse(int low, int high){
	if (low < high){
		int pos = part(low, high);
		quickSortHouse(low, pos - 1);
		quickSortHouse(pos + 1, high);
	}
}

void typeHouse(){
	quickSortHouse(0,dataCount - 1);
	int check = 0;
	printf("========================================================================================\n");
	printf("| [No.]  Item-Code\tItem-Name\tItem-Type\tItem-Price\tItem-Quantity |\n");
	printf("========================================================================================\n");		
	for (int i = 0; i < dataCount; i++){
		if (strcmpi(shopai[i].type, "Households Appliances") == 0){
			printf("| [ %d.]  %s %15s %20s %10d %19d |\n", i + 1, shopai[i].code, shopai[i].name, shopai[i].type, shopai[i].price, shopai[i].quantity);
			check++;
		}
	}
	if (check == 0){
		printf("No data available\n");	
	}
	printf("========================================================================================\n");
}

void typeUtility(){
	quickSortHouse(0, dataCount - 1);
	int check = 0;
	printf("========================================================================================\n");
	printf("| [No.]  Item-Code\tItem-Name\tItem-Type\tItem-Price\tItem-Quantity |\n");
	printf("========================================================================================\n");		
	for (int i = 0; i < dataCount; i++){
		if (strcmpi(shopai[i].type, "Utility") == 0){
			printf("| [ %d.]  %s %15s %20s %10d %19d |\n", i + 1, shopai[i].code, shopai[i].name, shopai[i].type, shopai[i].price, shopai[i].quantity);
			check++;
		}
	}
	if (check == 0){
		printf("No data available\n");	
	}
	printf("========================================================================================\n");
}

void typeToys(){
	quickSortHouse(0, dataCount - 1);
	int check = 0;
	printf("========================================================================================\n");
	printf("| [No.]  Item-Code\tItem-Name\tItem-Type\tItem-Price\tItem-Quantity |\n");
	printf("========================================================================================\n");	
	for (int i = 0; i < dataCount; i++){
		if (strcmpi(shopai[i].type, "Toys") == 0){
		printf("| [ %d.]  %s %15s %20s %10d %19d |\n", i + 1, shopai[i].code, shopai[i].name, shopai[i].type, shopai[i].price, shopai[i].quantity);
			check++;
		}
	}
	if (check == 0){
		printf("No data available\n");	
	}
	printf("========================================================================================\n");
}

void all(){
	quickSortHouse(0, dataCount - 1);
	int check = 0;
	printf("========================================================================================\n");
	printf("| [No.]  Item-Code\tItem-Name\tItem-Type\tItem-Price\tItem-Quantity |\n");
	printf("========================================================================================\n");	
	for (int i = 0; i < dataCount; i++){
		printf("| [ %d.]  %s %15s %20s %10d %18d |\n", i + 1, shopai[i].code, shopai[i].name, shopai[i].type, shopai[i].price, shopai[i].quantity);
		check++;
	}
	if (check == 0){
		printf("No data available\n");	
	}
	printf("========================================================================================\n");
}

void importData(){
	FILE* fp = fopen("shopai.txt", "r");
	while (!feof(fp)){
		fscanf(fp, "%[^/]/%[^/]/%[^/]/%d/%d\n", shopai[dataCount].code, shopai[dataCount].name, shopai[dataCount].type, &shopai[dataCount].price, &shopai[dataCount].quantity);
		dataCount++;
	}
	fclose(fp);
	all();
}

void saveData(){
	FILE* fp = fopen("shopai.txt", "w");
	for (int i = 0; i < dataCount; i++){
		fprintf(fp, "%s/%s/%s/%d/%d\n", shopai[i].code, shopai[i].name, shopai[i].type, shopai[i].price, shopai[i].quantity);
	}
	fclose(fp);
}

void addItem(){
	int type;
	char typeTemp[100];
	char nameTemp[100];
	int priceTemp;
	int quantityTemp;
	do {
		puts("1. Households Appliances");
		puts("2. Utility");
		puts("3. Toys");
		printf("Which item type do you wanna add? [1-3] : ");
		scanf("%d", &type); getchar();
		if (type == 1){
			strcpy(typeTemp, "Households Appliances");
		} else if (type == 2){
			strcpy(typeTemp, "Utility");
		} else if (type == 3){
			strcpy(typeTemp, "Toys"); 
		}
	} while (type < 1 || type > 3);
	
	do {
		printf("Input item's name [5-20 characters] : ");
		scanf("%[^\n]", nameTemp); getchar();
		strupr(nameTemp);
	} while (strlen(nameTemp) < 5 || strlen(nameTemp) > 20);
	
	do {
		printf("Input item's price [15.000 - 300.000] : ");
		scanf("%d", &priceTemp); getchar();
	} while (priceTemp < 15000 || priceTemp > 300000);
	
	do {
		printf("Input item's quantity [must be more than 0] : ");
		scanf("%d", &quantityTemp); getchar();
	} while (quantityTemp < 1);
	
	strcpy(shopai[dataCount].type, typeTemp);
	strcpy(shopai[dataCount].name, nameTemp);
	shopai[dataCount].price = priceTemp;
	shopai[dataCount].quantity = quantityTemp;
	
	srand(time(0));
	sprintf(shopai[dataCount].code, "%c%c-%d%d%d-%c%c", toupper(nameTemp[0]), toupper(nameTemp[1]), rand()%10, rand()%10, rand()%10, alphabet[rand()%26], alphabet[rand()%26]);
	dataCount++;
	printf("Data Added Successfully!\n"); getchar();
	system("cls");
}

void viewItem(){
	int inputView;
	do {
		puts("1. HouseHold Appliances");
		puts("2. Utility");
		puts("3. Toys");
		puts("4. All");
		puts("5. Back");
		printf("Which menu do you want to see ? [1-5] : ");
		scanf("%d", &inputView); getchar();
		if (inputView == 1){
			typeHouse();
		} else if (inputView == 2){
			typeUtility();
		} else if (inputView == 3){
			typeToys();
		} else if (inputView == 4){
			all();
		}
	} while (inputView != 5);
}

void purchaseItem(){
	int chooseToBuy;
	all();
	printf("Input item's number to buy [1 - %d] : ", dataCount);
	scanf("%d", &chooseToBuy);
	for (int i = chooseToBuy-1; i < dataCount; i++){
		strcpy(shopai[i].code, shopai[i+1].code);
		strcpy(shopai[i].name, shopai[i+1].name);
		strcpy(shopai[i].type, shopai[i+1].type);
		shopai[i].price = shopai[i+1].price;
		shopai[i].quantity = shopai[i].quantity;
	}
	dataCount--;
	printf("This item is sold out!\n"); getchar();
	system("cls"); 
}

void menu(){
	int input;
	do {
		puts("Welcome to ShoPAI");
		puts("=================");
		puts("1. Add New Item");
		puts("2. View Items");
		puts("3. Purchase Items");
		puts("4. Exit");
		printf(">> ");
		scanf("%d", &input); getchar();
		if (input == 1) addItem();
		if (input == 2) viewItem();
		if (input == 3) purchaseItem();
	} while (input != 4);
}

int main(){
	
	importData();
	menu();
	saveData();
}
