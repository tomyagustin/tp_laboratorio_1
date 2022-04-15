#include <stdio.h>
#include <stdlib.h>

float pedirKilometros(char mensaje[],char mensajeError[])
{
	float km;
	printf("%s",mensaje);
	scanf("%f",&km);
	while(km<1)
	{
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%f",&km);
	}

	return km;
}


float pedirY(char mensaje[],char mensajeError[])
{
	float y;
	printf("%s",mensaje);
	scanf("%f",&y);
	while(y<1)
	{
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%f",&y);
	}

	return y;

}


float pedirZ(char mensaje[],char mensajeError[])
{
	float z;
	printf("%s",mensaje);
	scanf("%f",&z);
	while(z<1)
	{
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%f",&z);
	}
	return z;
}


float calcularCostoDebito(float precio)
{
	float descuento;

	descuento = precio - (precio *10/100);

	return descuento;
}


float calcularCostoCredito(float precio)
{
	float interes;

	interes = precio + (precio *25/100);

	return interes;
}


float calcularCostoBtc(float precio)
{
	float valor;

	valor = precio / 4606954.55;

	return valor;
}


float calcularCostoUnitario(float precio,float x)
{
	float unitario;

	unitario = precio / x;

	return unitario;
}


float calcularCostoDiferencia(float y,float z)
{
	float diferencia;

	if(y<z)
	{
		diferencia = z-y;
	}
	else
	{
		diferencia = y-z;
	}

	return diferencia;
}


void informarResultados(float costosDebitoY,float costosCreditoY,float costosBtcY,float precioUnitarioY,float costosDebitoZ, float costosCreditoZ, float costosBtcZ, float precioUnitarioZ,float precioDiferencia)
{

	if(costosDebitoY == 0 || costosCreditoY == 0 || costosBtcY == 0 || precioUnitarioY == 0 || costosDebitoZ == 0 || costosCreditoZ == 0 || costosBtcZ == 0 || precioUnitarioZ == 0 || precioDiferencia == 0)
	{
		printf("ERROR. No se puede informar porque no se ingresaron datos validos.");
	}
	else
	{
		printf("Latam\n"); // Z
		printf("a) Precio con tarjeta de débito: $ %.2f\n",costosDebitoY);
		printf("b) Precio con tarjeta de crédito: $ %.2f\n",costosCreditoY);
		printf("c) Precio pagando con bitcoin: $ %.11f\n",costosBtcY);
		printf("d) Precio unitario: $ %.2f\n",precioUnitarioY);
		printf("Aerolíneas\n"); // Y
		printf("a) Precio con tarjeta de débito: $ %.2f\n",costosDebitoZ);
		printf("b) Precio con tarjeta de crédito: $ %.2f\n",costosCreditoZ);
		printf("c) precio pagando con bitcoin: $ %.11f\n",costosBtcZ);
		printf("d) Precio unitario: $ %2.f\n",precioUnitarioZ);
		printf("La diferencia de precio es: $ %.2f\n",precioDiferencia);
	}
}


void mostrarCargaForzadaDatos(void)
{
	float x;
	float y;
	float z;
	float costosDebitoY;
	float costosCreditoY;
	float costosBtcY;
	float precioUnitarioY;
	float costosDebitoZ;
	float costosCreditoZ;
	float costosBtcZ;
	float precioUnitarioZ;
	float precioDiferencia;

	x = 7090;
	y = 162965;
	z = 159339;
	costosDebitoY = calcularCostoDebito(y);
	costosCreditoY = calcularCostoCredito(y);
	costosBtcY = calcularCostoBtc(y);
	precioUnitarioY = calcularCostoUnitario(y,x);
	costosDebitoZ = calcularCostoDebito(z);
	costosCreditoZ = calcularCostoCredito(z);
	costosBtcZ = calcularCostoBtc(z);
	precioUnitarioZ = calcularCostoUnitario(z,x);
	precioDiferencia = calcularCostoDiferencia(z,y);
	printf("Latam\n"); // Z
	printf("a) Precio con tarjeta de débito: $ %.2f\n",costosDebitoY);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n",costosCreditoY);
	printf("c) Precio pagando con bitcoin: $ %.11f\n",costosBtcY);
	printf("d) Precio unitario: $ %.2f\n",precioUnitarioY);
	printf("Aerolíneas\n"); // Y
	printf("a) Precio con tarjeta de débito: $ %.2f\n",costosDebitoZ);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n",costosCreditoZ);
	printf("c) precio pagando con bitcoin: $ %.11f\n",costosBtcZ);
	printf("d) Precio unitario: $ %.2f\n",precioUnitarioZ);
	printf("\nLa diferencia de precio es: $ %.2f\n",precioDiferencia);
}
