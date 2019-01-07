#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login   (char username[5]);
void password(char username[5], char user_password[5]);
void add     (int meals[100][4][20], int* count_meals);
void view    (int meals[100][4][20], int  count_meals);
void getType (int meals[100][4][20], int meal);
void modify  (int meals[100][4][20], int count_meals);
void search  (int meals[100][4][20], int count_meals);
void sort    (int meals[11][4][20], int count_meals);
int main(int argc, char *argv[]) {
	int count_meals = 0;
	int meals[100][4][20];
	char choice[7];
	char username[5]= {'J','o','h','n','\0'};

	do {
		login(username);
		do{
		

			printf("                             Welcome!\n     What would you like to do?:Add,Modify,View,Sort,Search or Exit?\n");
			scanf("%s",choice);
			if (strcmp(choice,"Add") ==0  )      add   (meals, &count_meals);
			else if (strcmp(choice,"Modify")==0) modify(meals, count_meals);
			else if (strcmp(choice,"View")==0  ) view  (meals, count_meals);
			else if (strcmp(choice,"Search")==0) search(meals,count_meals);
			else if (strcmp(choice,"Sort")==0  ) sort  (meals,count_meals);
			else if (strcmp(choice,"Exit")==0  ) break;
			else printf("Invalid choice. Please write again what you want\n");
			
		} while(1);

	} while((strcmp(choice,"Exit")==0));
	return 0;
}
void login(char username[5]) {
	char user[5];
	char pass[5];
	int ret;
	printf("Welcome to your diet diary:\n Login\n Username:\n");
	do {
		scanf("%s",user);
		ret=strcmp(user,username);
		if(ret!=0) printf("Incorrect username.Please try again.\n");

	} while(ret!=0);
	ret=0;
	printf("Password:\n");
	char randompass[5];
	password(username,randompass);
	scanf("%s",pass);
	ret=strcmp(randompass,pass);
	while(ret!=0) {
		printf("Incorrect password.Please try again.\n");
		scanf("%s",pass);
		ret=strcmp(randompass,pass);
	}

}


void password(char username[5],char randompass[5]) {
	int x = rand()%2;

	int i=0;
	randompass[i] = username[i] + (i%2==1-x)*32;
	for(i=1; i<4; i++)
		randompass[i] = username[i] -(i%2==x)*32;

	randompass[4] = '\0';

}

void add (int meals[100][4][20],int* count_meals) {
	getchar();
	printf("Give the name of the meal:\n");
	scanf("%[^\n]s", &meals[*count_meals][0]);

	printf("Give me the associated calories:\n");
	scanf("%d", &meals[*count_meals][1][0]);

	getchar();

	printf("Give me the time when the meal took place:\n");
	float time;
	do {
		scanf("%f", &time);
		meals[*count_meals][2][0] =   (int) time;
		meals[*count_meals][2][1] = ( (int)(100*time) ) %100;

		if( (0 <= meals[*count_meals][2][0] && meals[*count_meals][2][0] < 24)
		        && (0 <= meals[*count_meals][2][1] && meals[*count_meals][2][1] < 60) ) break;
		else printf("Invalid time, please insert it again.\n");
	} while(1);

	if ( 0 <= time && time < 5 || 20 <= time && time < 24) meals[*count_meals][3][0] = 3;
	else if (time < 12 ) meals[*count_meals][3][0] = 1;
	else if (time < 20 ) meals[*count_meals][3][0] = 2;

	(*count_meals)++;
	system("cls");
	printf("End of Add\n");
}

void view (int meals[100][4][20], int count_meals) {
	int i;
	for(i=0; i<count_meals; i++) {
		if(meals[i][2][0]>0 && meals[i][2][0]<=9) printf("Name: %s Calories: %d Time: 0%d.",meals[i][0], meals[i][1][0], meals[i][2][0]);
		else printf("Name: %s Calories: %d Time: %d.",meals[i][0], meals[i][1][0], meals[i][2][0]);
		if(meals[i][2][1]==0) printf("%d0 Type: ",meals[i][2][1]);
		else printf("%d Type: ",meals[i][2][1]);
		getType(meals,i);
	}
	//system("cls");
	printf("End of View\n");
}

void getType(int meals[100][4][20], int meal) {
	switch(meals[meal][3][0]) {
		case 1:
			printf("prwino\n");
			break;
		case 2:
			printf("mesimeriano\n");
			break;
		case 3:
			printf("vradino\n");
			break;
	}
}
void modify(int meals[100][4][20], int count_meals) {
	int number;
	printf("Name: %s Calories: %d Time: %d.%d Type:",
	       meals[count_meals-1][0]   ,
	       meals[count_meals-1][1][0],
	       meals[count_meals-1][2][0],
	       meals[count_meals-1][2][1] );
	getType(meals,count_meals-1);
	printf("What would you like to modify?\nPress 1 for food\nPress 2 for calories\nPress 3 for time\n");
	scanf("%d",&number);
	if(number==1) {
		getchar();
		printf("Give the name of the meal:\n");
		scanf("%[^\n]s", &meals[count_meals-1][0]);
		getchar();
	}
	if(number==2) {
		printf("Give me the associated calories:\n");
		scanf("%d", &meals[count_meals-1][1]);

		getchar();

	}
	if(number==3) {

		printf("Give me the time when the meal took place:\n");
		float time;
		do {
			scanf("%f", &time);
			meals[count_meals-1][2][0] =   (int) time;
			meals[count_meals-1][2][1] = ( (int)(100*time) ) %100;

			if( (0 <= meals[count_meals-1][2][0] && meals[count_meals-1][2][0] < 24)
			        && (0 <= meals[count_meals-1][2][1] && meals[count_meals-1][2][1] < 60) ) break;
			else printf("Invalid time, please insert it again.\n");
		} while(1);

		if ( 0 <= time && time < 5 || 20 <= time && time < 24) meals[count_meals-1][3][0] = 3;
		else if (time < 12 ) meals[count_meals-1][3][0] = 1;
		else if (time < 20 ) meals[count_meals-1][3][0] = 2;

	}
	system("cls");
	printf("End of Modify\n");
}
void search(int meals[11][4][20], int count_meals) {
	char tpmeal[12];
	int type = 0;
	int i;
	printf("What would you like to search ?\n ");

	do {
		scanf("%s",tpmeal);
		if((strcmp(tpmeal,"prwino")==0)) type=1;
		else if((strcmp(tpmeal,"mesimeriano")==0)) type=2;
		else if((strcmp(tpmeal,"vradino")==0)) type=3;
		else printf("Invalid answer. Please try again.");
	} while(type==0);
	if(type==1) {
		printf("For prwino you had:\n");
		for(i=0; i<count_meals; i++) {
			if(meals[i][3][0]==type) printf("The meal is %s, The calories are %d, The time was %d.%d\n",meals[i][0],meals[i][1],meals[i][2][0],meals[i][2][1]);
		}
	} else if(type==2) {
		printf("For mesimeriano you had:\n");
		for(i=0; i<count_meals; i++) {
			if(meals[i][3][0]==type) printf("The meal is %s, The calories are %d, The time was %d.%d\n",meals[i][0],meals[i][1],meals[i][2][0],meals[i][2][1]);
		}
	} else {
		printf("For vradino you had:\n");
		for(i=0; i<count_meals; i++) {
			if(meals[i][3][0]==type) printf("The meal is %s, The calories are %d, The time was %d.%d\n",meals[i][0],meals[i][1],meals[i][2][0],meals[i][2][1]);
		}
	}

	printf("End of Search\n");
}
void sort(int meals[100][4][20], int count_meals) {
	int i,j,k,u;

	int temp_name;
	int temp;


	for(i=0; i<count_meals-1; i++) {
		for(j=0; j<count_meals-i-1; j++) {
			if(meals[j][1][0]<meals[j+1][1][0]) {

				for(k=0; k<20; k++) {
					temp_name = meals[j][0][k];
					meals[j][0][k] = meals[j+1][0][k];
					meals[j+1][0][k] = temp_name;
				}

				for(u=1; u<4; u++) {
					temp = meals[j][u][0];
					meals[j][u][0] = meals[j+1][u][0];
					meals[j+1][u][0] = temp;
				}
				
				// minutes
				temp = meals[j][2][1];
				meals[j][2][1] = meals[j+1][2][1];
				meals[j+1][2][1] = temp;
			}
		}
	}

	view(meals,count_meals);
	
	printf("End of Sort\n");
}
