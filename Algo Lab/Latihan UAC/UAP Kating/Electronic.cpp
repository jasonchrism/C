#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Electronic{
	char elecName[100];
	char elecType[100];
	long long int elecPrice;
	int elecStock;
	int elecSpace;
}electro[100];

int electroCount = 0;
int electroSpace = 150;
long long int maxSmall = 200000;
long long int maxMedium = 1500000;
long long int maxBig = 10000000;

int searchExistName(char nameExist[]){
	if (electroCount == 0){
		return -1;
	}
	int left = 0;
	int right = electroCount - 1;
	int mid;
	while (left <= right){
		mid = (left + right) / 2;
		if (strcmp(electro[mid].elecName, nameExist) == 0){
			return mid;
		} else if (strcmp(electro[mid].elecName, nameExist) > 0){
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

int searchName(char name[]){
	int left = 0;
	int right = electroCount - 1;
	int mid;
	while (left <= right){
		mid = (left + right) / 2;
		if (strcmp(electro[mid].elecName, name) == 0){
			return 1;
		} else if (strcmp(electro[mid].elecName, name) > 0){
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

int searchNameSell(char nameSell[]){
	int left = 0;
	int right = electroCount - 1;
	int mid;
	while (left < right){
		mid = (left + right) / 2;
		if (strcmp(electro[mid].elecName, nameSell) == 0){
			return mid;
		} else if (strcmp(electro[mid].elecName, nameSell) > 0){
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
	char pivot[100];
	strcpy(pivot, electro[high].elecName);
	while (j < high){
		if (strcmp(electro[j].elecName, pivot) < 0){
			i++;
			Electronic temp = electro[j];
			electro[j] = electro[i];
			electro[i] = temp;
		}
		j++;
	}
	Electronic temp = electro[i+1];
	electro[i+1] = electro[high];
	electro[high] = temp;
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
	double percentage;
	for (int i = 0; i < electroCount; i++){
		if (strcmp(electro[i].elecType, "Medium") == 0){
		percentage = percentage + electro[i].elecStock * 2;
		} else if (strcmp(electro[i].elecType, "Big") == 0){
			percentage = percentage + electro[i].elecStock * 4;
		} else {
			percentage = percentage + electro[i].elecStock;
		}
	}
	printf("=========================================================================\n");
	printf("| Electronic Name \t   | Electronic Type \t | Price \t| Stock |\n");
	printf("=========================================================================\n");
	for (int i = 0; i < electroCount; i++){
		printf("| %-25s| %-20s| Rp.%-10lld| %5d |\n", electro[i].elecName, electro[i].elecType, electro[i].elecPrice, electro[i].elecStock);
	}
	double percen = (double)150 - ((double)150 / (double)percentage) * 10;
	printf("=========================================================================\n");
	printf("| Used Capacity Percentage \t\t\t\t\t| %.1lf |\n", percen);
	printf("=========================================================================\n");
	printf("Press Enter to Continue...\n"); getchar();
}

void importData(){
	char nameImport[100];
	char typeImport[100];
	int stockImport;
	long long int priceImport;
	FILE* fp = fopen("electronics.txt", "r");
	while (!feof(fp)){
		fscanf(fp, "%[^#]#%[^#]#%lld#%d\n", nameImport, typeImport, &priceImport, &stockImport);
		strcpy(electro[electroCount].elecName, nameImport);
		strcpy(electro[electroCount].elecType, typeImport);
		electro[electroCount].elecPrice = priceImport;
		electro[electroCount].elecStock = stockImport;
		electroCount++;
	}
	fclose(fp);
	view();
}

void insertExist(){
	view();
	char nameExist[100];
	int searchExist;
	int stockExist;
	int availSpaceExist;
	do {	
		printf("Input Electronic Name you want to add stock [Input \"back\" to back]: ");
		scanf("%[^\n]", nameExist); getchar();
		if (strcmp(nameExist, "back") == 0){
			break;
		}
		searchExist = searchExistName(nameExist);
		if (searchExist == -1){
			printf("Please input existing Electronic Name!\n");
		}
	} while (searchExist == -1);
	
	int temp;
	searchExist = searchExistName(nameExist);
	if (strcmp(electro[searchExist].elecType, "Small") == 0){
		temp = 1;
	} else if (strcmp(electro[searchExist].elecType, "Medium") == 0){
		temp = 2;
	} else if (strcmp(electro[searchExist].elecType, "Big") == 0){
		temp = 4;
	}

	do {
		printf("Input how many stock you want to add: ");
		scanf("%d", &stockExist); getchar();
		availSpaceExist = stockExist * temp;
		if (availSpaceExist > electroSpace){
			printf("Input stock is more than available capacity [%d spaces]!");
		}
	} while (availSpaceExist > electroSpace);
	printf("Sucessfully add stock");
	
	electro[searchExist].elecStock = electro[searchExist].elecStock + stockExist;
	
}

void insertNew(){
	char name[100] = {};
	char type[100] = {};
	int price;
	int stock;
	int searchUnique;
	do {
		printf("Input Item Name [5-25 Characters | Unique]: ");
		scanf("%[^\n]", name); getchar();
		searchUnique = searchName(name);
	} while (searchUnique == 1 || strlen(name) < 5 || strlen(name) > 25);
	
	int check = 0;
	do {
		printf("Input Item Type [Small | Medium | Big]: ");
		scanf("%s", type); getchar();
		if (strcmp(type, "Small") == 0){
			check = 1;
		} else if (strcmp(type, "Medium") == 0){
			check = 1;
		} else if (strcmp(type, "Big") == 0){
			check = 1;
		}
	} while (check == 0);

	if (strcmp(type, "Small") == 0){
		do {		
			printf("Input Item Price [Max %lld]: ", maxSmall);
			scanf("%lld", &price); getchar();
		} while (price > maxSmall);
	} else if (strcmp(type, "Medium") == 0){
		do {
			printf("Input Item Price [Max %lld]: ", maxMedium);
			scanf("%lld", &price); getchar();
		} while (price > maxMedium);
	} else if (strcmp(type, "Big") == 0){
		do {
			printf("Input Item Price [Max %lld]: ", maxBig);
			scanf("%lld", &price); getchar();
		} while (price > maxBig);
	}
	
	int availSpace = 0;
	do {
		printf("Input Item Stock [more than 0]: ");
		scanf("%d", &stock); getchar();
		if (strcmp(type, "Small") == 0){
			availSpace = stock * 1;
		} else if (strcmp(type, "Medium") == 0){
			availSpace = stock * 2;
		} else if (strcmp(type, "Big") == 0){
			availSpace = stock * 4;
		}
		if (availSpace > electroSpace){
			printf("Input stock is more thhan available capacity [%d spaces]!\n", electroSpace);
		}
	} while (availSpace > electroSpace);
	
	printf("Successfully inserted new item!\n");
	
	strcpy(electro[electroCount].elecName, name);
	strcpy(electro[electroCount].elecType, type);
	electro[electroCount].elecPrice = price;
	electro[electroCount].elecStock = stock;
	electro[electroCount].elecSpace = availSpace;
	electroCount++;
	electroSpace = electroSpace - availSpace;
	
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
		if (inputInsert == 2) insertExist();
	} while (inputInsert != 0);
	
}

void sell(){
	view();
	char nameSell[100];
	int searchSell = 0;
	int sellStock;
	int cek;
	do {
		printf("Input Electronic Name you want to Sell [Input \"back\" to back]: ");
		scanf("%[^\n]", nameSell); getchar();
		if (strcmp(nameSell, "back") == 0){
//			cek = 1;
		} else {
			searchSell = searchName(nameSell);		
		}
	} while (searchSell == -1);
	
	searchSell = searchName(nameSell);
//	strcpy(electro[searchSell].elecName, nameSell);
	if(strcmp(nameSell,"back") != 0)
	{
		do {
		printf("Input item quantity you want to sell [1-%d]: ", electro[searchSell].elecStock);
		scanf("%d", &sellStock); getchar();
	} while (sellStock > electro[searchSell].elecStock);
	electro[searchSell].elecStock -= sellStock;
	
	if (strcmp(electro[searchSell].elecType, "Small") == 0){
		electroSpace = electroSpace - (sellStock * 1);
	} else if (strcmp(electro[searchSell].elecType, "Medium") == 0){
		electroSpace = electroSpace - (sellStock * 2);
	} else if (strcmp(electro[searchSell].elecType, "Big") == 0){
		electroSpace = electroSpace - (sellStock * 4);
	}
	printf("\n");
	printf("Successfully sold item!\n");
	printf("=======================\n");
	printf("Transaction Details\n");
	printf("=======================\n");
	printf("Electronic Name: %s\n", nameSell);
	printf("Electronic Type: %s\n", electro[searchSell].elecType);
	printf("Quantity: %d\n", sellStock);
	long long int totalPrice = 0;
	totalPrice = sellStock * electro[searchSell].elecPrice;
	printf("Total Price: %lld\n", totalPrice);
	printf("Press enter to continue...\n"); getchar();
	
	for (int i = searchSell-1; i < electroCount; i++){
		electro[i] = electro[i+1];
	}
	electroCount--;	
	}
	
	
	
}

void menu(){
	int input;
	do {
	system("cls");
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
	
	importData();
	menu();
	
}
