#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Electronic{
	char name[255];
	char type[255];
	long long price;
	int stock;
}elec[100];

int electroCount = 0;
int space = 150;
int small = 1;
int medium = 2;
int big = 4;
double currentSpace = 0;
double percentage = 0;

int searchExist(char nameExist[]){
	if (electroCount == 0) return -1;
	int left = 0;
	int right = electroCount - 1;
	int mid;
	while (left <= right){
		mid = (left + right) / 2;
		if (strcmp(elec[mid].name, nameExist) == 0){
			return mid;
		} else if (strcmp(elec[mid].name, nameExist) > 0){
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;	
}

int searchSame(char nameTemp[]){
	if (electroCount == 0) return -1;
	int left = 0;
	int right = electroCount - 1;
	int mid;
	while (left <= right){
		mid = (left + right) / 2;
		if (strcmp(elec[mid].name, nameTemp) == 0){
			return mid;
		} else if (strcmp(elec[mid].name, nameTemp) > 0){
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

int searchSell(char nameSell[]){
	int left = 0;
	int right = electroCount - 1;
	int mid;
	while (left <= right){
		mid = (left + right) / 2;
		if (strcmp(elec[mid].name, nameSell) == 0){
			return mid;
		} else if (strcmp(elec[mid].name, nameSell) > 0){
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

int partition(int low, int high){
	int i = low - 1;
	int j = low;
	char pivot[255];
	strcpy(pivot, elec[high].name);
	while (j < high){
		if (strcmp(elec[j].name, pivot) < 0){
			i++;
			Electronic temp = elec[j];
			elec[j] = elec[i];
			elec[i] = temp;
		}
		j++;
	}
	Electronic temp = elec[i+1];
	elec[i+1] = elec[high];
	elec[high] = temp;
	return (i+1);
}

void quickSort(int low, int high){
	if (low < high){
		int pos = partition(low, high);
		quickSort(low, pos - 1);
		quickSort(pos + 1, high);
	}
}

void view(){
	quickSort(0, electroCount - 1);
	percentage = currentSpace/150*100;
	printf("===============================================================================\n");
	printf("| Electronic Name \t\t | Electronic Type \t | Price \t | Stock |\n");
	printf("===============================================================================\n");
	for (int i = 0; i < electroCount; i++){
		printf("| %-25s | %-15s | Rp.%lld | %6d |\n", elec[i].name, elec[i].type, elec[i].price, elec[i].stock);
	}
	printf("===============================================================================\n");
	printf("| Used Capacity Percentage                                        | %.1lf%% |\n", percentage);
	printf("===============================================================================\n");
	printf("Press enter to continue..."); getchar();
}

void addExist(){
	char nameExist[255];
	view();
	int cekExist;
	int stockExist;
	int spaceExist;
	do {
		printf("Input Electronic Name you want to add stock [Input \"back\" to back]: ");
		scanf("%[^\n]", nameExist); getchar();
		cekExist = searchExist(nameExist);
		if (cekExist == -1) printf("Please input existing Electronic Name!\n");
	} while (cekExist == -1);
	
	int cek;
	do {
		printf("Input how many stock you want to add: ");
		scanf("%d", &stockExist);
		if (strcmp(elec[cekExist].type, "Small") == 0){
			spaceExist = stockExist * 1;
		} else if (strcmp(elec[cekExist].type, "Medium") == 0){
			spaceExist = stockExist * 2;
		} else if (strcmp(elec[cekExist].type, "Big") == 0){
			spaceExist = stockExist * 4;
		}
		if (currentSpace + spaceExist > space){
			printf("Input stock is more than available capacity [%d spaces]!\n", space);
			cek = 1;
		} else {
			currentSpace = currentSpace + spaceExist;
		}
	} while (cek == 1);
	space = space - spaceExist;
	printf("Successfully add stock!\n");
	printf("Press enter to continue..."); getchar();
}

void insertNew(){
	char nameTemp[255];
	char typeTemp[255];
	long long priceTemp;
	int stockTemp;
	int checkName;
	int checkType = 0;
	int spaceTemp;
	do {
		printf("Input Item Name [5-25 characters | Unique]: ");
		scanf("%[^\n]", nameTemp); getchar();
//		checkName = searchSame(nameTemp);
	} while (strlen(nameTemp) < 5 || strlen(nameTemp) > 25);

	do {
		printf("Input Item Type [Small | Medium | Big]: ");
		scanf("%[^\n]", typeTemp); getchar();
		if (strcmp(typeTemp, "Small") == 0){
			checkType = 1;
		} else if (strcmp(typeTemp, "Medium") == 0){
			checkType = 1;
		} else if (strcmp(typeTemp, "Big") == 0){
			checkType = 1;
		}
	} while (checkType == 0);
	
		if (strcmp(typeTemp, "Small") == 0){
	do {
		printf("Input Item Price [Max 200000]: ");
		scanf("%lld", &priceTemp); getchar();
	} while (priceTemp > 200000);
		} else if (strcmp(typeTemp, "Medium") == 0){
			do {
				printf("Input Item Price [Max 1500000]: ");
				scanf("%lld", &priceTemp); getchar();			
			} while (priceTemp > 1500000);
		} else if (strcmp(typeTemp, "Big") == 0){
			do {
				printf("Input Item Price [Max 10000000]: ");
				scanf("%lld", &priceTemp); getchar();				
			} while (priceTemp > 10000000);
		}
	
	int cek;
	do {
		printf("Input Item Stock [more than 0]: ");
		scanf("%d", &stockTemp); getchar();
		if (strcmp(typeTemp, "Small") == 0){
			spaceTemp = stockTemp * 1;
		} else if (strcmp(typeTemp, "Medium") == 0){
			spaceTemp = stockTemp * 2;
		} else if (strcmp(typeTemp, "Big") == 0){
			spaceTemp = stockTemp * 4;
		}
		if (currentSpace + spaceTemp > space){
			printf("Input stock is more than available capacity [%d spaces]!\n", space);
			cek = 1;
		} else {
			currentSpace = currentSpace + spaceTemp;
		}
	} while (stockTemp < 1 || cek == 1);
	
	printf("Successfully inserted new item!\n");
	strcpy(elec[electroCount].name, nameTemp);
	strcpy(elec[electroCount].type, typeTemp);
	elec[electroCount].price = priceTemp;
	elec[electroCount].stock = stockTemp;
	electroCount++;
	space = space - spaceTemp;
}

void insert(){
	int inputInsert;
	do {
		puts("Select this two option");
		puts("1. Insert new item");
		puts("2. Add existing item stock");
		puts("0. Back");
		printf(">> ");
		scanf("%d", &inputInsert); getchar();
		if (inputInsert == 1) insertNew();
		if (inputInsert == 2) addExist();	
	} while (inputInsert != 0);
}

void sell(){
	view();
	char nameSell[255];
	int checkSell;
	int stockSell;
	do {
		printf("Input Electronic Name you want to sell [Input \"back\" to back]: ");
		scanf("%[^\n]", nameSell); getchar();
		if (strcmp(nameSell, "back") == 0){
			
		} else {
			checkSell = searchSell(nameSell);	
		}
	} while (checkSell == -1);
	
	if (strcmp(nameSell, "back") != 0){
		do {
			printf("Input item quantity you want to sell [1-%d]: ", elec[checkSell].stock);
			scanf("%d", &stockSell); getchar();
		} while (stockSell < 1 || stockSell > elec[checkSell].stock);
	}
	
	elec[checkSell].stock = elec[checkSell].stock - stockSell;
	if (strcmp(elec[checkSell].type, "Small") == 0){
		space = space + stockSell*1;
	} else if (strcmp(elec[checkSell].type, "Medium") == 0){
		space = space + stockSell*2;
	} else if (strcmp(elec[checkSell].type, "Big") == 0){
		space = space + stockSell*4;
	}
	
	long long totalPrice = elec[checkSell].price * stockSell;
	
	for (int i = checkSell-1; i < electroCount; i++){
		elec[i] = elec[i+1];
	}
	electroCount--;
	
	printf("Successfully sold item!\n");
	printf("=======================\n");
	printf("Transaction Details\n");
	printf("=======================\n");
	printf("Electronic Name: %s\n", nameSell);
	printf("Electronic Type: %s\n", elec[checkSell].type);
	printf("Quantity: %d\n", stockSell);
	printf("Total Price: %lld\n", totalPrice);
	printf("Press enter to continue..."); getchar();
	
}

void menu(){
	int input;
	do {
		puts("Electronics 2.0!");
		puts("================");
		puts("1. Insert Electronic Stock");
		puts("2. View Electronic List");
		puts("3. Sell Electronic");
		puts("4. Exit");
		printf(">> ");
		scanf("%d", &input); getchar();	
		if (input == 1) insert();
		if (input == 2) view();
		if (input == 3) sell();
	} while (input != 4);
}

int main(){
	menu();
}
