
	/********************************************\
	|  PASSWORD MANAGING SYSTEM		     |
	|		    M  D  Y		     |
	|  Date Created   : 12 08 21		     |
	|  Software Vers  : alpha 0.01		     |
	|********************************************|
	|  Creator  Name  : Aaron Meek		     |
	|  Constact Email : aaronmeek16@outlook.com  |
	\********************************************/

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <stdio.h>
#include "common.h"
#include "details.h"

//max accounts array size
#define MAX_ACC_ARR 40
//max string size
#define MAX_STRING 30
#define MAX_DOB 10

struct Security
{
	//account security type
	char secType[MAX_STRING + 1];
	char recQuestion1[MAX_STRING + 1];
	char recQuestion2[MAX_STRING + 1];
	char recQuestion3[MAX_STRING + 1];
};

//account struct
struct Accounts
{
	//to identify the account when listed
	unsigned accountNumber;
	//email, youtube, seneca, udemy, etc
	char accountType[MAX_STRING + 1];
	//email used on account
	char accountEmail[MAX_STRING + 1];
	//userlogin
	char userLogin[MAX_STRING + 1];
	//userPassword
	char userPassword[MAX_STRING + 1];
	//name on account
	char firstName[MAX_STRING + 1];
	//phone number on account
	char phoneNumber[MAX_STRING - 9];
	//birth date on account
	char birthDate[MAX_DOB + 1];
};

int mainMenu(struct Accounts acc[], int arrSize, struct Security sec[]);
void addAccount(struct Accounts acc[], int arrSize, struct Security sec[]);
void manageAccount(struct Accounts acc[], int arrSize, struct Security sec[]);
void removeAccount(struct Accounts acc[], int arrSize, struct Security sec[]);
void displayAllAccounts(const struct Accounts * acc, int arrSize, const struct Security * sec);
void displayCurrentAccount(struct Accounts acc, struct Security sec);
int findNewAccountIndex(const struct Accounts * acc, int arrSize);
int accountNumberGenerator(const struct Accounts acc[], int arrSize);
int findIndexByAccNumber(const struct Accounts acc[], int arrSize);
void loadAccounts(struct Accounts acc[], int arrSize, struct Security sec[]);
void saveAccounts(struct Accounts acc[], int arrSize, struct Security sec[]);
void exitSequence(struct Accounts acc[], int arrSize, struct Security sec[]);

#endif // ! ACCOUNT_H_
