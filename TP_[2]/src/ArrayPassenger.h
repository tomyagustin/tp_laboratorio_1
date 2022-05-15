#ifndef ARRAYPASSENGERH
#define ARRAYPASSENGERH
#define VACIO 0
#define FULL 1
#define TAM 2000

typedef struct
{
	int opcion;
	char estadoVuelo[20];
}eStatusFlight;

typedef struct
{
	int opcion;
	char claseVuelo[20];
}eTypePassenger;

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;


/// @brief indica que todas las posiciones del array están vacías
///
/// @param list
/// @param size
/// @return index
int initPassengers(ePassenger list[],int size);


/// @brief Agrega valores recibidos como parámetro en la primer posición libre de los pasajeros
///
/// @param list
/// @param size
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flyCode
/// @param statusFlight
/// @return espacio
int addPassenger(ePassenger list[],int size,int id,char name[],char lastName[],float price,int typePassenger,char flyCode[],int statusFlight);


/// @brief busca un pasajero recibiendo como parametro de busqueda su id
///
/// @param list
/// @param size
/// @param id
/// @return respuesta
int findPassengerById(ePassenger list[],int size,int id);


/// @brief elimina el pasajero ingresado recibiendo como parametro su id
///
/// @param list
/// @param size
/// @param id
/// @return respuesta
int removePassenger(ePassenger list[],int size,int id);

/// @brief ordena por apellido y tipo de pasajero de forma descendente o ascendente
///
/// @param list
/// @param size
/// @param order
/// @return retorno
int sortPassengers(ePassenger list[],int size,int order)

/// @brief imprime a los pasajeros de forma encolumnada
///
/// @param list
/// @param size
/// @return respuesta
int printPassenger(ePassenger list[],int size);


/// @brief ordena a los pasajeros por el codigo de vuelo de forma descendente o ascendente
///
/// @param list
/// @param tam
/// @param order
/// @return retorno
int sortPassengersByCode(ePassenger list[],int tam, int order);
#endif /* ARRAYPASSENGERH */
