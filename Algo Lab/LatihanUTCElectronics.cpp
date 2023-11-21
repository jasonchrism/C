#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int input;
	int update;
	int sell;
	int index = 0;
	char itemID[50];
	char itemIDs[50][50];
	char itemName[50];
	char itemNames[50][50];
	float itemPrice;
	float itemPrices[50];
	
	do{
		puts("Electronics!");
		puts("============");
		puts("1. Insert Electronic Stock");
		puts("2. Update Electronic");
		puts("3. Sell Electronic");
		puts("4. Exit");
		printf(">> ");
		scanf("%d", &input); getchar();
		system("cls");
		
		int cek = 0;
		if (input == 1){
			do{
				printf("Input Item ID [must be numeric with exactly 3 digit]: ");
				scanf("%s", &itemID); getchar();
				for (int i = 0; i < strlen(itemID); i++){
					if (isdigit(itemID[i]) == 0){
						cek = 1;
					}
				}
			} while (strlen(itemID) != 3 || cek == 1);
			
			do{
				printf("Input Item Name [5-25 characters]: ");
				scanf("%[^\n]", itemName); getchar();
			} while (strlen(itemName) < 5 || strlen(itemName) > 25);
			
			do{
				printf("Input Item Price [not more than 5M]: ");
				scanf("%f", &itemPrice); getchar();
			} while (itemPrice > 5000000);
			
			strcpy(itemIDs[index], itemID);			
			strcpy(itemNames[index], itemName);
			itemPrices[index] = itemPrice;
			index++;
			
			printf("Item successfully inserted!\n");
			printf("Press enter to continue..."); getchar();
			system("cls");
		}
		
		if (input == 2){
			if (index == 0){
				printf("There is no item yet...\n");
				printf("Press enter to continue..."); getchar();
				system("cls");
			}
			
			if (index != 0){
				printf("=======================================================================\n");
				printf("|No. |ID\t |Name\t\t\t |Price\t\t\t |\n");
				printf("=======================================================================\n");
				for (int i = 0; i < index; i++){
				printf("|%d   |%-10s |%-23s|%2.f\t\t |\n", i + 1, itemIDs[i], itemNames[i], itemPrices[i]);
				}
				printf("=======================================================================\n");
				do{
					printf("Which item you want to update? [0 to exit] [1..%d]: ", index);
					scanf("%d", &update);					
					if (update == 0){
						break;
						system("cls");
					}
				} while (update > index || update < 0);
				
				if (update != 0){
					cek = 0;
					do{
					printf("Input Item ID [must be numeric with exactly 3 digit]: ");
					scanf("%s", &itemID); getchar();
					for (int i = 0; i < strlen(itemID); i++){
						if (isdigit(itemID[i]) == 0){
							cek = 1;
						}
					}
				} while (strlen(itemID) != 3 || cek == 1);
				
				do{
					printf("Input Item Name [5-25 characters]: ");
					scanf("%[^\n]", itemName); getchar();
				} while (strlen(itemName) < 5 || strlen(itemName) > 25);
				
				do{
					printf("Input Item Price [not more than 5M]: ");
					scanf("%f", &itemPrice); getchar();
				} while (itemPrice > 5000000);
				
				strcpy(itemIDs[update - 1], itemID);			
				strcpy(itemNames[update - 1], itemName);
				itemPrices[update - 1] = itemPrice;

				printf("Item successfully updated!\n");
				printf("Press enter to continue.."); getchar();
				system("cls");
				}
			}
			
		}
		
		if (input == 3){
			if (index == 0){
				printf("There is no item yet\n");
				printf("Press enter to continue..."); getchar();
				system("cls");
			}
			
			if (index != 0){
				printf("=======================================================================\n");
				printf("|No. |ID\t |Name\t\t\t |Price\t\t\t |\n");
				printf("=======================================================================\n");
				for (int i = 0; i < index; i++){
				printf("|%d |%s\t |%s\t\t\t |%2.f\t\t\t |\n", i + 1, itemIDs[i], itemNames[i], itemPrices[i]);
				}
				printf("=======================================================================\n");
				
				do{
					printf("Which item you want to sell? [0 to exit] [1..%d]: ", index);
					scanf("%d", &sell); getchar();
					if (sell == 0){
						break;
						system("cls");
					}
				} while (sell > index);
				
				srand(time(0));
				int disc = rand()%10;
				if (disc <= 3){
					if (sell == 0){
						break;
						system("cls");
					}
					printf("##########################\n");
					printf("Custtomer got discount 25%\n");
					printf("##########################\n");
					printf("\n");
				}
					int yes, no;
					char yn[5];
					if (sell == 0){
						break;
						system("cls");
					}
					printf("ETC%c Item Detail\n", itemIDs[sell-1]);
					printf("==================\n");
					printf("Item Name : %s\n", itemNames[sell-1]);
					printf("Item Price : %2.f\n", itemPrices[sell-1]);
				do{
					if (sell == 0){
						break;
						system("cls");
					}
					printf("Are you sure you want to sell this? [yes|no]: ");
					scanf("%s", yn);
					yes = strcmp("yes", yn);
					no = strcmp("no", yn);	
				} while (yes != 0 && no != 0);
				
				if (yes == 0){
					if (sell == 0){
						break;
						system("cls");
					}
					printf("Item successfully sold!\n");getchar();
					printf("Press enter to continue.."); getchar();
					system("cls");
					
					for (int m = sell-1; m < index - 1; m++){
						strcpy(itemIDs[m], itemIDs[m+1]);
						strcpy(itemNames[m], itemNames[m+1]);
						itemPrices[m] = itemPrices[m+1];
					}
					index--;
				} else if (no == 0){
					printf("Cancel selling!\n");
					printf("Press entr to continue..."); getchar();
					system("cls");
				}
			}
		}
		
	} while (input != 4);
	printf("Thank you for using this app!");
}

