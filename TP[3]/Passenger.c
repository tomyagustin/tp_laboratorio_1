#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Funciones.h"

void menu()
{
    printf("Menu:\n");
    printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n");
}

Passenger* Passenger_new()
{
	Passenger* passenger;
	passenger = (Passenger*) calloc(1,sizeof(Passenger));

	return passenger;
}

Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo)
{
	Passenger* passenger = Passenger_new();

	int validator;
	validator = 1;

	if(passenger!= NULL){

		if(Passenger_setId(passenger, id) == -1)
		{
			validator = -1;
		}

		if(Passenger_setNombre(passenger, nombre) == -1)
		{
			validator = -1;
		}

		if(Passenger_setApellido(passenger, apellido) == -1)
		{
			validator = -1;
		}

		if(Passenger_setPrecio(passenger, precio) == -1)
		{
			validator = -1;
		}

		if(Passenger_setTipoPasajero(passenger, tipoPasajero) == -1)
		{
			validator = -1;
		}

		if(Passenger_setCodigoVuelo(passenger, codigoVuelo) == -1)
		{
			validator = -1;
		}

		if(Passenger_setEstadoVuelo(passenger, estadoVuelo) == -1)
		{
			validator = -1;
		}
	}
	if(validator == -1)
	{
		free(passenger);
	}
	return passenger;
}

Passenger* Passenger_newParametrosStr(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char*codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	int id;
	float precio;
	int tipoPasajero;
	int estadoVuelo;
	Passenger* passenger;

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL)
	{
		id = atoi(idStr);
		precio = atof(precioStr);

		Passenger_tipoStrToInt(tipoPasajeroStr, &tipoPasajero);
		Passenger_estadoStrToInt(estadoVueloStr, &estadoVuelo);

		passenger = Passenger_newParametros(id, nombreStr, apellidoStr, precio, codigoVueloStr, tipoPasajero, estadoVuelo);
	}
	return passenger;
}

int Passenger_tomarDatos(Passenger* pasajero,LinkedList* pArrayListPassenger)
{
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxCodigoVuelo[8];
	int auxTipoPasajero;
	int auxEstadoVuelo;

	auxId = controller_loadMaxId("maxid.csv",pArrayListPassenger);
	auxId++;
	setName(auxNombre, 50, "Ingrese nombre: ", "ERROR. Reingrese nombre: ");
	setName(auxApellido, 50, "Ingrese apellido: ", "ERROR. Reingrese apellido: ");
	setFloat(&auxPrecio, "Ingrese precio: ", "ERROR. Reingrese precio: ");
	setString(auxCodigoVuelo, 8, "Ingrese codigo de vuelo: ", "ERROR. Reingrese codigoVuelo: ");
	printTipoPasajero();
	setRangeInt(&auxTipoPasajero, 1,3, "Ingrese tipo pasajero: ", "ERROR. Reingrese tipo pasajero: ");
	printEstadoVuelo();
	setRangeInt(&auxEstadoVuelo, 1,4, "Ingrese estado vuelo: ", "ERROR. Reingrese estado vuelo: ");

	Passenger_setId(pasajero,auxId);
	Passenger_setNombre(pasajero,auxNombre);
	Passenger_setApellido(pasajero,auxApellido);
	Passenger_setPrecio(pasajero,auxPrecio);
	Passenger_setCodigoVuelo(pasajero,auxCodigoVuelo);
	Passenger_setTipoPasajero(pasajero,auxTipoPasajero);
	Passenger_setEstadoVuelo(pasajero,auxEstadoVuelo);

	controller_saveMaxId("maxid.csv",pArrayListPassenger,auxId);
	return 1;
}

int Passenger_searchByID(LinkedList* listaPasajeros)
{
	int rtn;
	rtn = -1;

	int id;
	int id2;

	setInt(&id,"Ingresa el ID a buscar: ","ERROR. Reingrese devuelta el ID por favor: " );
	if(listaPasajeros != NULL)
	{
		int len = ll_len(listaPasajeros);
		for(int i=0;i<len;i++)
		{
			Passenger* aux = ll_get(listaPasajeros,i);
			Passenger_getId(aux,&id2);
			if(id2 == id)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int Passenger_tipoStrToInt(char* tipoPasajeroStr, int* tipoPasajero)
{
	int rtn;
	rtn = -1;

	if(tipoPasajeroStr != NULL && tipoPasajero != NULL)
	{
		if(strcmp(tipoPasajeroStr,"FirstClass") == 0)
		{
			*tipoPasajero = 1;
			rtn = 1;
		}
		else
		if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0)
		{
			*tipoPasajero = 2;
			rtn = 1;
		}
		else
		if(strcmp(tipoPasajeroStr, "EconomyClass") == 0)
		{
			*tipoPasajero = 3;
			rtn = 1;
		}
		if(rtn == -1)
		{
			rtn = 0;
		}
	}
	return rtn;
}

int Passenger_tipoIntToStr(char* tipoPasajeroStr, int* tipoPasajero)
{
	int rtn;
	rtn = -1;

	if(tipoPasajeroStr != NULL && tipoPasajero != NULL)
	{
		if(*tipoPasajero == 1)
		{
			strcpy(tipoPasajeroStr, "FirstClass");
		}
		else
		if(*tipoPasajero == 2)
		{
			strcpy(tipoPasajeroStr, "ExecutiveClass");
		}
		else
		if(*tipoPasajero == 3)
		{
			strcpy(tipoPasajeroStr, "EconomyClass");
		}
		if(rtn == -1)
		{
			rtn = 0;
		}
	}

	return rtn;
}

int Passenger_estadoStrToInt(char* estadoVueloStr, int* estadoVuelo)
{
	int rtn;
	rtn = -1;

	if(estadoVueloStr != NULL && estadoVuelo != NULL)
	{
		if(strcmp(estadoVueloStr,"Aterrizado") == 0)
		{
			*estadoVuelo = 1;
			rtn = 1;
		}
		else
		if(strcmp(estadoVueloStr, "A tiempo") == 0)
		{
			*estadoVuelo = 2;
			rtn = 1;
		}
		else
		if(strcmp(estadoVueloStr, "En vuelo") == 0)
		{
			*estadoVuelo = 3;
			rtn = 1;
		}
		else
		if(strcmp(estadoVueloStr, "Demorado") == 0)
		{
			*estadoVuelo = 4;
			rtn = 1;
		}
		if(rtn == -1)
		{
			rtn = 0;
		}
	}
	return rtn;
}
int Passenger_estadoIntToStr(char* estadoVueloStr, int* estadoVuelo)
{
	int rtn;
	rtn = -1;

	if(estadoVueloStr != NULL && estadoVuelo != NULL)
	{
		if(*estadoVuelo == 1)
		{
			strcpy(estadoVueloStr, "Aterrizado");
		}
		else
		if(*estadoVuelo == 2)
		{
			strcpy(estadoVueloStr, "En Horario");
		}
		else
		if(*estadoVuelo == 3)
		{
			strcpy(estadoVueloStr, "En Vuelo");
		}
		else
		if(*estadoVuelo == 4)
		{
			strcpy(estadoVueloStr, "Demorado");
		}
		if(rtn == -1)
		{
			rtn = 0;
		}
	}
	return rtn;
}

int Passenger_compareByName(void* passenger, void* passenger2)
{
		char nombre[50];
		char nombre2[50];

		Passenger* aux = passenger;
		Passenger* aux2 = passenger2;

		Passenger_getNombre(aux,nombre);
		Passenger_getNombre(aux2,nombre2);

		int cmp = strcmp(nombre,nombre2);

		if(cmp == 0)
		{
			cmp = Passenger_compareByLastName(passenger, passenger2);
		}

		return cmp;
}

int Passenger_compareByLastName(void* passenger, void* passenger2)
{
	char apellido[50];
	char apellido2[50];

	Passenger* aux = passenger;
	Passenger* aux2 = passenger2;

	Passenger_getApellido(aux,apellido);
	Passenger_getApellido(aux2,apellido2);

	return strcmp(apellido,apellido2);
}

int Passenger_compareById(void* passenger, void* passenger2)
{
	Passenger* aux = passenger;
	Passenger* aux2 = passenger2;

	int rtn;

	int id;
	int id2;

	Passenger_getId(aux,&id);
	Passenger_getId(aux2,&id2);

	if(id<id2)
	{
		rtn = 1;
	}
	else
	if(id>id2)
	{
		rtn = -1;
	}
	else
	{
		rtn = 0;
	}

	return rtn;
}

int Passenger_printOne(Passenger* passenger)
{
	int rtn;
	rtn = -1;

	if(passenger != NULL)
	{
		int id;
		char nombre[50];
		char apellido[50];
		float precio;
		char codigoVuelo[8];

		int tipoPasajero;
		char tipoPasajeroStr[50];

		int estadoVuelo;
		char estadoVueloStr[50];

		Passenger_getId(passenger, &id);
		Passenger_getNombre(passenger,nombre);
		Passenger_getApellido(passenger,apellido);
		Passenger_getPrecio(passenger, &precio);
		Passenger_getCodigoVuelo(passenger, codigoVuelo);


		Passenger_getTipoPasajero(passenger, &tipoPasajero);
		Passenger_tipoIntToStr(tipoPasajeroStr, &tipoPasajero);

		Passenger_getEstadoVuelo(passenger, &estadoVuelo);
		Passenger_estadoIntToStr(estadoVueloStr, &estadoVuelo);

		printf("%8d %20s %20s %10.2f %13s %20s %20s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajeroStr, estadoVueloStr);

		rtn = 1;
	}
	return rtn;
}
int Passenger_printAll(LinkedList* listaPasajeros)
{

	int rtn;
	rtn = -1;
	int len = ll_len(listaPasajeros);

	if(listaPasajeros != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			Passenger* passenger = ll_get(listaPasajeros, i);
			Passenger_printOne(passenger);
		}
	}

	return rtn;
}

int Passenger_setId(Passenger* this,int id)
{
	int rtn;
	rtn = -1;
	if(this!= NULL)
	{
		this->id = id;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getId(Passenger* this,int* id)
{
	int rtn;
	rtn = -1;
	if(this!= NULL)
	{
		*id = this->id;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int rtn;
	rtn = -1;
	if(this!= NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int rtn;
	rtn = -1;
	if(this!= NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		rtn = 1;
	}

	return rtn;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int rtn;
	rtn = -1;
	if(this!= NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		rtn = 1;
	}

	return rtn;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int rtn;
	rtn = -1;
	if(this!= NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		rtn = 1;
	}
	return rtn;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int rtn;
	rtn = -1;
	if(this!= NULL)
	{
		this->precio = precio;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
	int rtn;
	rtn = -1;
	if(this != NULL)
	{
		*precio = this->precio;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn;
	rtn = -1;
	if(this!= NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn;
	rtn = -1;
	if(this!= NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		rtn = 1;
	}
	return rtn;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int rtn;
	rtn = -1;
	if(this!= NULL)
	{
		this->tipoPasajero = tipoPasajero;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int rtn;
	rtn = -1;
	if(this!= NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int rtn;
	rtn = -1;
	if(this!= NULL)
	{
		this->estadoVuelo = estadoVuelo;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{
	int rtn;
	rtn = -1;
	if(this!= NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		rtn = 1;
	}
	return rtn;
}

void printTipoPasajero(void)
{
	printf("\n1. FirstClass\n");
	printf("2. ExecutiveClass\n");
	printf("3. EconomyClas\n");
}

void printEstadoVuelo(void)
{
	printf("\n1. Aterrizando\n");
	printf("2. En Horarion\n");
	printf("3. En Vuelo\n");
	printf("4. Demorado\n");
}

int Passenger_getMaxId(FILE* pFile,LinkedList* pArrayListPassenger)
{
	char auxId[50];
	int id;
	int id2;
	int len = ll_len(pArrayListPassenger);

	fscanf(pFile,"%[^,]",auxId);
	id = atoi(auxId);

	for(int i=0;i<len;i++)
	{
		Passenger* aux = ll_get(pArrayListPassenger,i);
		Passenger_getId(aux,&id2);
		if(id2>id)
		{
			id = id2;
		}
	}
	return id;
}
