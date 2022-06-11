#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = 1;

	char idStr[20];
	char nombreStr[50];
	char apellidoStr[50];
	char precioStr[20];
	char tipoPasajeroStr[50];
	char codigoVueloStr[8];
	char estadoVueloStr[50];

	char buffer[500];

	fscanf(pFile,"%[^\n]", buffer);
	while(!feof(pFile))
	{
			int validador = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);
			if(validador == 7)
			{
				Passenger* passenger = Passenger_newParametrosStr(idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
				if(passenger != NULL)
				{
					ll_add(pArrayListPassenger, passenger);
				}
			}
			else
			{
				rtn = -1;
			}
	}
    return rtn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = 1;

	Passenger* passenger;

	while(!feof(pFile))
	{
		passenger = Passenger_new();
		fread(passenger, sizeof(Passenger),1, pFile);
		if(feof(pFile))
		{
			break;
		}
		ll_add(pArrayListPassenger, passenger);
	}
    return rtn;
}
