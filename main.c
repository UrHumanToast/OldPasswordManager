
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
#include "details.h"
#include "common.h"

int main()
{
	struct Accounts acc[MAX_ACC_ARR + 1] = { {0} };
	struct Security sec[MAX_ACC_ARR + 1] = {0};

	loadAccounts(acc, MAX_ACC_ARR, sec);
	
	clearScreen();
	mainMenu(acc, MAX_ACC_ARR, sec);

	exitSequence(acc, MAX_ACC_ARR, sec);

	return 0;
}
