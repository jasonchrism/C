#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(){

    int input;
    int cek;
    int sell;
    int update;
    int index = 0;
    char itemID[50];
    char itemName[50];
    float itemPrice;
    
	char itemIDs[50][255];
	char itemNames[50][255];
	float itemPrices[50];
   
	do{ 
	    puts("Electronics!");
	    puts("======================");
	    puts("1. Insert Electronic Stock");
	    puts("2. Update Electronic");
	    puts("3. Sell Electronic");
	    puts("4. Exit");
	    printf(">> ");
	    scanf("%d", &input);
	    system("cls");
	
	    if (input == 1){
	        do{
	            cek = 0;
	            printf("Input Item Id [must be numeric with exactly 3 digit]: ");
	            scanf("%s", itemID); getchar();
	            for (int i = 0; i < strlen(itemID); i++){
	                if (!isdigit(itemID[i])){
	                    cek = 1;
	                }
	            }
	        } while (strlen(itemID) != 3 || cek == 1);
	
	        do{
	            printf("Input Item name [5-25 characters]: ");
	            scanf("%[^\n]", itemName); getchar();
	        } while (strlen(itemName) <= 5 || strlen(itemName) >= 25);
			
			do{
				printf("Input Item price [not more than 5M]: ");
				scanf("%f", &itemPrice); getchar();
			} while (itemPrice > 5000000);
			
			strcpy(itemIDs[index], itemID);
			strcpy(itemNames[index], itemName);
			itemPrices[index] = itemPrice;
			index = index + 1;
			
			puts("Item Successfully Inserted!");
			printf("Press enter to continue..."); getchar();
			system("cls");
	    }
	    
	    if (input == 2){
	    	if (index == 0){
	    		puts("There is no item yet...");
	    		printf("Press enter to continue"); getchar(); getchar();
	    		system("cls");
			} 
			
			if (index != 0){
				printf("=========================================================================================\n");
				printf("| No.  | Id\t| Name\t\t\t\t| Price\t\t|\n");
				printf("=========================================================================================\n");
				for (int j = 0; j < index; j++){
					printf("| %d | ETC%s | %-25s | Rp. %-10.2f |\n", j + 1, itemIDs[j], itemNames[j], itemPrices[j]);
					}
					printf("=========================================================================================\n");	
				
				do{
					printf("Which item you want to update? [0 to exit] [1..%d]: ", index);
					scanf("%d", &update);
					if (update == 0){
						break;
					} 
				} while (update > index || update < 1);
				
				do{
					if (update == 0){
						break;
					}
	            cek = 0;
	            printf("Input Item Id [must be numeric with exactly 3 digit]: ");
	            scanf("%s", itemID); getchar();
	            for (int i = 0; i < strlen(itemID); i++){
	                if (!isdigit(itemID[i])){
	                    cek = 1;
	                	}
	            	}
		        } while (strlen(itemID) != 3 || cek == 1);
		
		        do{
		        	if (update == 0){
		        		break;
					}
		            printf("Input Item name [5-25 characters]: ");
		            scanf("%[^\n]", itemName); getchar();
		        } while (strlen(itemName) <= 5 || strlen(itemName) >= 25);
				
				do{
					if (update == 0){
						break;
					}
					printf("Input Item price [not more than 5M]: ");
					scanf("%f", &itemPrice); getchar();
				} while (itemPrice > 5000000);
				
					strcpy(itemIDs[update-1], itemID);
					strcpy(itemNames[update-1], itemName);
					itemPrices[update-1] = itemPrice;
					
					printf("Item successfullt updated!\n");
					printf("Press enter to continue..."); getchar();
					system("cls");
				}
			}
			
			if (input == 3){
				if (index == 0){
	    			puts("There is no item yet...");
		    		printf("Press enter to continue"); getchar(); getchar();
		    		system("cls");
				} 
				
				if (index != 0){
					printf("=========================================================================================\n");
					printf("| No.\t| Id\t\t| Name\t\t\t\t\t| Price\t\t\t|\n");
					printf("=========================================================================================\n");
					for (int k = 0; k < index; k++){
						printf("| %d\t| ETC%s\t| %s\t\t\t\t| Rp. %.2f\t\t|\n", k + 1, itemIDs[k], itemNames[k], itemPrices[k]);
					}
					printf("=========================================================================================\n");
				do{
					printf("Which item you want to sell? [0 to exit] [1..%d]: ", index);
					scanf("%d", &sell);
				} while (sell > index || sell < 1);
					
					srand(time(0));
					int disc = rand()%100;
					if (disc <= 30){
						printf("##########################\n");
						printf("Customer got discount 25%%!\n");
						printf("##########################\n\n");
					}
					
					char yn[5];
					printf("ETC%d Item Detail\n", itemIDs[sell-1]);
					puts("==================\n");
					printf("Item Name   : %s\n", itemNames[sell-1]);
					printf("Item Price  : %.2f\n", itemPrices[sell-1]);
					
					int yes;
					int no;
					
					do{
					char yn[5];
						printf("Are you sure you want to sell this? [yes|no]: ");
						scanf("%s", yn);
						yes = strcmp("yes", yn);
						no = strcmp ("no", yn);
					} while (yes != 0 && no !=0);
					
					if (yes == 0){
						printf("Item successfully sold!\n");
						printf("Press enter to continue..."); getchar();
						system("cls");
						
						for (int m = sell-1; m < index-1; m++){
							strcpy(itemIDs[m], itemIDs[m+1]);
							strcpy(itemNames[m], itemNames[m+1]);
							itemPrices[m] = itemPrices[m+1];
						}
						index--;
					} else if (no == 0){
						printf("Cancel selling!\n");
						printf("Press enter to continue...");
						system("cls");
					}
				}
			}
		} while (input != 4);
        puts("Thank you for using this app!");
        puts("Press enter to continue..."); getchar(); getchar();
        system("cls");
	}