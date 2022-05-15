#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Funciones.h"

int pedirDatos(ePassenger list[],int size)
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int validacionCaracteres;
	int index;
	id = obtenerID();
	printf("Ingresa el nombre: \n");
	fflush(stdin);
	gets(name);
	validacionCaracteres = validarCaracteres(name);
	while(validacionCaracteres == 0)
	{
		printf("Reingresa el nombre: \n");
		fflush(stdin);
		gets(name);
		validacionCaracteres = validarCaracteres(name);
	}
	printf("Ingresa el apellido: \n");
	fflush(stdin);
	gets(lastName);
	validacionCaracteres = validarCaracteres(lastName);
	while(validacionCaracteres == 0)
	{
		printf("Reingresa el apellido \n");
		fflush(stdin);
		gets(lastName);
		validacionCaracteres = validarCaracteres(lastName);
	}
	price = pedirYValidarPrecio("Ingresa el precio","ERROR. Reingresa el precio");
	printf("Ingresa el codigo del vuelo:  \n");
	fflush(stdin);
	gets(flyCode);
	printf("Ingresa el tipo de pasajero \n 1. Primera clase \n 2. Segunda clase \n 3. Turista \n");
	scanf("%d",&typePassenger);
	while(typePassenger != 1 && typePassenger != 2 && typePassenger != 3)
	{
		printf("Reingresa el tipo de pasajero \n 1. Primera clase \n 2. Segunda clase \n 3. Turista");
		scanf("%d",&typePassenger);
	}
	printf("Ingresa el estado \n 1. Cancelado \n 2. Demorado \n 3. Activo \n");
	scanf("%d",&statusFlight);
	while(statusFlight != 1 && statusFlight != 2 && statusFlight != 3)
		{
			printf("Ingresa el estado \n 1. Reprogramado \n 2. Demorado \n 3. Cancelado \n");
			scanf("%d",&typePassenger);
		}
	index = addPassenger(list,size,id,name,lastName,price,typePassenger,flyCode,statusFlight);
	return index;
}

void mostrar(ePassenger list)
{
	printf(" \n %4d \t %4s \t %4s \t %4.2f \t %4s \t %4d \t %4d \t \n",list.id,list.name,list.lastName,list.price,list.flyCode,list.typePassenger,list.statusFlight);
}

void mostrarLista(ePassenger list[],int size,eTypePassenger tipos[],int tamtipos,eStatusFlight estadoVuelo[],int tamVuelos)
{
	int i;

	printf("Mostrar lista de pasajeros: ");
	for(i=0;i<size;i++)
	{
		if(list[i].isEmpty == FULL)
		{
			mostrarConTipoYEstado(list[i], estadoVuelo, tipos);
		}
	}
}

int validarCaracteres(char cadena[])
{
    int size = strlen(cadena);
    int validacion = -1;
    for(int i=0;i<size;i++)
    {
        if (isdigit(cadena[i]))
        {
            validacion = 0;
        }
    }
    return validacion;
}

int pedirYValidarNumero(char mensaje[],char mensajeError[],int limiteInferior,int limiteSuperior)
{
    int numeroIngresado;
    printf("%s", mensaje);
    scanf("%d",&numeroIngresado);
    while(numeroIngresado<limiteInferior || numeroIngresado>limiteSuperior)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%d",&numeroIngresado);
    }
    return numeroIngresado;
}

int busquedaLibre(ePassenger list[],int size)
{
    int retorno;
    int index;

    retorno = -1;

    if(list != NULL)
    {
        if (size >= 0)
        {
            for (index = 0;index<size;index++)
            {
                if(list[index].isEmpty == VACIO)
                {
                    retorno = index;
                    break;
                }
            }
        }
    }
    return retorno;
}

int opcionModificar(ePassenger list[],int size)
{
	int seModifico;
	int id;
	int indice;
	int opcion;
	char modificarNombre[51];
	char modificarApellido[51];
	float modificarPrecio;
	int modificarTipoPasajero;
	int modificarEstado;
	int validacionCaracteres;
	char name[51];
	char lastName[51];
	ePassenger modificar;

	seModifico = -1;

	if(list != NULL && size > 0)
	{

		printf("Ingrese la ID a modificar");
		scanf("%d",&id);
		indice = findPassengerById(list,size,id);
		modificar = list[indice];
		if(indice != -1)
		{
			do
			{
				seModifico = 0;

				printf("1. Modificar nombre \n");
				printf("2. Modificar apellido \n");
				printf("3. Modificar precio \n");
				printf("4. Modificar tipo de pasajero \n");
				printf("5. Modificar estado \n");
				printf("6. Salir");
				scanf("%d",&opcion);
				switch(opcion)
				{
				case 1:
					printf("Ingresa nombre a modificar");
					fflush(stdin);
					gets(modificarNombre);
					while(validacionCaracteres == 0)
					{
						printf("Reingresa el nombre");
						fflush(stdin);
						gets(name);
						validacionCaracteres = validarCaracteres(name);
					}
					strcpy(modificar.name,modificarNombre);
					break;
				case 2:
					printf("Ingresa apellido a modificar");
					fflush(stdin);
					gets(modificarApellido);
					while(validacionCaracteres == 0)
					{
						printf("Reingresa el nombre");
						fflush(stdin);
						gets(lastName);
						validacionCaracteres = validarCaracteres(lastName);
					}
					strcpy(modificar.lastName,modificarApellido);
					break;
				case 3:
					printf("Ingresa precio a modificar");
					scanf("%f",&modificarPrecio);
					while(modificarPrecio < 0)
					{
						printf("Reingresa el precio /n");
						scanf("%f",&modificarPrecio);
					}
					modificar.price = modificarPrecio;
					break;
				case 4:
					printf("Ingresa tipo de pasajero a modificar");
					scanf("%d",&modificarTipoPasajero);
					while(modificarTipoPasajero != 1 && modificarTipoPasajero != 2 && modificarTipoPasajero != 3)
					{
						printf("Reingresa el tipo de pasajero \n 1. Primera clase \n 2. Segunda clase \n 3. Turista");
						scanf("%d",&modificarTipoPasajero);
					}
					modificar.typePassenger = modificarTipoPasajero;
					break;
				case 5:
					printf("Ingresa el estado a modificar");
					scanf("%d",&modificarEstado);
					while(modificarEstado != 1 && modificarEstado != 2 && modificarEstado != 3)
					{
						printf("Ingresa el estado \n 1. Activo \n 2. Demorado \n 3. Cancelado \n");
						scanf("%d",&modificarEstado);
					}
					modificar.statusFlight = modificarEstado;
					break;
				case 6:
					printf("Salir del modificar");
					break;
				}
			}while(opcion!=6);
			list[indice]=modificar;
		}
	}

	return seModifico;

}

int opcionBaja(ePassenger list[],int size)
{
	int id;
	int bandera;
	char confirmacion;
	int validacion;
	bandera = 0;

	printf("Ingrese el ID del empleado que desea bajar ");
	scanf("%d",&id);
	validacion = findPassengerById(list,size,id);

	for(int i=0;i<size;i++)
	{
		if(validacion == 1 && list[i].id == id)
		{
			printf("Está seguro de que desea darle de baja? s/n: ");
			fflush(stdin);
			scanf("%c", &confirmacion);
			while(confirmacion!= 's' && confirmacion!= 'n')
			{
				printf("Ingrese si o no: s/n: ");
				fflush(stdin);
				scanf("%c", &confirmacion);
			}
			if(confirmacion == 's')
			{
				list[i].isEmpty = VACIO;
				bandera = 1;
			}
		}
	}
	return bandera;
}

void hardcodeo(ePassenger* list,int size)
{
    int id[] = {1,2,3,4};
    char name[][51]= {"Tomas","Cristian","Lucas","Agustin"};
    char lastName[][51]= {"Lopez","Facundo","Avalos","Ledesma"};
    float price[]={10000,20000,30000,40000};
    char flycode[][10]= {"10a15z","15bc30","tlm500","czx700"};
    int typePassenger[]= {1,3,4,2};
    int statusFlight[]= {1,2,3,4};
    int isEmpty[]= {1,1,1,1};

    for(int i=0;i<4;i++)
    {
        list[i].id = id[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].price = price[i];
        strcpy(list[i].flyCode,flycode[i]);
        list[i].typePassenger = typePassenger[i];
        list[i].statusFlight = statusFlight[i];
        list[i].isEmpty = isEmpty[i];
    }
}

int totalPreciosPasajes(ePassenger list[],int size)
{
	float suma=0;

	for(int i = 0;i<size;i++)
	{
		if(list[i].isEmpty == FULL)
		{
			suma+=list[i].price;
		}
	}
	return suma;
}

int promedioPreciosPasajes(ePassenger list[],int size)
{
	int contador;
	float promedio;
	float precioTotal;

	contador = 0;

	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == FULL)
		{
			contador++;
		}
	}

	precioTotal = totalPreciosPasajes(list,size);

	promedio = precioTotal/contador;

	return promedio;
}

int cantidadPasajeros(ePassenger list[],int size)
{
	float promedio;
	int contadorPasajeros;

	contadorPasajeros = 0;

	promedio = promedioPreciosPasajes(list,size);
	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == FULL)
		{
			if(list[i].price > promedio)
			{
				contadorPasajeros++;
			}
		}
	}

	return contadorPasajeros;
}

float pedirYValidarPrecio(char mensaje[],char mensajeError[])
{
    float numeroIngresado;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f",&numeroIngresado);
    while(numeroIngresado < 0)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%f",&numeroIngresado);
    }
    return numeroIngresado;
}

int pedirEntero(int* entero,char* mensaje,char* mensajeError,int limiteInferior,int limiteSuperior)
{
    int retorno;
    int numeroIngresado;

    retorno = -1;

    if(entero != NULL && mensaje != NULL && mensajeError != NULL && limiteInferior < limiteSuperior)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d",&numeroIngresado);

        while(numeroIngresado < limiteInferior || numeroIngresado > limiteSuperior)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", &numeroIngresado);
        }

        *entero = numeroIngresado;
        retorno = 0;
    }
    return retorno;
}


int mostrarTipo(ePassenger pasajero,eTypePassenger tipos[],int sizeTipos)
{
    int index;
    for(int i=0;i<sizeTipos;i++)
    {
        if(pasajero.typePassenger == tipos[i].opcion)
        {
            index = i;
            break;
        }
    }
    return index;
}

int mostrarVuelo(ePassenger pasajero,eStatusFlight estadoVuelo[],int sizeVuelo)
{
    int index;
    for(int i=0;i<sizeVuelo;i++)
    {
        if(pasajero.statusFlight == estadoVuelo[i].opcion)
        {
            index = i;
            break;
        }
    }
    return index;
}

void mostrarConTipoYEstado(ePassenger list,eStatusFlight estadoVuelo[],eTypePassenger tipos[])
{
    int tipo;
    int vuelo;
    if(list.isEmpty == FULL)
            {
                tipo =  mostrarTipo(list,tipos,TAMTIPOS);
                vuelo = mostrarVuelo(list,estadoVuelo,TAMVUELOS);

                printf("\n%4d %4s     %4s         %4.2f         %4s         %4s         %4s\n",
                        list.id,
                        list.name,
                        list.lastName,
                        list.price,
                        list.flyCode,
						tipos[tipo].claseVuelo,
                        estadoVuelo[vuelo].estadoVuelo);
            }
}
