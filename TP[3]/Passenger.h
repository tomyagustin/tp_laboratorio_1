#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero; // 1 FirstClass, 2 ExecutiveClass, 3 EconomyClass
	int estadoVuelo; // 1 Aterrizado, 2 En Horario, 3 En Vuelo , 4 Demorado
}Passenger;

void menu();

/// @brief
///
/// @return
Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* codigoVueo, int tipoPasajero, int estadoVuelo);
Passenger* Passenger_newParametrosStr(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);


/// @brief funcion para tomar los datos de los pasajeros, -1 si no pudo tomar los datos,  1 si pudo
///
/// @param pasajero
/// @return
int Passenger_tomarDatos(Passenger* pasajero,LinkedList* pArrayListPassenger);


/// @brief funcion para buscar por id, -1 si no encuentra el id, y el indice del pasajero si lo encuentra
///
/// @param listaPasajeros
/// @return
int Passenger_searchByID(LinkedList* listaPasajeros);


/// @brief funcion para pasar de Str a Entero
///
/// @param tipoPasajeroStr
/// @param tipoPasajero
/// @return
int Passenger_tipoStrToInt(char* tipoPasajeroStr, int* tipoPasajero);


/// @brief funcion para pasar de Entero a Str
///
/// @param tipoPasajeroStr
/// @param tipoPasajero
/// @return
int Passenger_tipoIntToStr(char* tipoPasajeroStr, int* tipoPasajero);


/// @brief funcion para pasar el estado de vuelo Str a entero
///
/// @param estadoVueloStr
/// @param estadoVuelo
/// @return
int Passenger_estadoStrToInt(char* estadoVueloStr, int* estadoVuelo);


/// @brief funcion para pasar el estado de vuelo de Entero a Str
///
/// @param estadoVueloStr
/// @param estadoVuelo
/// @return
int Passenger_estadoIntToStr(char* estadoVueloStr, int* estadoVuelo);


/// @brief funcion para remover el pasajero, -1 ERROR 1 SUCCESS
///
void Passenger_delete();

/// @brief funcion para comparar por nombre, -1 ERROR 1 SUCCESS
///
/// @param passenger
/// @param passenger2
/// @return
int Passenger_compareByName(void* passenger, void* passenger2);


/// @brief funcion para comparar por apellido, -1 ERROR 1 SUCCESS
///
/// @param passenger
/// @param passenger2
/// @return
int Passenger_compareByLastName(void* passenger, void* passenger2);

/// @brief funcion para comparar por id
///
/// @param passenger
/// @param passenger2
/// @return
int Passenger_compareById(void* passenger, void* passenger2);

/// @brief funcion para imprimir la lista de un pasajero, -1 ERROR 1 SUCCESS
///
/// @param passenger
/// @return
int Passenger_printOne(Passenger* passenger);

/// brief funcion para imprimir la lista de todos los pasajeros
///
/// @param listaPasajeros
/// @return
int Passenger_printAll(LinkedList* listaPasajeros);


int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);


int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int*  estadoVuelo);

/// @brief funcion para imprimir el tipo de pasajero
///
void printTipoPasajero(void);

/// @brief funcion para imprimir el estado de vuelo para los pasajeros
///
void printEstadoVuelo(void);


/// @brief funcion para el maximo por id guardado desde un archivo
///
/// @param pFile
/// @param pArrayListPassenger
/// @return
int Passenger_getMaxId(FILE* pFile,LinkedList* pArrayListPassenger);

#endif /* PASSENGER_H_ */
