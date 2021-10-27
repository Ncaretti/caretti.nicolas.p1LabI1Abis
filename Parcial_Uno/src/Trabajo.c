#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabajo.h"

#define OCUPADO 1
#define VACIO 0




int inicializarTrabajos(eTrabajo* listaTrabajos, int tam)
{
    int ret = 0;
    int i;

    if(listaTrabajos != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
        	listaTrabajos[i].isEmpty = VACIO;
        }
        ret = 1;
    }
    return ret;
}



int buscarTrabajoLibre(eTrabajo* listaTrabajos, int tam)
{
    int index = -1;
    int i;

    if(listaTrabajos != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            if(listaTrabajos[i].isEmpty == VACIO)
            {
            	index = i;
                break;
            }
        }
    }
    return index;
}

int altaTrabajo(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eServicio* listaServicios, int tamServicio, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, int* idSiguiente, eCliente* listaClientes, int tamCliente)
{
	int ret = 0;
	int indexTrabajo;
	int idBicicleta;
	int idServicio;
	int indexBici;
	int dia;
	int mes;
	int anio;

	if(listaTrabajos != NULL && tamTrabajo > 0)
	{
		indexTrabajo = buscarTrabajoLibre(listaTrabajos, tamTrabajo);

		if(indexTrabajo != -1)
		{
			printf("El trabajo a ingresar tendra el id: %d\n", *idSiguiente);
			listaTrabajos[indexTrabajo].id = *idSiguiente;
			(*idSiguiente)++;

			printf("******************************************************************\n");
			mostrarBicicletas(listaBicicletas, tamBici, listaTipos, tamTipo, listaColores, tamColor, listaClientes, tamCliente);
			printf("******************************************************************\n");

			printf("Ingrese el ID de la bicicleta: ");
			fflush(stdin);
			validarEntero(&idBicicleta, 1, 1000);

			indexBici = buscarBicicletaPorId(listaBicicletas, tamBici, idBicicleta);

			if(indexBici == idBicicleta)
			{
				listaTrabajos[indexTrabajo].idBicicleta = idBicicleta;

				listarServicios(listaServicios, tamServicio);

				printf("Ingrese el ID del servicio: ");
				fflush(stdin);
				validarEntero(&idServicio, 20000, 20003);
				listaTrabajos[indexTrabajo].idServicio = idServicio;


				printf("Ingrese el dia: ");
				fflush(stdin);
				validarEntero(&dia, 1, 31);
				listaTrabajos[indexTrabajo].fecha.dia = dia;

				printf("Ingrese el mes: ");
				fflush(stdin);
				validarEntero(&mes, 1, 12);
				listaTrabajos[indexTrabajo].fecha.mes = mes;

				printf("Ingrese el anio: ");
				fflush(stdin);
				validarEntero(&anio, 2021, 2023);
				listaTrabajos[indexTrabajo].fecha.anio = anio;

				listaTrabajos[indexTrabajo].isEmpty = OCUPADO;
				ret = 1;
			}
			else
			{
				printf("No hay ninguna bicicleta con el id ingresado.\n");
				system("pause");
			}
		}
		else
		{
			printf("Lista de trabajos llena.\n");
			system("pause");
		}
	}


	return ret;
}

void mostrarTrabajo(eTrabajo miTrabajo, eServicio* listaServicios, int tamServicio)
{
	char servicio[20];
    cargarServicios(listaServicios,tamServicio, miTrabajo.idServicio, servicio);
    printf("%d\t\t%10s\t%d\t\t%d/%d/%d\n", miTrabajo.id, servicio, miTrabajo.idBicicleta, miTrabajo.fecha.dia, miTrabajo.fecha.mes, miTrabajo.fecha.anio);
}

int mostrarTrabajos(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eServicio* listaServicios, int tamServicio, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor)
{
	int ret = 0;
	int i;

	if(listaTrabajos != NULL && tamBici > 0)
	{
		printf("ID TRABAJO\t   TRABAJO\tID BICICLETA\tFECHA\tPRECIO\n");
		printf("******************************************************\n");
		for(i=0;i<tamBici;i++)
		{
			if(listaTrabajos[i].isEmpty == OCUPADO)
			{
				mostrarTrabajo(listaTrabajos[i], listaServicios, tamServicio);
			}
		}
		printf("******************************************************\n");
		system("pause");
	}

	return ret;
}

int mostrarTrabajosBicicleta(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eServicio* listaServicios, int tamServicio)
{
	int ret = 0;
	int idIngresado;
	int i;

	mostrarBicicletas(listaBicicletas, tamBici, listaTipos, tamTipo, listaColores, tamColor, listaClientes, tamCliente);

	printf("Ingrese el ID de la bicicleta: ");
	fflush(stdin);
	validarEntero(&idIngresado, 1, 1000);

	printf("\n******************************************************\n");
	for(i=0;i<tamBici;i++)
	{
		if(listaTrabajos[i].isEmpty == OCUPADO && listaTrabajos[i].idBicicleta == idIngresado)
		{
			mostrarTrabajo(listaTrabajos[i], listaServicios, tamServicio);
			ret = 1;
		}
	}
	printf("******************************************************\n\n");
	return ret;
}

int mostrarSumaTotalTrabajo(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eServicio* listaServicios, int tamServicio)
{
	int ret = 0;
	int idIngresado;
	int acumuladorTotal = 0;
	int i;

	mostrarBicicletas(listaBicicletas, tamBici, listaTipos, tamTipo, listaColores, tamColor, listaClientes, tamCliente);

	printf("Ingrese el ID de la bicicleta: ");
	fflush(stdin);
	validarEntero(&idIngresado, 1, 1000);

	for(i=0;i<tamTrabajo;i++)
	{
		if(listaTrabajos[i].isEmpty == OCUPADO && listaTrabajos[i].idBicicleta == idIngresado)
		{
			acumuladorTotal += listaServicios[i].precio;
			ret = 1;
		}
	}

	if(acumuladorTotal > 0)
	{
		printf("\nEl total por los servicios hechos a la bicicleta es de $%d\n\n", acumuladorTotal);
		system("pause");
	}
	else
	{
		printf("\nNo se le hizo ningun servicio a la bicicleta ingresada\n\n");
		system("pause");
	}

	return ret;
}
