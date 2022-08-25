
	/********************************************\
	|  PASSWORD MANAGING SYSTEM		     |
	|		    M  D  Y		     |
	|  Date Created   : 12 08 21		     |
	|  Software Vers  : alpha 0.01		     |
	|********************************************|
	|  Creator  Name  : Aaron Meek		     |
	|  Constact Email : aaronmeek16@outlook.com  |
	\********************************************/

#include "account.h"

//account main menu
int mainMenu(struct Accounts acc[], int arrSize, struct Security sec[])
{
	int input = 0;
	do
	{
		//open a menu
		printf("    _________________________________________________________________\n");
		printf("   |                                                                 |\n");
		printf("   |          WELCOME TO YOUR PASSWORD MANAGER                       |\n");
		printf("   |_________________________________________________________________|\n");
		printf("   |                                                                 |\n");
		printf("   |          1) Add new account                                     |\n");
		printf("   |                                                                 |\n");
		printf("   |          2) Manage an account                                   |\n");
		printf("   |                                                                 |\n");
		printf("   |          3) Remove an account                                   |\n");
		printf("   |                                                                 |\n");
		printf("   |          4) Display all account info                            |\n");
		printf("   |                                                                 |\n");
		printf("   |          0) Exit & Save                                         |\n");
		printf("   |_________________________________________________________________|\n\n");
		printf("              Please select one of the following: ");
		input = getIntFromRange(0,4);
		
		if(input == 1)
		{
			clearScreen();
			addAccount(acc, arrSize, sec);
		}
		else if(input == 2)
		{
			manageAccount(acc, arrSize, sec);
		}
		else if(input == 3)
		{
			removeAccount(acc, arrSize, sec);
		}
		else if(input == 4)
		{
			clearScreen();
			displayAllAccounts(acc, arrSize, sec);
		}
		else clearScreen(); //do nothing
	} while(input);
			
	return 0;
}
//add a new account
void addAccount(struct Accounts acc[], int arrSize, struct Security sec[])
{
	int index = -1;
	
	//find the next free position for a new account
	index = findNewAccountIndex(acc, arrSize);

	if(index == -1)
	{
		printf("\n              ERROR: the system could not find an open slot\n");
		hang();
	}
	else
	{
		acc[index].accountNumber = accountNumberGenerator(acc, arrSize);
		
		printf("\n              NEW ACCOUNT NUMBER (%03d)\n", acc[index].accountNumber);
		
		//enter acc type
		changeAccType(acc[index].accountType);
		//enter acc email
		changeAccEmail(acc[index].accountEmail);
		//enter login
		changeAccLogin(acc[index].userLogin);  
		//enter user password
		while(!(*acc[index].userPassword))
		{
			changeAccPass(acc[index].userPassword);
		}
		//enter full name
		changeAccName(acc[index].firstName);
		//enter phone number
		changeAccPhone(acc[index].phoneNumber);
		//enter birthday
		changeAccDOB(acc[index].birthDate);
		//enter security details
		changeAccSec(sec[index].secType, sec[index].recQuestion1, sec[index].recQuestion2, sec[index].recQuestion3);
		
		//display the newly created account
		clearScreen();
		displayCurrentAccount(acc[index], sec[index]);
		hang();
		clearScreen();
	}
}
//manage an existing account
void manageAccount(struct Accounts acc[], int arrSize, struct Security sec[])
{
	int input = 0;
	int index = 0;
	
	//get an account to change from the user
	printf("\n              Manage Account\n");
	index = findIndexByAccNumber(acc, arrSize);
	
	//if the account doesn't exist (-1), notify the user
	if(index == -1)
	{
		printf("\n              ERROR: account number could not be found\n");
		hang();
		clearScreen();
	}
	
	//if the user chose to cancel (-2), return to the previous menu
	if(index == -2)
	{
		clearScreen();
	}
	
	while(index >= 0)
	{
		clearScreen();
		//open a menu
		printf("    _________________________________________________________________\n");
		printf("   |                                                                 |\n");
		printf("   |          MANAGE ACCOUNT #%03d                                    |\n",
			acc[index].accountNumber);
		printf("   |_________________________________________________________________|\n");
		printf("   |                                                                 |\n");
		printf("   |          1) Account             %30s  |\n",
			acc[index].accountType);
		printf("   |                                                                 |\n");
		printf("   |          2) Email               %30s  |\n",
			acc[index].accountEmail);
		printf("   |                                                                 |\n");
		printf("   |          3) Login               %30s  |\n",
			acc[index].userLogin);
		printf("   |                                                                 |\n");
		printf("   |          4) Password            %30s  |\n",
			acc[index].userPassword);
		printf("   |                                                                 |\n");
		printf("   |          5) Name                %30s  |\n",
			acc[index].firstName);
		printf("   |                                                                 |\n");
		printf("   |          6) Phone Number                        %14s  |\n",
				acc[index].phoneNumber);
		printf("   |                                                                 |\n");
		printf("   |          7) Date of Birth                           %10s  |\n",
				acc[index].birthDate);
		printf("   |                                                                 |\n");
		printf("   |          8) Security (unavailable)                              |\n");
		printf("   |                                                                 |\n");
		printf("   |          0) Previous Menu                                       |\n");
		printf("   |_________________________________________________________________|\n");
		printf("\n              Please select one of the following: ");
		input = getIntFromRange(0,8);

		//change acc type
		if(input == 1)
		{
			clearScreen();
			changeAccType(acc[index].accountType);
		}
		//change acc email
		else if(input == 2)
		{
			clearScreen();
			changeAccEmail(acc[index].accountEmail);
		}
		//change acc login
		else if(input == 3)
		{
			clearScreen();
			changeAccLogin(acc[index].userLogin);
		}
		//change acc password
		else if(input == 4)
		{
			clearScreen();
			changeAccPass(acc[index].userPassword);
		}
		//change acc name
		else if(input == 5)
		{
			clearScreen();
			changeAccName(acc[index].firstName);
		}
		//change acc phone number
		else if(input == 6)
		{
			clearScreen();
			changeAccPhone(acc[index].phoneNumber);
		}
		//change acc date of birth
		else if(input == 7)
		{
			clearScreen();
			changeAccDOB(acc[index].birthDate);
		}
		//change acc security info
		else if(input == 8)
		{
			clearScreen();
			changeAccSec(sec[index].secType, sec[index].recQuestion1, sec[index].recQuestion2, sec[index].recQuestion3);
		}
		//go back one menu
		else
		{
			index = -1;
			clearScreen();
		}
	}

}
//remove an existing account
void removeAccount(struct Accounts acc[], int arrSize, struct Security sec[])
{
	int index = 0;
	char string[4] = "YyNn", input;
	
	struct Accounts tempAcc = {0};
	struct Security tempSec = {0};
	
	//get an account to change from the user
	printf("\n              Remove Account\n");
	index = findIndexByAccNumber(acc, arrSize);
	
	//if the account doesn't exist (-1), notify the user
	if(index == -1)
	{
		printf("\n              ERROR: account number could not be found\n");
		hang();
		clearScreen();
	}
	
	//if the user chose to cancel (-2), return to the previous menu
	if(index == -2)
	{
		clearScreen();
	}
	
	if(index >= 0)
	{
		clearScreen();
		//open a menu
		printf("    _________________________________________________________________\n");
		printf("   |                                                                 |\n");
		printf("   |          REMOVE ACCOUNT #%03d                                    |\n",
			acc[index].accountNumber);
		printf("   |_________________________________________________________________|\n");
		printf("   |                                                                 |\n");
		printf("   |          Account                %30s  |\n",
			acc[index].accountType);
		printf("   |          Email                  %30s  |\n",
			acc[index].accountEmail);
		printf("   |          Login                  %30s  |\n",
			acc[index].userLogin);
		printf("   |          Password               %30s  |\n",
			acc[index].userPassword);
		printf("   |          Name                   %30s  |\n",
			acc[index].firstName);
		printf("   |          Phone Number           %30s  |\n",
				acc[index].phoneNumber);
		printf("   |          Date of Birth                              %10s  |\n",
				acc[index].birthDate);
		printf("   |          Security (unavailable)                                 |\n");
		printf("   |                                                                 |\n");
		printf("   |          ARE YOU SURE YOU WANT TO REMOVE THIS ACCOUNT?  (Y/N)   |\n");
		printf("   |_________________________________________________________________|\n");
		printf("\n\n              Selection: ");
		input = getCharOption(string);

		if(input == 'Y' || input == 'y')
		{
			acc[index] = tempAcc;
			sec[index] = tempSec;
			printf("\n              ACCOUNT REMOVED\n");
			hang();
			clearScreen();
		}
		
		else
		{
			printf("\n              CANCELED\n");
			hang();
			clearScreen();
		}
	}


}
//display all accounts
void displayAllAccounts(const struct Accounts * acc, int arrSize, const struct Security * sec)
{
	int i, toPrint[MAX_ACC_ARR + 1] = {0}, counter = 0;
	
	for(i = 0; i < arrSize; i++)
	{
		toPrint[i] = -1;
		if(acc[i].accountNumber != 0)
		{
			toPrint[counter] = i;
			counter++;
		}
	}

	printf("    ________________________________________________________________________\n");
	printf("   |                                                                        |\n");
	printf("   |                        DISPLAYING ALL ACCOUNTS                         |\n");

	for(i = 0; toPrint[i] != -1; i+=2)
	{
		if(acc[toPrint[i+1]].accountNumber)
		{
			printf("   |________________________________________________________________________|\n");
			printf("   |                                                                        |\n");
			printf("   |  ACNT#: %03d                           |  %03d                           |\n",
				acc[toPrint[i]].accountNumber,acc[toPrint[i+1]].accountNumber);
			printf("   |  ACNT : %-30s|  %-30s|\n",
				acc[toPrint[i]].accountType,acc[toPrint[i+1]].accountType);
			printf("   |  EMAIL: %-30s|  %-30s|\n",
				acc[toPrint[i]].accountEmail,acc[toPrint[i+1]].accountEmail);
			printf("   |  LOGIN: %-30s|  %-30s|\n",
				acc[toPrint[i]].userLogin,acc[toPrint[i+1]].userLogin);
			printf("   |  PASWD: %-30s|  %-30s|\n",
				acc[toPrint[i]].userPassword,acc[toPrint[i+1]].userPassword);
			printf("   |  NAME : %-30s|  %-30s|\n",
				acc[toPrint[i]].firstName,acc[toPrint[i+1]].firstName);
			printf("   |  PHONE: %-30s|  %-30s|\n",
				acc[toPrint[i]].phoneNumber,acc[toPrint[i+1]].phoneNumber);
			printf("   |  D.O.B: %-30s|  %-30s|\n",
				acc[toPrint[i]].birthDate,acc[toPrint[i+1]].birthDate);
		}
		else
		{
			printf("   |________________________________________________________________________|\n");
			printf("   |                                                                        |\n");
			printf("   |  ACNT#: %03d                           |                                |\n",
				acc[toPrint[i]].accountNumber);
			printf("   |  ACNT : %-30s|                                |\n",
				acc[toPrint[i]].accountType);
			printf("   |  EMAIL: %-30s|                                |\n",
				acc[toPrint[i]].accountEmail);
			printf("   |  LOGIN: %-30s|                                |\n",
				acc[toPrint[i]].userLogin);
			printf("   |  PASWD: %-30s|                                |\n",
				acc[toPrint[i]].userPassword);
			printf("   |  NAME : %-30s|                                |\n",
				acc[toPrint[i]].firstName);
			printf("   |  PHONE: %-30s|                                |\n",
				acc[toPrint[i]].phoneNumber);
			printf("   |  D.O.B: %-30s|                                |\n",
				acc[toPrint[i]].birthDate);

		}
	}
	
	printf("   |________________________________________________________________________|\n");

	clearStandardInputBuffer();
	hang();
	clearScreen();
}


//display a current account to the user
void displayCurrentAccount(struct Accounts acc, struct Security sec)
{
	clearScreen();
	//open a menu
	printf("    _________________________________________________________________\n");
	printf("   |                                                                 |\n");
	printf("   |          NEW ACCOUNT #%03d                                       |\n",
		acc.accountNumber);
	printf("   |_________________________________________________________________|\n");
	printf("   |                                                                 |\n");
	printf("   |          Account                %30s  |\n",
		acc.accountType);
	printf("   |          Email                  %30s  |\n",
		acc.accountEmail);
	printf("   |          Login                  %30s  |\n",
		acc.userLogin);
	printf("   |          Password               %30s  |\n",
		acc.userPassword);
	printf("   |          Name                   %30s  |\n",
		acc.firstName);
	printf("   |          Phone Number           %30s  |\n",
		acc.phoneNumber);
	printf("   |          Date of Birth                              %10s  |\n",
		acc.birthDate);
	printf("   |          Security (unavailable)                                 |\n");
	printf("   |_________________________________________________________________|\n");
}


//search for the next free slot to store account
int findNewAccountIndex(const struct Accounts * acc, int arrSize)
{
	int index = -1, i = 0;
	for( i = 0; i < arrSize; i++)
	{
		if(!acc[i].accountNumber)
		{
			index = i;
			i = arrSize;
		}
		else
		{
			index = -1;
		}
	}
	
	return index;
}

//generates a new account number for a new account
int accountNumberGenerator(const struct Accounts acc[], int arrSize)
{
	int accountNumber = 0, i;
	
	//find the next free array position and increment i, which will be the acc num
	//currently acc nums are index positions
	for(i = 1; (i - 1 < arrSize); i++)
	{
		if((acc[i - 1].accountNumber == '\0'))
		{
			accountNumber = i;
			i = arrSize;
		}
	}
	
	return accountNumber;
}

//prompts the user to provide an account number and searchs the array for a matching position
int findIndexByAccNumber(const struct Accounts acc[], int arrSize)
{
	int accNumber = 0, index = -1, i;

	printf("              Please enter an account number (0 - cancel): ");
	accNumber = getPositiveIntegerZeroUp();
	
	//find the account position
	if(accNumber != 0)
	{	
		//search the array for a matching account number
		for(i = 0; i < arrSize; i++)
		{
		
			//if a match is found, record the index position
			if(acc[i].accountNumber == accNumber)
			{
				index = i;
				i = arrSize;
			}
		}

		//account found
		if(index >= 0)
		{
			return index;
		}
		//account not found
		else
		{
			return -1;
		}
	}
	//user chose to cancel, return to previous menu
	else
	{
		return -2;
	}
}

//load accounts from file into array
void loadAccounts(struct Accounts acc[], int arrSize, struct Security sec[])
{
	int i = 0;
	FILE * fp = fopen("passwords.txt", "r");

	//check if the file exists
	if(!fp)
	{
		clearScreen();
		printf("\n\n   ERROR: The file could not be opened!\n\n");
		printf("   A new file will be created within this programs main directory\n");
		printf("   upon saving at the end of this session.\n\n");
		
		printf("   If a backup has been created, please place it within the programs\n");
		printf("   main directory, and rename it to \"passwords.txt\". Then exit the\n");
		printf("   program without saving.\n\n");
		hang();
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%u,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],",
				&acc[i].accountNumber, acc[i].accountType, acc[i].accountEmail,
				acc[i].userLogin, acc[i].userPassword, acc[i].firstName,
				acc[i].phoneNumber, acc[i].birthDate);
				i++; //here so that this function returns the number of accounts loaded
		}

		fclose(fp);
		fp = NULL;
	}
}

//save accounts from array into file
void saveAccounts(struct Accounts acc[], int arrSize, struct Security sec[])
{
	int i = 0;
	FILE * fp = fopen("passwords.txt", "w");

	//check if the file exists
	if(!fp)
	{
		printf("\n\nERROR: The file could not be open!\n\n");
		hang();
	}
	else
	{
		while(acc[i].accountNumber)
		{
			fprintf(fp, "%u,%s,%s,%s,%s,%s,%s,%s,\n",
				acc[i].accountNumber, acc[i].accountType, acc[i].accountEmail,
				acc[i].userLogin, acc[i].userPassword, acc[i].firstName,
				acc[i].phoneNumber, acc[i].birthDate);
				i++;
		}

		fclose(fp);
		fp = NULL;
	}
}

//exit the program, ask the user to save or discard changes
void exitSequence(struct Accounts acc[], int arrSize, struct Security sec[])
{
	char string[4] = "YyNn", save;

	//open a menu
	printf("    _________________________________________________________________\n");
	printf("   |                                                                 |\n");
	printf("   |          EXIT THE PASSWORD MANAGER                              |\n");
	printf("   |_________________________________________________________________|\n");
	printf("   |                                                                 |\n");
	printf("   |          WOULD YOU LIKE TO SAVE YOUR CHANGES?  (Y/N)            |\n");
	printf("   |_________________________________________________________________|\n");
	printf("\n\n              Selection: ");
	save = getCharOption(string);

	if(save == 'Y' || save == 'y')
	{
		saveAccounts(acc, MAX_ACC_ARR, sec);
		printf("\n              CHANGES SAVED\n");
		hang();
		clearScreen();
	}
	
	else
	{
		printf("\n              CHANGED UNSAVED\n");
		hang();
		clearScreen();
	}
}
