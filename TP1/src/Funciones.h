/**
 * @fn float pedirKilometros(char[], char[])
 * @brief es pido al usuario que ingrese los kilometros
 *
 * @param mensaje = Ingrese la cantidad de kilometros
 * @param mensajeError = ERROR. Ingresa una cantidad valida.
 * @return km
 */
float pedirKilometros(char mensaje[],char mensajeError[]);



/**
 * @fn float pedirY(char[], char[])
 * @brief le pido al usuario que ingrese el precio de Aerolineas
 *
 * @param mensaje = Ingresa el precio de Aerolíneas
 * @param mensajeError = ERROR. Ingresa un precio valido
 * @return y
 */
float pedirY(char mensaje[],char mensajeError[]);



/**
 * @fn float pedirZ(char[], char[])
 * @brief le pido al usuario que ingrese el precio de Latam
 *
 * @param mensaje = Ingresa el precio de Latam
 * @param mensajeError = ERROR. Ingresa un precio valido
 * @return z
 */
float pedirZ(char mensaje[],char mensajeError[]);


/**
 * @fn float calcularCostoDebito(float)
 * @brief funcion que calcula el descuento de la tarjeta de debito
 *
 * @param precio = descuento del 10%
 * @return descuento
 */
float calcularCostoDebito(float precio);



/**
 * @fn float calcularCostoCredito(float)
 * @brief funcion que calcula el interes de la tarjeta de credito
 *
 * @param precio = interes del 25%
 * @return interes
 */
float calcularCostoCredito(float precio);



/**
 * @fn float calcularCostoBtc(float)
 * @brief funcion que calcula el valor del Bitcoin
 *
 * @param precio = 1 BTC(4606954.55)
 * @return valor
 */
float calcularCostoBtc(float precio);



/**
 * @fn float calcularCostoUnitario(float, float)
 * @brief funcion que calcula el precio por kilometros en precio unitario
 *
 * @param precio = cantidad que ingresa el usuario
 * @param x = kilometros
 * @return unitario
 */
float calcularCostoUnitario(float precio, float x);



/**
 * @fn float calcularCostoDiferencia(float, float)
 * @brief funcion que calcula la diferencia entre Latam y Aerolineas
 *
 * @param y = Aerolineas
 * @param z = Latam
 * @return diferencia
 */
float calcularCostoDiferencia(float y, float z);



/**
 * @fn void mostrarCargaForzadaDatos(void)
 * @brief funcion que muestra los datos forzadamente sin que el usuario los ingrese
 *
 */
void mostrarCargaForzadaDatos(void);



/**
 * @fn void informarResultados(float, float, float, float, float, float, float, float, float)
 * @brief funcion que muestra los resultados de los costos
 *
 * @param costosDebitoY
 * @param costosCreditoY
 * @param costosBtcY
 * @param precioUnitarioY
 * @param costosDebitoZ
 * @param costosCreditoZ
 * @param costosBtcZ
 * @param precioUnitarioZ
 * @param precioDiferencia
 */
void informarResultados(float costosDebitoY,float costosCreditoY,float costosBtcY,float precioUnitarioY,float costosDebitoZ, float costosCreditoZ, float costosBtcZ, float precioUnitarioZ,float precioDiferencia);
