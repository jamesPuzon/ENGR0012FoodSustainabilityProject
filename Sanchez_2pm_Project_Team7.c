/*
 * ENGR-0012
 * Prof. Sanchez
 * James Puzon Chase Sickenberger
 * Updated: 4/11/23
 * 
 * This program is for the ENGR-0012 Portfolio Project. The purpose is to 
 * help the user learn how long they can store their food in a refrigerator
 * or freezer. The first feature that the app has is a game 
 * where the user can learn how long each type of food can be stored.
 * The second feature is a quiz that tests the user on how long different foods can be stored.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int store(int type,int result[4]);
const char *names(int storage,int times[3][17],int result[4]);
int days(int storage,int times[3][17],int result[4]);
void game(int length);
void instructions(void);
void quiz(int times[3][17]);



int main(void)
{
	int type,storage,length,result[4],play;
	int times[3][17] = 	{{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
						{14,2,5,35,14,7,5,3,3,4,5,10,3,14,10,14,0},
						{14,120,180,0,60,30,365,90,240,120,540,120,540,180,60,270,60}};
	char again,again2;
	printf("Welcome to the food advisor!\nThis program will help you "
	"store your food so that it doesn't go to waste.");
	
	do{
	//ask user if they want to play a game or take a quiz
	printf("\n\nWould you like to play a game or take a quiz?\n");
	printf("1. Game\n2. Quiz\n");
	
	do{
		printf("Enter 1 or 2: ");
		scanf(" %d",&play);
		}while(play!=1&&play!=2);
	printf("You entered: %d\n\n",play);
	
	if(play==1)
	{
		do{
			//get the type of food from the user
			printf("\n\nSelect your type of food:\n");
			printf("1. Fruits and Vegetables\n2. Grains, Beans, and Nuts\n"
			"3. Meat and Poultry\n4. Fish and Seafood\n5. Dairy\n");
			do{
				printf("Enter number 1-5: ");
				scanf("%d",&type);
				}while(type<1||type>5);
			printf("You entered: %d\n\n",type);
	
			//get storage type
			storage = store(type,result);
		
			//get number of days
			length = days(storage,times,result);
			//show instructions
			instructions();
			//play game
			game(length);
			//ask if user wants to use different food or storage option
			printf("Would you like to try out a different food type or storage option?\n");
			do{
				printf("Enter y or n: ");
				scanf(" %c",&again);
				}while(again!='y'&&again!='n');
			}while(again=='y');
		}
	else if(play==2)
	{
		do
		{
			quiz(times);
			printf("Would you like to take another quiz?\n");
			do{
				printf("Enter y or n: ");
				scanf(" %c",&again);
				}while(again!='y'&&again!='n');
			}while(again=='y');
		}
	printf("\nWould you like to try another function?\n");
	do{
		printf("Enter y or n: ");
		scanf(" %c",&again2);
		}while(again2!='y'&&again2!='n');
	}while(again2=='y');
	
	return 0;
}



//store function
int store(int type,int result[4])
{
	int storage,food,pick,pick2;
	switch (type)
	{
		//Fruits and Vegetables
		case 1: printf("Fruits and Vegetables can be stored in either a refrigerator or a freezer.\n");
		printf("Select an option:\n1. Refrigerator\n2. Freezer\n");
		do{
			printf("Enter 1 or 2: ");
			scanf("%d",&storage);
			}while(storage!=1&&storage!=2);
		printf("You entered %d\n\n",storage);
		result[0] = type;
		result[1] = storage;
		result[2] = 0;
		break;
		//Grains, Beans, Nuts
		case 2:	printf("Grains, Beans, and Nuts can be stored in an "
		"airtight container in a cool, dry place.\n\n");
		storage = 3;
		result[0] = type;
		result[1] = storage;
		result[2] = 0;
		
		break;
		//Meat and Poultry
		case 3: printf("Meat and Poultry can be stored in either a refrigerator or a freezer.\n");
		printf("Select an option:\n1. Refrigerator\n2. Freezer\n");
		do{
			printf("Enter 1 or 2: ");
			scanf("%d",&storage);
			}while(storage!=1&&storage!=2);
		printf("You entered %d\n\n",storage);
		printf("What type of meat or poultry do you have?\n");
		printf("1. Ground Meat or Fresh Poultry\n2. Ham\n3. Eggs\n"
		"4. Deli Meat\n5. Bacon or Sausage\n6. Steaks, Chops, or Roasts\n");
		printf("Select an option: ");
		scanf("%d",&food);
		while(food<1||food>6)
		{
			printf("Enter a number between 1 and 6: ");
			scanf("%d",&food);
			}
		printf("You entered %d",food);
		if(food==3&&storage==2)
		{
			printf("\nEggs should only be stored in a refrigerator.\n\n");
			storage = 1;
			}
		else
		{
			printf("\n\n");
			}
		result[0] = type;
		result[1] = storage;
		result[2] = food;
		
		break;
		//Seafood
		case 4: 
		printf("Seafood can be stored in either a refrigerator or a freezer.\n");
		printf("Select an option:\n1. Refrigerator\n2. Freezer\n");
		do{
			printf("Enter 1 or 2: ");
			scanf("%d",&storage);
			}while(storage!=1&&storage!=2);
		printf("You entered %d\n\n",storage);
		printf("What type of seafood do you have?\n");
		printf("1. Fin Fish\n2. Shellfish\n");
		do{
		printf("Enter 1 or 2: ");
		scanf("%d",&pick);
			}while(pick!=1&&pick!=2);
		printf("You entered %d\n\n",pick);
		if(pick==1)
		{
			printf("What type of fin fish do you have?\n");
			printf("1. Fatty Fish\n2. Lean Fish\n");
			do{
			printf("Enter 1 or 2: ");
			scanf("%d",&pick2);
				}while(pick2!=1&&pick2!=2);
			printf("You entered %d\n\n",pick2);
			result[0] = type;
			result[1] = storage;
			result[2] = pick2+6;
			}
		else if(pick==2)
		{
			printf("What type of shellfish do you have?\n");
			printf("1. Crab or Lobster Meat\n2. Crayfish\n3. Shucked Clams, Mussels, Oysters, or Scallops\n4. Squid\n");
			do{
			printf("Select option: ");
			scanf("%d",&pick2);
				}while(pick2<1||pick2>4);
			printf("You entered %d\n\n",pick2);
			result[0] = type;
			result[1] = storage;
			result[2] = pick2+8;
			}
		
	
		
		break;
		//Dairy
		case 5: printf("For your food type, Dairy, the best storage "
		"opton is a refrigerator for quality.\nHowever, some products can be stored in a freezer.\n");
		printf("Choose your type of dairy:\n1. Cheese\n2. Yogurt\n3. Butter\n4. Ice Cream\n");
		printf("Select option: ");
		scanf("%d",&food);
		while(food<1||food>4)
		{
			printf("Enter number 1-4: ");
			scanf("%d",&food);
			}
		//Give storage option based on food and store food in array
		switch (food)
		{
			//Cheese
			case 1: printf("\nYou entered Cheese, which can be stored in a refrigerator or a freezer.\n");
			printf("Select an option:\n1. Refrigerator\n2. Freezer\n");
			do{
				printf("Enter 1 or 2: ");
				scanf("%d",&storage);
				}while(storage!=1&&storage!=2);
			printf("You entered %d\n\n",storage);
			break;
			//Yogurt
			case 2: printf("\nYou entered Yogurt, which can be stored in a refrigerator or a freezer.\n");
			printf("Select an option:\n1. Refrigerator\n2. Freezer\n");
			do{
				printf("Enter 1 or 2: ");
				scanf("%d",&storage);
				}while(storage!=1&&storage!=2);
			printf("You entered %d\n\n",storage);
			break;
			//Butter
			case 3: printf("\nYou entered Butter, which can be stored in a refrigerator or a freezer.\n");
			printf("Select an option:\n1. Refrigerator\n2. Freezer\n");
			do{
				printf("Enter 1 or 2: ");
				scanf("%d",&storage);
				}while(storage!=1&&storage!=2);
			printf("You entered %d\n\n",storage);
			break;
			//Ice Cream
			case 4: printf("\nYou entered Ice Cream.\nYour food should only be stored a freezer.\n\n");
			storage = 2;
			break;
			}
			result[0] = type;
			result[1] = storage;
			result[2] = food+12;
			break;
		}
	
	return storage;
	}

//names function
const char *names(int storage,int times[3][17],int result[4])
{
	//get food
	if(storage==3)
	{
		return "Grains, beans, or nuts";
		}
	else
	{
	switch (times[0][result[2]])
	{
		case 1: return "Fruits and Vegetables";
		break;
		case 2: return "Ground Meat or Poultry";
		break;
		case 3: return "Ham";
		break;
		case 4: return "Eggs";
		break;
		case 5: return "Deli Meat";
		break;
		case 6: return "Bacon or Sausage";
		break;
		case 7: return "Steak, Chops, or Roast";
		break;
		case 8: return "Fatty Fish";
		break;
		case 9: return "Lean Fish";
		break;
		case 10: return "Crab or Lobster Meat";
		break;
		case 11: return "Crayfish";
		break;
		case 12: return "Shucked Clams, Mussels, Oysters, or Scallops";
		break;
		case 13: return "Squid";
		break;
		case 14: return "Cheese";
		break;
		case 15: return "Yogurt";
		break;
		case 16: return "Butter";
		break;
		case 17: return "Ice Cream";
		break;
		}
		}
	}
//days function
int days(int storage, int times[3][17], int result[4])
{
	int length;
	//get the number of days before the food goes bad
	length = times[result[1]][result[2]];
	//display food name
	printf("Food Name: %s\n",names(storage,times,result));
	//display storage type and time
	switch (storage)
	{
		case 1: printf("Your storage option is: Refrigerator\n");
		printf("You can store your food for %d days.\n\n",length);
		break;
		case 2: printf("Your storage option is: Freezer\n");
		printf("You can store your food for %d days.\n\n",length);
		break;
		case 3: printf("Your storage option is: Cool, Dry Place\n");
		length = 365;
		printf("You can store your food for %d days.\n\n",length);
		break;
		}
	
	return length;
	}

//instructions function
void instructions(void)
{
	//show instructions
	printf("_____________________________________________________\n\n"
	"Welcome to the game.\n\nYou have just survived a nuclear "
	"apocalypse and you need to stockpile your food.\n"
	"You just put your backup food into storage (fridge or freezer).\n"
	"Your goal is to KEEP YOUR FOOD IN STORAGE AS LONG AS YOU CAN BEFORE IT GOES BAD.\n\n"
	"Unfortunately, you can only access your storage when your "
	"air quality sensor indicates that the air is safe.\n"
	"There is no pattern to when the air is safe, and you need "
	"to keep your food fresh as long as you can to survive.\n"
	"If you waste more than 10%% of your food's life span, YOU LOSE.\n\n");
	}
//game function
void game(int length)
{
	srand(time(NULL)); 
	int time,days,bad;
	char play,finish;
	
	//start game
	do{
		printf("_____________________________________________________\n\n");
		time = 0;
		printf("Let's begin.\n\n");
		printf("Your food is good for %d days.\n",length);
		do{
		days = rand()%length/2;
		time += days;
		bad = length-time;
		if(bad>0)
		{
			printf("\nAfter %d days, the air quality is safe.\n",days);
			printf("Your food is still good for %d days.\n",bad);
			printf("Do you want to remove your food from storage?\n");
			do{
				printf("Enter y or n: ");
				scanf(" %c",&finish);
			}while(finish!='y'&&finish!='n');
			if(finish=='y')
			{
				if(bad<(length/10))
				{
					//Win
					printf("\nYou won!!!\nYou were able so save your food"
					" until the last week and you survived the "
					"apocalypse!\n\n");
					}
				else
				{
					//Lose
					printf("\nYou lost!!!\nYou weren't able to save your "
					"food long enough to survive.\n\n");
					}
				}
			else if(finish=='n');
			}
		else if(bad<0)
		{
			//Lose
			printf("\nYou lost!!!\nThe air quality wasn't safe again before your food went bad.\n");
			printf("Better luck in your next life!\n\n");
			}
		else if(bad==0)
		{
			//Win
			printf("\nYou won!!!\nYou got your food on the last day "
			"and were able to survive the apocalypse!\n\n");
			}
			}while(bad>0&&finish!='y');
		//ask if the user wants to play again
		printf("\nWould you like to play again?\n");
		do{
			printf("Enter y or n: ");
			scanf(" %c",&play);
			}while(play!='y'&&play!='n');
		printf("You entered: %c\n\n",play);
		}while(play=='y');
	}

//quiz function
void quiz(int times[3][17])
{
	srand(time(NULL));
	int ans,score,result[4],questions;
	double grade;
	printf("Food Waste Quiz:\n\n");
	//ask the user how many questions they want on the quiz
	printf("How many questions would you like on the quiz?\n");
	do{
		printf("Enter number 1-17: ");
		scanf("%d",&questions);
		}while(questions<1||questions>17);
		printf("\n");
	for(int i=0;i<questions;i++)
	{
		int store = (rand()%3)+1;
		result[2] = rand()%17;
		switch (store)
		{
			case 1: 
			printf("%d. How many days can you store %s in a refrigerator?\n",i+1,names(store,times,result));
			printf("Answer: ");
			scanf("%d",&ans);
			//check answer
			if(ans==times[store][result[2]])
			{
				printf("Correct\n\n");
				score = 1;
				}
			else
			{
				printf("Incorrect\nThe correct answer is: %d\n\n",times[store][result[2]]);
				score = 0;
				}
			grade += score;
			break;
			case 2:
			printf("%d. How many days can you store %s in a freezer?\n",i+1,names(store,times,result));
			printf("Answer: ");
			scanf("%d",&ans);
			//check answer
		if(ans==times[store][result[2]])
		{
			printf("Correct\n\n");
			score = 1;
			}
		else
		{
			printf("Incorrect\nThe correct answer is: %d\n\n",times[store][result[2]]);
			score = 0;
			}
		grade += score;
			break;
			case 3:
			printf("%d. How many days can you store Grains, beans, or nuts in a cool, dry place?\n",i+1);
			printf("Answer: ");
			scanf("%d",&ans);
			//check answer
		if(ans==365)
		{
			printf("Correct\n\n");
			score = 1;
			}
		else
		{
			printf("Incorrect\nThe correct answer is: 365\n\n");
			score = 0;
			}
		grade += score;
			break;
			
			}
		printf("\n");
		}
	grade = grade/questions*100;
	printf("Your grade is %4.1lf%%\n\n",grade);
	}



