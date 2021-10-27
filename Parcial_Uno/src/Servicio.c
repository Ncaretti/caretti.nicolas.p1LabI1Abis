#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"


int listarServicios(eServicio* listaServicios, int tamServicio)
{
    int ret = 0;
    int i;

    if(listaServicios != NULL && tamServicio > 0)
    {
        printf("\n************ SERVICIOS ************\n");
        for(i=0; i<tamServicio; i++)
        {
            printf("%d  %10s  %d\n", listaServicios[i].id, listaServicios[i].descripcion, listaServicios[i].precio);
        }

        ret = 1;
    }

    return ret;
}

int cargarServicios(eServicio* listaServicios, int tam, int id, char nombreServicio[])
{
	int ret = 0;
	int i;

	if(listaServicios != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaServicios[i].id == id)
			{
				strcpy(nombreServicio, listaServicios[i].descripcion);
				break;
			}
		}

		ret = 1;
	}

	return ret;
}

