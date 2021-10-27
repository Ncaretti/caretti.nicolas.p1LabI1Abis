#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacion.h"



int validarEntero(int* datoValidar, int minimo, int maximo)
{
	int validacion = 0;

	fflush(stdin);
	if((scanf("%d", datoValidar)))
	{
		if(*datoValidar >= minimo && *datoValidar <= maximo)
		{
			validacion = 1;
		}
		else
		{
			do
			{
				printf("Error, ingrese un valor valido: ");
				fflush(stdin);
				if(scanf("%d", datoValidar))
				{
					if(*datoValidar >= minimo && *datoValidar <= maximo)
					{
						validacion = 1;
					}
				}
				else
				{
					validacion = 0;
				}
			}while(validacion == 0);
		}
	}
	else
	{
		do
		{
			printf("Error, ingrese un valor valido: ");
			fflush(stdin);
			if(scanf("%d", datoValidar))
			{
				if(*datoValidar >= minimo && *datoValidar <= maximo)
				{
					validacion = 1;
				}
			}
			else
			{
				validacion = 0;
			}

		}while(validacion == 0);
	}

	return validacion;
}

int validarCaracter(char* datoValidar, char primeraOpcion, char segundaOpcion)
{
	int validacion = 0;

	fflush(stdin);
	if((scanf("%c", datoValidar)))
	{
		if(*datoValidar == primeraOpcion || *datoValidar == segundaOpcion)
		{
			validacion = 1;
		}
		else
		{
			do
			{
				printf("Error, ingrese un caracter valido: ");
				fflush(stdin);
				if(scanf("%c", datoValidar))
				{
					if(*datoValidar == primeraOpcion || *datoValidar == segundaOpcion)
					{
						validacion = 1;
					}
				}
				else
				{
					validacion = 0;
				}
			}while(validacion == 0);
		}
	}
	else
	{
		do
		{
			printf("Error, ingrese un caracter valido: ");
			fflush(stdin);
			if(scanf("%c", datoValidar))
			{
				if(*datoValidar == primeraOpcion || *datoValidar == segundaOpcion)
				{
					validacion = 1;
				}
			}
			else
			{
				validacion = 0;
			}

		}while(validacion == 0);
	}

	return validacion;

}





