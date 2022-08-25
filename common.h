
	/********************************************\
	|  PASSWORD MANAGING SYSTEM		     |
	|		    M  D  Y		     |
	|  Date Created   : 12 08 21		     |
	|  Software Vers  : alpha 0.01		     |
	|********************************************|
	|  Creator  Name  : Aaron Meek		     |
	|  Constact Email : aaronmeek16@outlook.com  |
	\********************************************/

#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>

void clearStandardInputBuffer(void);
long int getInteger(void);
long int getPositiveInteger(void);
long int getPositiveIntegerZeroUp(void);
int getIntFromRange(int min, int max);
char getCharOption(char string[]);
void clearScreen(void);
void hang(void);
void intToString(int intVal, char * stringInt);

#endif // ! COMMON_H_
