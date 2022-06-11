#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int IsDigit(char* string)
{
	int isDigit = -1;

	int large = strlen(string);

	for(int i = 0; i <large; i++)
	{
		if((string[i] <=  '9' && string[i] >= '0')||(string[i] == '-' && i == 0))
		{
			isDigit = 1;
		}
		else
		{
			isDigit = 0;
			break;
		}
	}
	return isDigit;
}

int IsLetter(char* string)
{
	int isLetter;
	isLetter = -1;

	if(string != NULL)
	{
		int len = strlen(string);
		char auxStr[len+1];

		strcpy(auxStr,strlwr(string));

		isLetter = 1;

		for(int i = 0; i < len-1; i++)
		{
			if(auxStr[i]<'a' || auxStr[i]>'z')
			{
				isLetter = -1;
				break;
			}
		}
	}
	return isLetter;
}

int DoesntHaveAnyNumber(char* string)
{
	int rtn;
	rtn = -1;

	int large = strlen(string);

	for(int i = 0; i < large; i++)
	{
		if(string[i] <=  '9' && string[i] >= '0')
		{
			rtn = 0;
			break;
		}
		else
		{
			rtn = 1;
		}
	}
	return rtn;
}

int IsFloatDigit(char* string)
{
	int isDigit = -1;
	int comma = 0;
	int flagSign = 0;
	int large = strlen(string);  // - FLAG SIGN 1, -,

	for(int i = 0; i < large; i++)
	{
		if((string[i] <=  '9' && string[i] >= '0') || (string[i] == '.' && comma == 0 && i != flagSign) || (string[i] == '-' && i == 0))
		{
			if(string[i] == '.')
			{
				comma++;
			}
			if(string[i] == '-')
			{
				flagSign++;
			}
			isDigit = 1;
		}
		else
		{
			isDigit = 0;
			break;
		}
	}
	return isDigit;
}

int setRangeInt(int* number, int min, int max, char* message, char* messageError)
{
	int auxReturn = -1;
	int flagError = 0;
	char auxNumber[40];

	if(message!= NULL && messageError != NULL && number != NULL && min <= max)
	{
		do{
			int isDigit = 0;
			int auxNumberInt;

			if(flagError == 0)
			{
				printf("%s", message);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}
			else
			{
				printf("%s", messageError);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}

			isDigit = IsDigit(auxNumber);

			if(isDigit == 1)
			{
				auxNumberInt = atoi(auxNumber);
				if(auxNumberInt >= min && auxNumberInt <= max)
				{
					*number = auxNumberInt;
					auxReturn = 1;
				}else
				{
					flagError = 1;
				}
			}
			else
			{
				flagError = 1;
			}
		}while(auxReturn == -1);
	}
	return auxReturn;
}

int setInt(int* number, char* message, char* messageError)
{
	int auxReturn = -1;
	int flagError = 0;
	char auxNumber[40];

	if(message!= NULL && messageError != NULL && number != NULL)
	{
		do{
			int isDigit = 0;

			if(flagError == 0)
			{
				printf("%s", message);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}
			else
			{
				printf("%s", messageError);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}

			isDigit = IsDigit(auxNumber);

			if(isDigit == 1)
			{
				*number = atoi(auxNumber);
			}else
			{
				flagError = 1;
			}
		}while(auxReturn == -1);
	}
	return auxReturn;
}

int setRangeIntTries(int* number, int min, int max, char* message, char* messageError, int tries)
{
	int auxReturn = -1;
	int flagError = 0;
	char auxNumber[40];

	if(message!= NULL && messageError != NULL && number != NULL && min <= max && tries >= 1)
	{
		do{
			int isDigit = 0;
			int auxNumberInt;

			if(flagError == 0)
			{
				printf("%s", message);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}else{
				printf("(%d more try) %s", tries, messageError);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}

			isDigit = IsDigit(auxNumber);

			if(isDigit == 1)
			{
				auxNumberInt = atoi(auxNumber);
				if(auxNumberInt >= min && auxNumberInt <= max)
				{
					*number = auxNumberInt;
					auxReturn = 1;
				}else
				{
					flagError = 1;
				}
			}
			else
			{
				flagError = 1;
			}
			tries--;
		}while(auxReturn == -1  && tries > 0);
	}

	if(tries == 0 && auxReturn == -1)
	{
		auxReturn = 0;
	}
	return auxReturn;
}

int setFloatRange(float* number, float min, float max, char* message, char* messageError)
{
	int auxReturn = -1;
	int flagError = 0;
	char auxNumber[40];

	if(message!= NULL && messageError != NULL && number != NULL && min <= max)
	{
		do{
			int isDigit = 0;
			int comma = 0;
			float auxNumberFloat;

			if(flagError == 0)
			{
				printf("%s", message);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}
			else
			{
				printf("%s", messageError);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}

			if((isDigit = IsFloatDigit(auxNumber)) == 1)
			{
				auxNumberFloat = atof(auxNumber);
				if(auxNumberFloat >= min && auxNumberFloat <= max && (comma == 0 || comma == 1))
				{
					*number = auxNumberFloat;
					auxReturn = 1;
				}
				else
				{
					flagError = 1;
				}
			}
			else
			{
				flagError = 1;
			}
		}while(auxReturn == -1);
	}
		return auxReturn;
}

int setFloat(float* number, char* message, char* messageError)
{
	int auxReturn = -1;
	int flagError = 0;
	char auxNumber[40];

	if(message!= NULL && messageError != NULL && number != NULL)
	{
		do{
			int isDigit = 0;

			if(flagError == 0)
			{
				printf("%s", message);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}
			else
			{
				printf("%s", messageError);
				fflush(stdin);
				scanf("%40[^\n]", auxNumber);
			}

			if((isDigit = IsFloatDigit(auxNumber)) == 1)
			{
				*number = atof(auxNumber);
				auxReturn = 1;
			}
			else
			{
				flagError = 1;
			}
		}while(auxReturn == -1);
	}
		return auxReturn;
}

int setString(char* string, int size, char* message, char* errorMessage)
{

	int returnAux = -1;

	if(string != NULL && size > 0 && message != NULL && errorMessage != NULL)
	{
		char auxString[size + 100];

			int x = 0;
			int flag = 0;

			do{
				if(flag == 0)
				{
					printf("%s", message);
					fflush(stdin);
					fgets(auxString,size,stdin);
				}else{
					printf("%s", errorMessage);
					fflush(stdin);
					fgets(auxString,size,stdin);
				}

				x = strlen(auxString);
				flag = 1;

			}while(x > size || auxString[0] == '\n');

			auxString[x-1] = '\0';

			strcpy(string, auxString);
			returnAux = 1;
	}
	return returnAux;
}

int setStringTries(char* string, int size, int tries, char* message, char* errorMessage)
{
	int returnAux = -1;
	if(string != NULL && size > 0 && tries > 0 && message != NULL && errorMessage != NULL)
	{
		char auxString[size + 200];

		int x = 0;
		int flag = 0;

		do{
			if(flag == 0)
			{
				printf("%s", message);
				fflush(stdin);
				fgets(auxString,size,stdin);
			}
			else
			{
				printf("%s", errorMessage);
				fflush(stdin);
				fgets(auxString,size,stdin);
			}
			x = strlen(auxString);
			flag = 1;
			tries --;

		}while((x > size || auxString[0] == '\n') && tries < 0);


		if(strlen(auxString) < size)
		{
			auxString[x-1] = '\0';
			strcpy(string, auxString);
			returnAux = 1;
		}
	}
	return returnAux;
}

int setName(char* string, int size, char* message, char* errorMessage)
{
	int rtn = -1;

	if(string != NULL && size > 0 && message != NULL && errorMessage != NULL)
	{
		char auxString[size];
		int flag = 0;
		int x;
		int isLetter;

		do{
			if(flag == 0)
			{
				printf("%s", message);
				fflush(stdin);
				fgets(auxString,size+1,stdin);
			}else
			{
				printf("%s", errorMessage);
				fflush(stdin);
				fgets(auxString,size+1,stdin);
			}
			x = strlen(auxString);
			flag = 1;
			isLetter = IsLetter(auxString);

		}while(x >= size || auxString[0] == '\n' || isLetter == -1);

		rtn = 1;
		strcpy(string,strlwr(auxString));
		string[0] = toupper(string[0]);
		string[(strlen(string)-1)] = '\0';
	}
	return rtn;
}

void validator(int number, char* actionMessage)
{
	if(number == 1)
	{
		printf("\nEXITO AL %s.\n\n", actionMessage);
	}
	else
	if(number == 0)
	{
		printf("\nSE HA CANCELADO %s.\n\n", actionMessage);
	}
	else
	{
		printf("\nERROR AL %s.\n\n", actionMessage);
	}
	system("pause");
	fflush(stdin);
}

void validatorWithMessageError(int number, char* actionMessage, char* errorActionMessage)
{
	if(number >= 1)
	{
			printf("\nEXITO AL %s.\n\n", actionMessage);
		}
		else
		if(number == 0)
		{
			printf("\nSE HA CANCELADO %s.\n\n", actionMessage);
		}
		else
		{
			printf("\n%s.\n\n", errorActionMessage);
		}

		system("pause");
}
