
	/********************************************\
	|  PASSWORD MANAGING SYSTEM		     |
	|		    M  D  Y		     |
	|  Date Created   : 12 08 21		     |
	|  Software Vers  : alpha 0.01		     |
	|********************************************|
	|  Creator  Name  : Aaron Meek		     |
	|  Constact Email : aaronmeek16@outlook.com  |
	\********************************************/

#include "details.h"
#include "common.h"

//get a new account type from the user
void changeAccType(char * accType)
{
	char tempString[MAX_STRING + 1];

	//open a menu
	printf("    _________________________________________________________________\n");
	printf("   |                                                                 |\n");
	printf("   |          ENTER THE TYPE OF ACCOUNT                              |\n");
	printf("   |_________________________________________________________________|\n");
	printf("   |                                                                 |\n");
	printf("   |          Examples (no spaces): YouTube, Gmail, Outlook, etc...  |\n");
	printf("   |_________________________________________________________________|\n\n");
	printf("              Enter here: ");
	//get the account type
	scanf("%30s", tempString);
	clearStandardInputBuffer();
	
	//copy the user input to the destination
	strcpy(accType, tempString);
}
//get an account email from the user
void changeAccEmail(char * accEmail)
{
	char tempString[MAX_STRING + 1];

	//open a menu
	printf("    _________________________________________________________________\n");
	printf("   |                                                                 |\n");
	printf("   |          ENTER THE ACCOUNT EMAIL                                |\n");
	printf("   |_________________________________________________________________|\n\n");
	//promt the user to input the aaccount email
	printf("              Enter here: ");
	//get the account type
	scanf("%30s", tempString);
	clearStandardInputBuffer();
	
	//copy the user input to the destination
	strcpy(accEmail, tempString);
}
//get a new account login from the user
void changeAccLogin(char * accLogin)
{
	char tempString[MAX_STRING + 1];

	//open a menu
	printf("    _________________________________________________________________\n");
	printf("   |                                                                 |\n");
	printf("   |          ENTER THE ACCOUNT LOGIN ID                             |\n");
	printf("   |_________________________________________________________________|\n");
	printf("   |                                                                 |\n");
	printf("   |          If the email is used, write \"email\"                    |\n");
	printf("   |_________________________________________________________________|\n\n");

	//promt the user to input the aaccount login
	printf("              Enter here: ");
	//get the account login
	scanf("%30s", tempString);
	clearStandardInputBuffer();
	
	//copy the user input to the destination
	strcpy(accLogin, tempString);

}
//get a new account password from the user
void changeAccPass(char * accPassword)
{
	int flag = 1;
	//strings have +2 to check for length validation
	char tempString[MAX_STRING + 2] = {0};
	char tempChecker[MAX_STRING + 2] = {0};

	//open a menu
	printf("    _________________________________________________________________\n");
	printf("   |                                                                 |\n");
	printf("   |          ENTER THE ACCOUNT PASSWORD (30 chars max)              |\n");
	printf("   |_________________________________________________________________|\n\n");

	//prompt the user to input a new password
	printf("              Enter here: ");
	
	//validate the user input
	while(flag)
	{
		//get the account password
		scanf("%31s", tempString);
		
		//check the length is not over 30 characters
		if(strlen(tempString) > 30)
		{
			//reset the string to a safe state
			clearStandardInputBuffer();
			strcpy(tempString,tempChecker);
			printf("\n              ERROR: must be under 30 characters in length: ");
			continue;
		}
		else
		{
			flag = 0;
		}
	}
	
	//prompt the user to confirm their input
	printf("\n              Confirm password: ");
	scanf("%31s", tempChecker);
	
	if(strcmp(tempString, tempChecker))
	{
		printf("\n              ERROR: the passwords entered do not match; please try again!\n");
		clearStandardInputBuffer();
		hang();
		clearScreen();
	}
	else
	{
		strcpy(accPassword,tempString);
		clearStandardInputBuffer();
	}
}
//get a new name on the account from the user
void changeAccName(char * accFirstName)
{
	char tempName[MAX_STRING + 1] = {0}, tempLast[MAX_STRING + 1] = {0};

	//open a menu
	printf("    _________________________________________________________________\n");
	printf("   |                                                                 |\n");
	printf("   |          ENTER THE NAME ON THE ACCOUNT                          |\n");
	printf("   |_________________________________________________________________|\n\n");

	//promt the user to input the aaccount name
	printf("              Enter the first name (0 - skip): ");

	//get the account name
	scanf("%20s", tempName);
	
	//if the first name is valid, get the second name
	if(strcmp(tempName, "0"))
	{
		printf("\n              Enter the last name: ");
		scanf("%20s", tempLast);
		strcat(tempName," ");
		strcat(tempName,tempLast);
	}
	//set the names to empty
	else
	{
		strcpy(tempName," ");
		strcpy(tempLast," ");
	}

	clearStandardInputBuffer();

	//copy the user input to the destination
	strcpy(accFirstName, tempName);	
}

void changeAccPhone(char * accPhone)
{
	long long unsigned tempPhone = 0;
	int checkError = 0;

	//open a menu
	printf("    _________________________________________________________________\n");
	printf("   |                                                                 |\n");
	printf("   |          ENTER THE PHONE NUMBER ON THE ACCOUNT                  |\n");
	printf("   |_________________________________________________________________|\n");
	printf("   |                                                                 |\n");
	printf("   |          Example: 9055555555, 6471234567                      |\n");
	printf("   |_________________________________________________________________|\n\n");

	do
	{
		//promt the user to input the aaccount phone#
		printf("              Enter here (0 - skip): ");
		//get the account number
		checkError = scanf("%llu", &tempPhone);
		
		if( (!tempPhone) && (checkError) )
		{
			checkError = 1;
		}
		else if( (!checkError) || (tempPhone < 1000000000) )
		{
			printf("\n              ERROR: only enter numeric characters\n\n");
			checkError = 0;
			clearStandardInputBuffer();
		}

	} while(!checkError);

	if(!tempPhone)
	{
		strcpy(accPhone, " ");
	}
	else
	{
		sprintf(accPhone, "%llu", tempPhone);
	}
}

void changeAccDOB(char * dateOfBirth)
{
	int day = 0, month = 0, year = 0;
	char sday[4] = {0}, smonth[4] = {0}, syear[5] = {0}, tempDOB[MAX_DOB + 1] = {0};

	//open a menu
	printf("    _________________________________________________________________\n");
	printf("   |                                                                 |\n");
	printf("   |          ENTER THE DATE OF BIRTH ON THE ACCOUNT                 |\n");
	printf("   |_________________________________________________________________|\n\n");

	//promt the user to input the aaccount phone#
	printf("              Enter the month (0 - skip): ");
	month = getIntFromRange(0,12);

	if(month)
	{
		printf("\n              Enter the day: ");

		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		{
			day = getIntFromRange(1,31);
		}

		if(month==4||month==6||month==9||month==11)
		{
			day = getIntFromRange(1,30);
		}

		if(month==2)
		{
			day = getIntFromRange(1,29);
		}

		printf("\n              Enter the year: ");
		year = getIntFromRange(1800,10000);

		sprintf(sday, "%d", day);
		sprintf(smonth, "%d", month);
		sprintf(syear, "%d", year);
		
		strcat(sday,"/");
		strcat(smonth,"/");
		strcat(tempDOB,sday);
		strcat(tempDOB,smonth);
		strcat(tempDOB,syear);
		strcpy(dateOfBirth, tempDOB);
	}
	//leave the date of birth empty
	else
	{
		strcpy(dateOfBirth, " ");
	}

	clearStandardInputBuffer();

}

void changeAccSec(char * secType, char * recQuestion1, char * recQuestion2, char * recQuestion3)
{
	printf("   \n*** Security Details ***");
	printf("   \n   - examples: Google Auth, Two-Step, Security Questions, etc...\n");
}



