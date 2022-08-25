
	/********************************************\
	|  PASSWORD MANAGING SYSTEM		     |
	|		    M  D  Y		     |
	|  Date Created   : 12 08 21		     |
	|  Software Vers  : alpha 0.01		     |
	|********************************************|
	|  Creator  Name  : Aaron Meek		     |
	|  Constact Email : aaronmeek16@outlook.com  |
	\********************************************/

#include "common.h"

//clear the terminal screen
void clearScreen(void)
{
	#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
		system("clear");

	#else
		system("cls");
	#endif
}

//promts user to press enter to continue
void hang(void)
{
	printf("\n              *** Press Enter to Continue ***");
	while(getchar() != '\n');
}

//empty the standard input buffer 
void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{ 
		; //left empty on purpose 
	} 
}

//take a valid integer and return it
long int getInteger(void)
{
	long int integer = 0, flag = 1;
	char check;

	//enter a loop to collect inputs and validate them		
	while(flag)
	{
		//take in a user integer and character
		scanf(" %ld%c", &integer, & check);
		
		//if a character other than '\n' proceeds the integer input, print an error
		if(check != '\n')
		{
			clearStandardInputBuffer();
			printf("              ERROR: only enter an integer: ");
		}
		//exit the loop once validated
		else
		{
			flag = 0;
		}
	}
	
	return integer;
}

//take a valid positive integer and return it
long int getPositiveInteger(void)
{
	long int integer = 0, flag = 1;
	
	while(flag)
	{
		//get an integer
		integer = getInteger();

		//check if integer is positive (greater than 2 because 0 is to enter no value)
		if(integer <= 0)
		{
			printf("              ERROR: value must be greater than 1: ");
		}
		//exit the loop once validated
		else
		{
			flag = 0;
		}
	}
	
	return integer;
}

//take a valid positive integer greater than -1 and return it
long int getPositiveIntegerZeroUp(void)
{
	long int integer = 0, flag = 1;
	
	while(flag)
	{
		//get an integer
		integer = getInteger();

		//check if integer is positive (greater than 2 because 0 is to enter no value)
		if(integer < 0)
		{
			printf("              ERROR: value must be equal to or greater than 0: ");
		}
		//exit the loop once validated
		else
		{
			flag = 0;
		}
	}
	
	return integer;
}

//take an integer within a range and return it
int getIntFromRange(int min, int max)
{
	int integer, bufferCollection, flag;
	
	//get a value and record the status into the flag var	
	flag = scanf("%d", &integer);

	//enter validation loop if the value was not valid
	while(flag!=1 || (integer < min || integer > max))
	{
		//clear standard buffer input
		while((bufferCollection=getchar()) != EOF && bufferCollection != '\n');
		
		//check if the input is within range
		if (flag && (integer < min || integer > max))
		{
			printf("              ERROR: must be between %d and %d inclusive: ", min,max);  
		}
		//check if the input is an integer
		else if (!flag)
		{
			printf("              ERROR: must be an integer: ");
		}
		
		//get a value and record the status into the flag var
		flag = scanf(" %d", &integer);
	}
	
	return integer;
}


char getCharOption(char * const string)
{
	int i, j, counter, stringCounter = 0;
	//input can have any size so long as it is greater than 2
	char input[5];
	
	//count the number of chars in string
	for(i = 0; string[i] != '\0'; i++)
	{
		stringCounter++;
	}

	//for "j" loop acting as a while loop
	//takes an intput and compares it to all the letters in the string
	
	for(i = 0; i < 1; i++)
	{
	
		//initialize input initial index position (the one thats comapred)
		input[0] = '\n';		
		counter = 0;
		scanf(" %s", input);
		while(input[counter] != '\0')
		{
			counter++; //letter count
		}	
		
		
		for(j = 0; j < stringCounter; j++)
		{	
			//if a match is found, exit the loop
			if(input[0] == string[j] && counter == 1)
			{
				i++;
			}
		}
		//if no match is found, print an error
		if(i == 0)
		{	//this might have to pront as a for loop because its an array
			printf("              ERROR: Character must be one of [%s]: ", string);
			clearStandardInputBuffer();
			i--;
		}
	}
	
	clearStandardInputBuffer();
	
	return input[0];
}

//converts an integer to a string (max 9999)
void intToString(int intVal, char * string)
{
	int thou = 0, hund = 0, tens = 0, ones = 0;

//0 = 48

	ones = ((intVal)%10)/1;
	tens = ((intVal-ones)%100)/10;
	hund = ((intVal - ones - tens)%1000)/100;
	thou = ((intVal - ones - tens - hund)%10000)/1000;

	string[0] = (char)thou+48;
	string[1] = (char)hund+48;
	string[2] = (char)tens+48;
	string[3] = (char)ones+48;
	string[4] = '\0';
}
