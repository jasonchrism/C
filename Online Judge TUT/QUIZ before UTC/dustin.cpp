#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>

int main(){
	
	int input, cek;
	int index = 0;
	int ganti, jual;
	
	char itemID[50];
	char itemName[50];
	float itemPrice;
	
	char itemID_1[50][255];
	char itemName_1[50][255];
	float itemPrice1[50];
	
	do{
		printf("1. Insert Electronic Stock\n");
		printf("2. Update Electronic\n");
		printf("3. Sell Electronic\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d",&input); getchar();
		system("cls");
		
		if(input==1){
		
		do{
		cek = 0;
		printf("Input item Id [must be numeric with exactly 3 digit]: ");
		scanf("%s", &itemID); getchar();
		for(int i=0; i<strlen(itemID); i++){
			if(!isdigit(itemID[i])){
				cek = 1;
			}
		}
		}while(strlen(itemID) != 3 || cek == 1);
		
		do{
		printf("Input Item name [5-25 characters]: ");
		scanf("%[^\n]", itemName); getchar();
		}while(strlen(itemName) < 5 || strlen(itemName) > 25);
		
		do{
			printf("Input Item price [not more than 5M]: ");
			scanf("%f", &itemPrice);			
		}while (itemPrice>5000000);
		
		strcpy(itemID_1[index], itemID);
		strcpy(itemName_1[index], itemName);
		itemPrice1[index] = itemPrice;
		
		index++;
		
		printf("Item successfully inserted!\n");
		printf("Press enter to continue...\n");
		
		}
		
		if(input==2){
			
			if(index == 0){
				printf("There is no item yet...\n");
				printf("Press enter to continue...\n");
			}
			if(index != 0){
				printf("=========================================================================\n");
				printf("| No\t| Id\t\t| Name\t\t\t| Price\t\t\t|\n");
				printf("=========================================================================\n");
				for(int j=0; j<index; j++){
					printf("| %d\t| ETC%s\t| %s\t\t| Rp. %.2f\t\t|\n", j+1, itemID_1[j], itemName_1[j], itemPrice1[j]);	
				}
				printf("=========================================================================\n");
				
				do{
					printf("Which item you want to update? [0 to exit] [1..%d] ", index);
					scanf("%d", &ganti);
				} while (ganti>index || ganti < 0);
				
				if (ganti!= 0 && ganti <= index){
					do{
						cek = 0;
						printf("Input Item Id [must be numeric with exactly 3 digit]: ");
						scanf("%s", itemID); getchar();
						for(int i=0; i<strlen(itemID); i++){
							if(!isdigit(itemID[i])){
								cek = 1;
							}
						}
					} while(strlen(itemID) != 3 || cek ==1);
					
					do{
						printf("Input Item name [5-25 characters]: ");
						scanf("%[^\n]", itemName); getchar();
					}while (strlen(itemName) < 5 || strlen(itemName) > 25);
					
					do{
					printf("Input Item price [not more than 5M]: ");
					scanf("%f", &itemPrice);			
					}while (itemPrice>5000000);
					
					strcpy(itemID_1[ganti-1], itemID);
					strcpy(itemName_1[ganti-1], itemName);
					itemPrice1[ganti-1] = itemPrice;
									
					printf("Item successfully inserted!\n");
					printf("Press enter to continue...\n");
				}
			}
		}
		
		if(input==3){
			
			if(index == 0){
				printf("There is no item yet...\n");
				printf("Press enter to continue...\n");
			}
			if(index != 0){
				printf("=============================================================\n");
				printf("! No\t| Id\t\t| Name\t\t\t| Price\t\t\t|\n");
				printf("=============================================================\n");
				for(int j=0; j<index; j++){
					printf("| %d\t| ETC%s\t| %s\t\t | Rp. %.2f\t\t|\n", j+1, itemID_1[j], itemName_1[j], itemPrice1[j]);	
				}
				printf("=============================================================\n");
				
				do{
					printf("Which item you want to update? [0 to exit] [1..%d] ", index);
					scanf("%d", &jual);
				} while (jual>index || jual < 0);
			
			srand(time(0));
			int time = rand()%100;
			if(jual>0 && jual <= index){
				if(time <= 30){
					printf("##########################\n");
					printf("Customer got discount 25%!\n");
					printf("##########################\n");
					printf(" ");
					printf("ETC%s Item Detail\n", itemID_1[jual-1]);
					printf("==========================\n");
					printf("Item Name: %s\n", itemName_1[jual -1]);
					printf("Item Price: %.2f\n", itemPrice1[jual-1] - (itemPrice1[jual-1]*0.25));	
				} else {
					printf("ETC%s Item Detail\n", itemID_1[jual-1]);
					printf("===============================\n");
					printf("Item Name: %s\n", itemName_1[jual-1]);
					printf("Item Price: %.2f\n", itemPrice1[jual-1]);
				}
				int yes;
				int no;
				char pilih[10];
				
				do{
					printf("Are you sure you want to sell this? [yes|no]: ");
					scanf("%s", pilih); getchar();
					
					yes = strcmp("yes", pilih);
					no = strcmp ("no", pilih);
				} while (yes != 0 && no !=0);
				
				if(yes == 0){
					printf("item successfully sold!\n");
					printf("Press enter to continue...\n");
					for(int i=jual-1; i<index-1; i++){
						strcpy(itemID_1[i], itemID_1[i+1]);
						strcpy(itemName_1[i], itemName_1[i+1]);
						itemPrice1[i] = itemPrice1[i+1];
					} index--;
				} else if (no==0){
					printf("cancel selling!\n");
					printf("Press enter to continue...\n");
				}
			}
		
		}
	}
	}while(input !=4);	
	
	return 0;
}
