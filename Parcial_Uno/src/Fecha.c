#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fecha.h"

#define OCUPADO 1
#define VACIO 0



int listarFechas(eFecha* listaFechas, int tamFecha)
{
    int ret = 0;
    int i;

    if(listaFechas != NULL && tamFecha > 0)
    {
        printf("\n************ FECHAS ************\n");
        for(i=0; i<tamFecha; i++)
        {
            printf("%d\t %d/%d/%d\n", listaFechas[i].id, listaFechas[i].dia, listaFechas[i].mes, listaFechas[i].anio);
        }

        ret = 1;
    }

    return ret;
}

int cargarFechas(eFecha* listaFechas, int tamFecha, int id)
{
	int ret = 0;
	int i;

	if(listaFechas != NULL && tamFecha > 0)
	{
		for(i=0;i<tamFecha;i++)
		{
			if(listaFechas[i].id == id)
			{
				id = listaFechas[i].id;
				break;
			}
		}

		ret = 1;
	}

	return ret;
}

