#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Rice{
	char custName[100];
	char riceName[100];
	char topName[100];
	int price;
	int quantity;
	int total;
}friedRice[100];

int orderCount = 0;
int money = 0;
int custCount = 0;

int partitionQuantity(int low, int high){
	int i = low - 1;
	int j = low;
	int pivot = friedRice[high].quantity;
	while (j < high){
		if (friedRice[j].quantity < pivot){
			i++;
			Rice temp = friedRice[j];
			friedRice[j] = friedRice[i];
			friedRice[i] = temp;
		}
		j++;
	}
	Rice temp = friedRice[high];
	friedRice[high] = friedRice[i+1];
	friedRice[i+1] = temp;
	return (i+1);
}

void quickSortQuantity(int low, int high){
	if (low < high){
		int pos = partitionQuantity(low, high);
		quickSortQuantity(low, pos - 1);
		quickSortQuantity(pos + 1, high);
	}
}

int partitionPrice(int low, int high){
	int i = low - 1;
	int j = low;
	int pivot = friedRice[high].price;
	while (j < high){
		if (friedRice[j].price < pivot){
			i++;
			Rice temp = friedRice[j];
			friedRice[j] = friedRice[i];
			friedRice[i] = temp;
		}
		j++;
	}
	Rice temp = friedRice[high];
	friedRice[high] = friedRice[i+1];
	friedRice[i+1] = temp;
	return (i+1);
}

void quickSortPrice(int low, int high){
	if (low < high){
		int pos = partitionPrice(low, high);
		quickSortPrice(low, pos - 1);
		quickSortPrice(pos + 1, high);
	}
}

int partitionCustName(int low, int high){
	int i = low - 1;
	int j = low;
	char pivotName[100];
	strcpy(pivotName, friedRice[high].custName);
	while (j < high){
		if (strcmp(friedRice[j].custName, pivotName) < 0){
			i++;
			Rice temp = friedRice[j];
			friedRice[j] = friedRice[i];
			friedRice[i] = temp;
		}
		j++;
	}
	Rice temp = friedRice[high];
	friedRice[high] = friedRice[i+1];
	friedRice[i+1] = temp;
	return (i+1);
}

void quickSortCustName(int low, int high){
	if (low < high){
		int pos = partitionCustName(low, high);
		quickSortCustName(low, pos - 1);
		quickSortCustName(pos + 1, high);
	}
}

void import(){
	FILE* fp = fopen("data.csv", "r");
	while (!feof(fp)){
		fscanf(fp, "%[^#]#%[^#]#%[^#]#%d#%d\n", friedRice[orderCount].custName, friedRice[orderCount].riceName, friedRice[orderCount].topName, &friedRice[orderCount].price, &friedRice[orderCount].quantity);
		friedRice[orderCount].total = friedRice[orderCount].price * friedRice[orderCount].quantity;
		orderCount++;
	}
	for (int i = 0; i < orderCount; i++){
		printf("%d. %s with %s\n", i + 1, friedRice[i].riceName, friedRice[i].topName);
		printf("Ordered by - %s with quantity of %d, price of %d with total of %d\n\n", friedRice[i].custName, friedRice[i].quantity, friedRice[i].price, friedRice[i].total);
	}
	fclose(fp);
}

void save(){
	FILE* fp = fopen("data.csv", "w");
	for (int i = 0; i < orderCount; i++){
		fprintf(fp,"%s#%s#%s#%d#%d\n", friedRice[i].custName, friedRice[i].riceName, friedRice[i].topName, friedRice[i].price, friedRice[i].quantity);
	}
	fclose(fp);
}

void insert(){
	char custNameTemp[100];
	int chooseRice, chooseTop, choosePrice, chooseQuantity; 
	do {
		printf("Insert customer name [3-50 characters] : ");
		scanf("%[^\n]", custNameTemp);
	} while (strlen(custNameTemp) < 1 || strlen(custNameTemp) > 50);
	
	do {
		puts("Choose fried rice :");
		puts("1. Vegetarian fried rice");
		puts("2. Pork fried rice");
		puts("3. Beef fried rice");
		puts("4. Chicken fried rice");
		printf("Choose fried rice [1-4] : ");
		scanf("%d", &chooseRice); getchar();
		if (chooseRice == 1) strcpy(friedRice[orderCount].riceName, "Vegetarian fried rice");
		if (chooseRice == 2) strcpy(friedRice[orderCount].riceName, "Pork fried rice");
		if (chooseRice == 3) strcpy(friedRice[orderCount].riceName, "Beef fried rice");
		if (chooseRice == 4) strcpy(friedRice[orderCount].riceName, "Chicken fried rice");
	} while (chooseRice < 1 || chooseRice > 4);
	
	do {
		puts("Choose topping :");
		puts("1. Omelette");
		puts("2. Mozarella");
		puts("3. Cheddar");
		printf("Choose topping [1-3] : ");
		scanf("%d", &chooseTop); getchar();
		if (chooseTop == 1) strcpy(friedRice[orderCount].topName, "Omelette");
		if (chooseTop == 2) strcpy(friedRice[orderCount].topName, "Mozarella");
		if (chooseTop == 3) strcpy(friedRice[orderCount].topName, "Cheddar");
	} while (chooseTop < 1 || chooseTop > 3);
	
	do {
		printf("Insert quantity of fried rice [1 - 10] : ");
		scanf("%d", &chooseQuantity); getchar();
	} while (chooseQuantity < 1 || chooseQuantity > 10);
	
	int len = strlen(custNameTemp);
	strcpy(friedRice[orderCount].custName, custNameTemp);
	friedRice[orderCount].quantity = chooseQuantity;
	srand(time(0));
	choosePrice = (rand()%len + 1) * 7000;
	friedRice[orderCount].price = choosePrice;
	friedRice[orderCount].total = choosePrice * friedRice[orderCount].quantity;
	money = money + friedRice[orderCount].total;
	orderCount++;
	custCount++;
}

void sortPrice(){
	quickSortPrice(0, orderCount - 1);
	for (int i = 0; i < orderCount; i++){
		printf("%d. %s with %s\n", i + 1, friedRice[i].riceName, friedRice[i].topName);
		printf("Ordered by - %s with quantity of %d, price of %d000 with total of %d\n\n", friedRice[i].custName, friedRice[i].quantity, friedRice[i].price, friedRice[i].total);
	}
}

void sortQty(){
	quickSortQuantity(0, orderCount - 1); 
	for (int i = 0; i < orderCount; i++){
		printf("%d. %s with %s\n", i + 1, friedRice[i].riceName, friedRice[i].topName);
		printf("Ordered by - %s with quantity of %d, price of %d000 with total of %d\n\n", friedRice[i].custName, friedRice[i].quantity, friedRice[i].price, friedRice[i].total);
	}
}

void sortCust(){
	quickSortCustName(0, orderCount - 1);
	for (int i = 0; i < orderCount; i++){
		printf("%d. %s with %s\n", i + 1, friedRice[i].riceName, friedRice[i].topName);
		printf("Ordered by - %s with quantity of %d, price of %d000 with total of %d\n\n", friedRice[i].custName, friedRice[i].quantity, friedRice[i].price, friedRice[i].total);
	}
}

void view(){
	if (orderCount == 0){
		printf("There are no data!\n");
	} else {	
		int inputSort;
		puts("1. Order by price");
		puts("2. Order by quantity");
		puts("3. Order by customer name");
		puts("4. Exit");
		printf("Choose > ");
		scanf("%d", &inputSort); getchar();
		if (inputSort == 1){
			sortPrice();
		} else if (inputSort == 2){
			sortQty();	
		} else if (inputSort == 3){
			sortCust();	
		} else {
			system("cls");
		}
	}
}

void make(){
	for (int i = 0; i < orderCount; i++){
		printf("%d. %s with %s\n", i + 1, friedRice[i].riceName, friedRice[i].topName);
		printf("Ordered by - %s with quantity of %d, price of %d000 with total of %d\n\n", friedRice[i].custName, friedRice[i].quantity, friedRice[i].price, friedRice[i].total);
	}
	int chooseDel;
	do {	
		printf("Choose id to delete [1 - %d] : ", orderCount);
		scanf("%d", &chooseDel); getchar();
	} while (chooseDel < 1 || chooseDel > orderCount + 1);
	for (int i = chooseDel - 1; i < orderCount; i++){
		strcpy(friedRice[i].custName, friedRice[i + 1].custName);
		strcpy(friedRice[i].riceName, friedRice[i + 1].riceName);
		strcpy(friedRice[i].topName, friedRice[i + 1].topName);
		friedRice[i].price = friedRice[i + 1].price;
		friedRice[i].quantity = friedRice[i + 1].quantity;
		friedRice[i].total = friedRice[i + 1].total;
	}
	orderCount--;
}

void menu(){
	int input;
	do {

		puts("Random Fried Rice Shop...");
		printf("Current money : %d\n", money);
		puts("1. Insert Order");
		puts("2. View Order");
		puts("3. Make Order");
		puts("4. Exit");
		printf("Choose > ");
		scanf("%d", &input); getchar();
		
		if (input == 1) insert();
		if (input == 2) view();
		if (input == 3) make();	
	} while (input != 4);
}

int main(){
	
	import();
	menu();
	save();
	
}
