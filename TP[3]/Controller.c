#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Funciones.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = -1;

	FILE* pFile = fopen(path, "r");

	if(pFile != NULL && pArrayListPassenger != NULL){
		parser_PassengerFromText(pFile, pArrayListPassenger);
		rtn = 1;
	}
	fclose(pFile);
	return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = -1;

	FILE* pFile = fopen(path, "rb");

	if(pFile != NULL && pArrayListPassenger != NULL){
		rtn = 1;
		parser_PassengerFromBinary(pFile, pArrayListPassenger);
	}
	fclose(pFile);
    return rtn;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
  int rtn;
  rtn = -1;

  if(pArrayListPassenger != NULL)
  {
	  Passenger* aux = Passenger_new();
	  rtn = Passenger_tomarDatos(aux,pArrayListPassenger);
	  if(rtn == 1)
	  {
		  ll_add(pArrayListPassenger, aux);
	  }
  }
  return rtn;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger) //  devuelve 1 si pudo modificar, o -1 si no pudo modificar o no encontro el id
{
	int rtn;
	rtn = -1;
	Passenger* aux;
	if(pArrayListPassenger != NULL)
	{
	int indice = Passenger_searchByID(pArrayListPassenger);
		if(indice != -1)
		{
			aux = ll_get(pArrayListPassenger, indice);
			rtn = Passenger_tomarDatos(aux,pArrayListPassenger);
		}
	}
    return rtn;
}

/** \brief Baja de pasajero

 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = -1;
	if(pArrayListPassenger != NULL)
	{
	int indice = Passenger_searchByID(pArrayListPassenger);
		if(indice != -1)
		{
			ll_remove(pArrayListPassenger, indice);
			rtn = 1;
		}
	}
	return rtn;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = -1;
	if(pArrayListPassenger != NULL)
	{
		rtn = Passenger_printAll(pArrayListPassenger);
	}
    return rtn;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = -1;
	int option;

	if(pArrayListPassenger != NULL)
	{
		printf("\nOrdenar pasajeros\n\n");

		setRangeInt(&option, 1, 2, "1. Por nombre\n2. Por ID\nSu opcion: ", "Error. Reingrese su opcion (1-2):");

		if(option == 1)
		{
			setRangeInt(&option, 0, 1, "0. Ascendiente\n1. Descendiente\nOpcion: ", "Error. Reingrese su opcion (0-1):");
			rtn = ll_sort(pArrayListPassenger, Passenger_compareByName, option);
		}
		else
		{
			setRangeInt(&option, 0, 1, "0. Ascendiente\n1. Descendiente\nOpcion: ", "Error. Reingrese su opcion (0-1):");
			rtn = ll_sort(pArrayListPassenger, Passenger_compareById, option);
		}
	}
	if(rtn == 0)
	{
		printf("\nORDENADO CON EXTIO\n");
		system("pause");
	}
    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = -1;

	int id;
	char nombre[50];
	char apellido[50];
	float precio;

	int tipoPasajero;
	char tipoPasajeroStr[50];

	char codigoVuelo[8];

	int estadoVuelo;
	char estadoVueloStr[50];

	FILE* pFile = fopen(path, "w");

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		rtn = 1;

		int len = ll_len(pArrayListPassenger);

		printf("%d", len);

		for(int i = 0; i<len; i++)
		{
			Passenger* passenger = ll_get(pArrayListPassenger, i);

			if(passenger != NULL)
			{
				Passenger_getId(passenger, &id);
				Passenger_getNombre(passenger, nombre);
				Passenger_getApellido(passenger, apellido);
				Passenger_getPrecio(passenger, &precio);

				Passenger_getTipoPasajero(passenger, &tipoPasajero);
				Passenger_tipoIntToStr(tipoPasajeroStr, &tipoPasajero);

				Passenger_getCodigoVuelo(passenger, codigoVuelo);

				Passenger_getEstadoVuelo(passenger, &estadoVuelo);
				Passenger_estadoIntToStr(estadoVueloStr, &estadoVuelo);

				fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n", id, nombre, apellido, precio, tipoPasajeroStr, codigoVuelo, estadoVueloStr);
			}
		}
	}
	fclose(pFile);
    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = -1;

	FILE* pFile = fopen(path, "wb");

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		int len = ll_len(pArrayListPassenger);
		for(int i = 0; i < len; i++)
		{
			Passenger* passenger = ll_get(pArrayListPassenger, i);
			fwrite(passenger, sizeof(Passenger),1,pFile);
		}
		rtn = 1;
	}
	fclose(pFile);
    return rtn;
}

int controller_loadMaxId(char* path,LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn = -1;

	FILE* pFile = fopen(path,"r");
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		rtn = Passenger_getMaxId(pFile,pArrayListPassenger);
	}
	fclose(pFile);
	return rtn;
}

int controller_saveMaxId(char* path,LinkedList* pArrayListPassenger,int id)
{
	int rtn;
	rtn = -1;

	FILE* pFile = fopen(path,"w");
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fprintf(pFile,"%d",id);
		rtn = 1;

	}
	fclose(pFile);
	return rtn;
}
