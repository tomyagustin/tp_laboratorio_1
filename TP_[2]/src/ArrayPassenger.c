#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

int obtenerID()
{
	static int idIncremental = 1000;
    return idIncremental++;
}

int initPassengers(ePassenger list[],int size)
{
	int index = -1;
	if(list!= NULL && size > 0)
	{
		index = 0;
		for(int i=0;i<size;i++)
		{
			list[i].isEmpty = VACIO;
		}
	}
	return index;
}

int addPassenger(ePassenger list[],int size,int id,char name[],char lastName[],float price,int typePassenger,char flyCode[],int statusFlight)
{
	int espacio;

	espacio = busquedaLibre(list,size);

	if(espacio!=-1)
	{
		list[espacio].id = id;
		strcpy(list[espacio].name,name);
		strcpy(list[espacio].lastName,lastName);
		list[espacio].price = price;
		strcpy(list[espacio].flyCode,flyCode);
		list[espacio].typePassenger = typePassenger;
		list[espacio].isEmpty = FULL;
		list[espacio].statusFlight = statusFlight;
	}

	return espacio;
}

int findPassengerById(ePassenger list[],int size,int id)
{
	int respuesta;

	for(int i;i<size;i++)
	{
		if(list[i].id == id)
		{
			respuesta = id;
			break;
		}
	}
	return respuesta;
}

int removePassenger(ePassenger list[],int size,int id)
{
	int respuesta;

	respuesta = 0;

	for(int i;i<size;i++)
	{
		if(list[i].id == id)
			{
				list[i].isEmpty = VACIO;
				respuesta=1;
				break;
			}
	}
	return respuesta;
}

int printPassenger(ePassenger list[],int size)
{
	int respuesta;
	int print;

	respuesta= -1;
	print = 0;

	for(int i;i<size;i++)
	{
		if(list[i].isEmpty == FULL)
		{
			mostrar(list[i]);
			print++;
		}
	}
	if(print > 0)
	{
		respuesta = 0;
	}
	return c;
}

int sortPassengers(ePassenger list[],int size,int order)
{
    ePassenger AuxiliarPasajero;
    int retorno;

    retorno = -1;

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(((list[i].typePassenger==list[j].typePassenger) && strcmp(list[i].lastName,list[j].lastName)>0 && order==1)
                        (list[i].typePassenger>list[j].typePassenger && order==1)
                     ((list[i].typePassenger== list[j].typePassenger) && strcmp(list[i].lastName,list[j].lastName)<0 && order==0)||
                     (list[i].typePassenger <list[j].typePassenger && order==0))
            {
            	AuxiliarPasajero=list[i];
                list[i]=list[j];
                list[j]=AuxiliarPasajero;
                retorno=0;
            }
        }

    }

    return retorno;

}

int sortPassengersByCode(ePassenger list[],int tam, int order)
{
	ePassenger AuxiliarPasajero;
	    int retorno;

	    retorno = -1;
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(((list[i].statusFlight==list[j].statusFlight) && strcmp(list[i].flyCode,list[j].flyCode)>0 && order==1)
                        (list[i].statusFlight>list[j].statusFlight&& order==1)
                       ((list[i].statusFlight== list[j].statusFlight) && strcmp(list[i].flyCode,list[j].flyCode)<0 && order==0)
                       ||(list[i].statusFlight <list[j].statusFlight && order==0))
            {
            	AuxiliarPasajero=list[i];
                list[i]=list[j];
                list[j]=AuxiliarPasajero;
                retorno=0;
            }
        }
    }
    return retorno;
}
