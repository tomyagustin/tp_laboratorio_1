#define TAMTIPOS 3
#define TAMVUELOS 3
/// @brief funcion para obtener el ID
///
/// @return
int obtenerID();

/// @brief funcion para pedir los datos al pasajero
///
/// @param list
/// @param size
/// @return index
int pedirDatos(ePassenger list[],int size);

/// @brief funcion para validar los datos
///
/// @param list
/// @param size
void validarDatos(ePassenger list[],int size);


/// @brief  funcion para validar los caracteres
///
/// @param cadena
/// @return validacion
int validarCaracteres(char cadena[]);


/// @brief funcion que busca
///
/// @param list
/// @param size
/// @return retorno
int busquedaLibre(ePassenger list[],int size);

int opcionModificar(ePassenger list[],int size);
int opcionBaja(ePassenger list[],int size);

/// @brief funcion que muestra la lista de los pasajeros
///
/// @param list
void mostrar(ePassenger list);

/// @brief funcion que muestra una carga de datos
///
/// @param list
/// @param size
void hardcodeo(ePassenger* list,int size);

/// @brief funcion que muestra la lista de los pasajeros
///
/// @param list
/// @param size
/// @param tipos
/// @param tamtipos
/// @param estadoVuelo
/// @param tamVuelos
void mostrarLista(ePassenger list[],int size,eTypePassenger tipos[],int tamtipos,eStatusFlight estadoVuelo[],int tamVuelos);

/// @brief funcion que muestra el total de los precios de los pasajes
///
/// @param list
/// @param size
/// @return
int totalPreciosPasajes(ePassenger list[],int size);

/// @brief funcion que muestra el promedio de los precios de los pasajes
///
/// @param list
/// @param size
/// @return
int promedioPreciosPasajes(ePassenger list[],int size);

/// @brief funcion que cuenta la cantidad de pasajeros
///
/// @param list
/// @param size
/// @return
int cantidadPasajeros(ePassenger list[],int size);


/// @brief funcion que pide al pasajero que ingrese para validr el numero
///
/// @param mensaje
/// @param mensajeError
/// @param limiteInferior
/// @param limiteSuperior
/// @return numeroIngresado
int pedirYValidarNumero(char mensaje[],char mensajeError[],int limiteInferior,int limiteSuperior);


/// @brief funcion que pide y valida los precios
///
/// @param mensaje
/// @param mensajeError
/// @return
float pedirYValidarPrecio(char mensaje[],char mensajeError[]);

/// @brief funcion que pide un entero y si se ingresa un numero invalido, pide reingresarlo
///
/// @param entero
/// @param mensaje
/// @param mensajeError
/// @param limiteInferior
/// @param limiteSuperior
/// @return
int pedirEntero(int* entero,char* mensaje,char* mensajeError,int limiteInferior,int limiteSuperior);


/// @brief funcion que muestra los tipos de pasajeros
///
/// @param pasajero
/// @param tipos
/// @param sizeTipos
/// @return
int mostrarTipo(ePassenger pasajero,eTypePassenger tipos[],int sizeTipos);


/// @brief funcion que muestra los vuelos
///
/// @param pasajero
/// @param estadoVuelo
/// @param sizeVuelo
/// @return
int mostrarVuelo(ePassenger pasajero,eStatusFlight estadoVuelo[],int sizeVuelo);


/// @brief funcion que muestra el tipo y estado de los vuelos
///
/// @param list
/// @param estadoVuelo
/// @param tipos
void mostrarConTipoYEstado(ePassenger list,eStatusFlight estadoVuelo[],eTypePassenger tipos[]);


