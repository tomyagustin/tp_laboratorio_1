/*
 ============================================================================
 Name        : TP2.c
 Author      : Tomas Agustin Lo Sasso Greco
 Description : Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener m�s de 2000 pasajeros.

datos: passenger: int id
char name [51]
char lastname[51]
float price
char flycode[10]
int typePassenger
int statusflight
int is empty

El sistema deber� tener el siguiente men� de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el
n�mero de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o C�digo de vuelo
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�
1-NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �ArrayPassenger� que
facilitar� el manejo de la lista de pasajeros y su modificaci�n. En la secci�n siguiente se
detallan las funciones que esta biblioteca debe tener.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Funciones.h"

int main(void)
{

	setbuf(stdout, NULL);

	int opcion;
	int bandera;

	int eleccion;
	float total;
	float promedio;
	int cantidad;

	bandera = 0;
	ePassenger list[TAM];
	eStatusFlight estadoPasajero [3] = {{1,"Activo"},{2,"Demorado"},{3,"Cancelado"}};
	eTypePassenger tipoPasajero[3] = {{1,"Primera clase"},{2,"Segunda Clase"},{3,"Turista"}};

	do
	{
		printf("\n *****Bienvendio! Ingresa una opcion***** \n");
		printf("1. ALTAS \n");
		printf("2. MODIFICAR \n");
		printf("3. BAJA \n");
		printf("4. INFORMAR \n");
		printf("5. CARGA FORZADA \n");
		printf("6. SALIR \n");
		fflush(stdin);
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			bandera = 1;
			pedirDatos(list,TAM);
			break;
		case 2:
			opcionModificar(list,TAM);
			break;
		case 3:
			opcionBaja(list,TAM);
			break;
		case 4:
			mostrarLista(list, TAM, tipoPasajero, TAMTIPOS, estadoPasajero, TAMVUELOS);
			if(bandera == 1)
						{
							pedirEntero(&eleccion,"1.Ordenar por apellido 2. Listado de precios y promedio, precios que superan el promedio. 3. Ordenado por codigo y estado activo","ERROR. Ingresa un numero valido",1,3);
							switch(eleccion)
							{
							case 1:
								sortPassengers(list,TAM);
								printPassenger(list,TAM);
								break;
							case 2:
								printf("La suma total de precios es: \n");
								total = totalPreciosPasajes(list,TAM);
								printf("%2.f",total);
								printf("El promedio de los precios es: \n");
								promedio = promedioPreciosPasajes(list,TAM);
								printf("%2.f",promedio);
								printf("Cantidad de pasajeros que superan el precio promedio: \n");
								cantidad = cantidadPasajeros(list,TAM);
								printf("%d",cantidad);
								break;
							case 3:
								sortPassengers(list,TAM);
								printPassenger(list,TAM);
								break;
							}
						}
					break;
		case 5:
		hardcodeo(list,TAM);
		printPassenger(list,TAM);
		break;
		case 6:
		printf("Saliendo del programa..\n");
		system("pause");
		break;
		default:
		printf("Opcion incorrecta, intente nuevamente. \n");
		break;
		}
		}while(opcion!=6);

	return 0;
}
