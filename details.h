
	/********************************************\
	|  PASSWORD MANAGING SYSTEM		     |
	|		    M  D  Y		     |
	|  Date Created   : 12 08 21		     |
	|  Software Vers  : alpha 0.01		     |
	|********************************************|
	|  Creator  Name  : Aaron Meek		     |
	|  Constact Email : aaronmeek16@outlook.com  |
	\********************************************/

#ifndef DETAILS_H_
#define DETAILS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "account.h"

void changeAccType(char * accType);
void changeAccEmail(char * accEmail);
void changeAccLogin(char * accLogin);
void changeAccPass(char * accPassword);
void changeAccName(char * accFirstName);
void changeAccPhone(char * accPhone);
void changeAccDOB(char * dateOfBirth);
void changeAccSec(char * secType, char * recQuestion1, char * recQuestion2, char * recQuestion3);

#endif // ! DETAILS_H_
