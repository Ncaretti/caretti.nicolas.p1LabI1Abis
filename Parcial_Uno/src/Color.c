#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Color.h"

#define OCUPADO 1
#define VACIO 0



int listarColores(eColor* listaColores, int tamColor)
{
    int ret = 0;
    int i;

    if(listaColores != NULL && tamColor > 0)
    {
        printf("\n************ COLORES ************\n");
        for(i=0; i<tamColor; i++)
        {
            printf("%d  %10s\n", listaColores[i].id, listaColores[i].nombreColor);
        }

        ret = 1;
    }

    return ret;
}

int cargarColor(eColor* listaColores, int tam, int id, char nombreColor[])
{
	int ret = 0;
	int i;

	if(listaColores != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaColores[i].id == id)
			{
				strcpy(nombreColor, listaColores[i].nombreColor);
				break;
			}
		}

		ret = 1;
	}

	return ret;
}
