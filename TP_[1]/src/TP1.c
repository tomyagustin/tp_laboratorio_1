/*
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y,Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir

Tomás Agustín Lo Sasso Greco
Division 1C
*/

#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int main(void)
{
	setbuf(stdout, NULL);

	int config; // variable para las opciones del menu
	float x = 0; // variable de los kilometros
	float y = 0; // variable para Aerolineas
	float z = 0; // variable para Latam
	// VARIBLES DE LOS COSTOS PARA AEROLINEAS
	float costosDebitoY = 0;
	float costosCreditoY = 0;
	float costosBtcY = 0;
	float precioUnitarioY = 0;
	// VARIABLES DE LOS COSTOS PARA LATAM
	float costosDebitoZ = 0;
	float costosCreditoZ = 0;
	float costosBtcZ = 0;
	float precioUnitarioZ = 0;
	// VARIABLE PARA LA DIFERENCIA ENTRE AEROLINEAS Y LATAMS
	float precioDiferencia = 0;

	do
	{
		printf("******************¡¡Hola mundo!!*******************\n");
		printf("En el menú, ingresa las siguientes opciones.\n");
		printf("1.Ingresa la cantidad de kilometros\n");
		printf("2.Ingresa el precio de los vuelos: Aerolíneas/Latam\n");
		printf("3.Calcular costos\n");
		printf("4.Informar resultados\n");
		printf("5.Carga forzada de datos\n");
		printf("6.Salir\n");
		fflush(stdin);
		scanf("%d",&config);
		switch(config)
		{
		case 1:
			x = pedirKilometros("Ingrese la cantidad de kilometros" , "ERROR. Ingresa una cantidad valida");
			break;
		case 2:
			y = pedirY("\nIngresa el precio de Aerolíneas","ERROR. Ingresa un precio valido");
			z = pedirZ("\nIngresa el precio de Latam","ERROR. Ingresa un precio valido");
			break;
		case 3:
			if(x == 0 || z == 0 || y == 0)
			{
				printf("Error. Ingresa un numero valido");
			}
			else
			{
				// COSTOS DE AEROLINEAS
				costosDebitoY = calcularCostoDebito(y);
				costosCreditoY = calcularCostoCredito(y);
				costosBtcY = calcularCostoBtc(y);
				precioUnitarioY = calcularCostoUnitario(y,x);
				// COSTOS DE LATAM
				costosDebitoZ = calcularCostoDebito(z);
				costosCreditoZ = calcularCostoCredito(z);
				costosBtcZ = calcularCostoBtc(z);
				precioUnitarioZ = calcularCostoUnitario(z,x);
				precioDiferencia = calcularCostoDiferencia(z,y);
				printf("Se han calculado los costos exitosamente.\n");
			}
			break;
		case 4:
			informarResultados(costosDebitoY,costosCreditoY,costosBtcY,precioUnitarioY,costosDebitoZ,costosCreditoZ,costosBtcZ,precioUnitarioZ,precioDiferencia);
			break;
		case 5:
			mostrarCargaForzadaDatos();
			break;
		case 6:
			printf("Cerrando...");
			break;
		default:
			printf("Ingresa una opción valida");
		system("pause");
		break;
		}
	}while(config != 6);

		return 0;
}
