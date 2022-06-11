#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "LinkedList.h"
#include "Funciones.h"

/**********************************************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
**********************************************************************************/
int main()
{
	setbuf(stdout,NULL);

    int option;
    option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	menu();
    	setRangeInt(&option, 1, 10, "Su opcion: ", "Error. Reingrese una opcion: ");
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
            case 2:
            	controller_loadFromBinary("data.bin", listaPasajeros);
            	break;
            case 3:
            	validatorWithMessageError(controller_addPassenger(listaPasajeros),"Exito al agregar pasajero", "ERROR. No se pudo agregar el pasajero" );
            	break;
            case 4:
            	validatorWithMessageError(controller_editPassenger(listaPasajeros),"Exito al modificar pasajero", "ERROR. No se pudo modificar el pasajero" );
            	break;
            case 5:
            	validatorWithMessageError(controller_removePassenger(listaPasajeros),"Exito al eliminar pasajero", "ERROR. No se pudo eliminar el pasajero" );
            	break;
            case 6:
            	validatorWithMessageError(controller_ListPassenger(listaPasajeros),"Exito al listar pasajeros", "ERROR. No se pudo listar pasajeros" );
            	break;
            case 7:
            	controller_sortPassenger(listaPasajeros);
            	break;
            case 8:
                controller_saveAsText("data.csv", listaPasajeros);
                break;
            case 9:
            	controller_saveAsBinary("data.bin", listaPasajeros);
            	break;
            case 10:
            	system("pause");
            	break;
        }
    }while(option != 10);

    return 0;
}
