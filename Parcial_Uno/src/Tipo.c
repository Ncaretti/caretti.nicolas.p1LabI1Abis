#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipo.h"



int listarTipos(eTipo* listaTipos, int tamTipo)
{
    int ret = 0;
    int i;

    if(listaTipos != NULL && tamTipo > 0)
    {
        printf("\n************ TIPOS ************\n");
        for(i=0; i<tamTipo; i++)
        {
            printf("%d  %10s\n", listaTipos[i].id, listaTipos[i].descripcion);
        }

        ret = 1;
    }

    return ret;
}

int cargarTipo(eTipo* listaTipos, int tam, int id, char nombreTipo[])
{
	int ret = 0;
	int i;

	if(listaTipos != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaTipos[i].id == id)
			{
				strcpy(nombreTipo, listaTipos[i].descripcion);
				break;
			}
		}

		ret = 1;
	}

	return ret;
}


