#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"


int listarCliente(eCliente* listaClientes, int tamCliente)
{
    int ret = 0;
    int i;

    if(listaClientes != NULL && tamCliente > 0)
    {
        printf("\n************ TIPOS ************\n");
        for(i=0; i<tamCliente; i++)
        {
            printf("%d  %10s  %10s\n", listaClientes[i].id, listaClientes[i].nombre, listaClientes[i].apellido);
        }

        ret = 1;
    }

    return ret;
}

int cargarCliente(eCliente* listaClientes, int tam, int id, char nombreCliente[])
{
	int ret = 0;
	int i;

	if(listaClientes != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaClientes[i].id == id)
			{
				strcpy(nombreCliente, listaClientes[i].nombre);
				break;
			}
		}

		ret = 1;
	}

	return ret;
}
