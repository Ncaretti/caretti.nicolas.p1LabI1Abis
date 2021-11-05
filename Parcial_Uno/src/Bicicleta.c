#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bicicleta.h"

#define OCUPADO 1
#define VACIO 0

int inicializarBicicletas(eBicicleta* listaBicicletas, int tam)
{
    int ret = 0;
    int i;

    if(listaBicicletas != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
        	listaBicicletas[i].isEmpty = VACIO;
        }
        ret = 1;
    }
    return ret;
}

int buscarLibre(eBicicleta* listaBicicletas, int tam)
{
    int index = -1;
    int i;

    if(listaBicicletas != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            if(listaBicicletas[i].isEmpty == VACIO)
            {
            	index = i;
                break;
            }
        }
    }
    return index;
}

int altaBicicleta(eBicicleta* listaBicicletas, int tam, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, int* idSiguiente, eCliente* listaClientes, int tamCliente)
{
	int ret = 0;
	int index;
	int tamChar;
	int i;
	char marca[20];
	int validacionMarca = 0;
	int tipo;
	int color;
	char material;
	int idCliente;

	if(listaBicicletas != NULL && tam > 0)
	{
		index = buscarLibre(listaBicicletas, tam);

		if(index != -1)
		{
			//ID//
			printf("La bicicleta a ingresar tendra el id: %d\n", *idSiguiente);
			listaBicicletas[index].id = *idSiguiente;
			(*idSiguiente)++;

			//ID CLIENTE//

			listarCliente(listaClientes, tamCliente);

			printf("Elija el ID del cliente.");
			fflush(stdin);
			validarEntero(&idCliente, 1, 3);
			listaBicicletas[index].idCliente = idCliente;

			//MARCA//
			do
			{
				printf("Ingrese marca: ");
				scanf("%s", marca);
				tamChar = strlen(marca);

				for(i=0;i<tamChar;i++)
				{
					if(!((marca[i] >= 65 && marca[i] <= 90) || (marca[i] >= 97 && marca[i] <= 122)))
					{
						printf("Error, ingrese una marca valido\n");
						validacionMarca = 0;
						break;
					}

					validacionMarca = 1;
				}
			}while(validacionMarca == 0);

			if(validacionMarca == 1)
			{
				strcpy(listaBicicletas[index].marca, marca);
			}

			//TIPO//
			listarTipos(listaTipos, tamTipo);
			printf("Ingrese el id del tipo: ");
			fflush(stdin);
			if(validarEntero(&tipo, 1000, 1003))
			{
				listaBicicletas[index].idTipo = tipo;
			}

			//COLOR//
			listarColores(listaColores, tamColor);
			printf("Ingrese el id del color: ");
			fflush(stdin);
			if(validarEntero(&color, 5000, 5004))
			{
				listaBicicletas[index].idColor = color;
			}

			//MATERIAL//
			printf("Ingrese el material: ");
			fflush(stdin);
			if(validarCaracter(&material, 'a', 'c'))
			{
				listaBicicletas[index].material = material;
			}

			listaBicicletas[index].isEmpty = OCUPADO;

			ret = 1;
		}

	}
	return ret;
}

int buscarBicicletaPorId(eBicicleta* listaBicicletas, int tam, int id)
{
	int index = -1;
	int i;

	for(i=0; i<tam; i++)
	{
		if(listaBicicletas[i].isEmpty == OCUPADO)
		{
			if(listaBicicletas[i].id == id)
			{
				index = id;
				break;
			}
		}
		else
		{
			index = -1;
		}
	}

	return index;
}

void mostrarBicicleta(eBicicleta miBicicleta, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, eCliente* listaClientes, int tamCliente)
{
	char tipo[20];
	char color[20];
	char nombreCliente[20];
    cargarTipo(listaTipos,tamTipo,miBicicleta.idTipo, tipo);
    cargarColor(listaColores,tamColor,miBicicleta.idColor, color);
    cargarCliente(listaClientes, tamCliente, miBicicleta.idCliente, nombreCliente);
    printf("%d\t %s\t %10s\t %s\t %c\t\t %s\n", miBicicleta.id, miBicicleta.marca ,tipo, color, miBicicleta.material, nombreCliente);
}

int mostrarBicicletas(eBicicleta* listaBicicletas, int tamBici, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, eCliente* listaClientes, int tamCliente)
{
	int ret = 0;
	int i;

	if(listaBicicletas != NULL && tamBici > 0)
	{
		printf("ID\t  MARCA\t      TIPO\t COLOR\t MATERIAL\tNOMBRE\n");
		printf("**************************************************************************\n");
		for(i=0;i<tamBici;i++)
		{
			if(listaBicicletas[i].isEmpty == OCUPADO)
			{
				mostrarBicicleta(listaBicicletas[i], listaTipos, tamTipo, listaColores, tamColor, listaClientes, tamCliente);
			}
		}
	}

	return ret;
}

int modificarBicicleta(eBicicleta* listaBicicletas, int tamBici, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, eCliente* listaClientes, int tamCliente)
{
	int ret = 0;
	int opcion;
	int index;
	int idIngresado;
	int tipo;
	char material;

	mostrarBicicletas(listaBicicletas, tamBici, listaTipos, tamTipo, listaColores, tamColor, listaClientes, tamCliente);

	printf("Ingrese el ID que quiere modificar: ");
	fflush(stdin);
	validarEntero(&idIngresado, 1, 1000);

	index = buscarBicicletaPorId(listaBicicletas, tamBici, idIngresado);

	if(index == idIngresado)
	{
		do
		{
		system("cls");
		printf("\n************* MENU MODIFICACIONES *************\n\n");
		printf("1- MODIFICAR TIPO\n");
		printf("2- MODIFICAR MATERIAL\n");
		printf("3- SALIR\n");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				listarTipos(listaTipos, tamTipo);
				printf("Ingrese el id del nuevo tipo: ");
				fflush(stdin);
				if(validarEntero(&tipo, 1000, 1003))
				{
					printf("Tipo modificado con exito\n");
					system("pause");
					listaBicicletas[index].idTipo = tipo;
				}
			break;

			case 2:
				printf("Ingrese el nuevo material: ");
				fflush(stdin);
				if(validarCaracter(&material, 'a', 'c'))
				{
					printf("Material modificado con exito\n");
					system("pause");
					listaBicicletas[index].material = material;
				}
			break;

			case 3:
				printf("Ha salido con exito.\n");
			break;

			default:
				printf("Error, ingrese una opcion valida\n");
			break;
		}

		}while(opcion != 3);
	}
	else
	{
		printf("Error, el id ingresado no pertenece a ninguna bicicleta.\n");
		system("pause");
	}


	return ret;
}

int bajaBicicleta(eBicicleta* listaBicicletas, int tam, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, eCliente* listaClientes, int tamCliente)
{
	int ret = 0;
	int idIngresado;
	int indice;

	if(listaBicicletas != NULL && tam > 0)
	{

		mostrarBicicletas(listaBicicletas, tam, listaTipos, tamTipo, listaColores, tamColor, listaClientes, tamCliente);

		printf("Ingrese el ID de la bici a dar de baja: ");
		fflush(stdin);
		if(validarEntero(&idIngresado, 1, 1000))
		{
			indice = buscarBicicletaPorId(listaBicicletas, tam, idIngresado);

			if(indice != -1)
			{
				listaBicicletas[indice].isEmpty = VACIO;
				ret = 1;
			}
			else
			{
				printf("Error, no hay ninguna bicicleta con el ID ingresado.\n");
			}
		}
	}
	return ret;
}

int mostrarBicicletasColor(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente)
{
	int color;
	int ret = 0;
	int i;

	listarColores(listaColores, tamColor);

	printf("Ingrese el ID del color:");
	fflush(stdin);
	validarEntero(&color, 5000, 5004);

	printf("\n****************************Bicicletas con ID color: %d*******************************\n\n", color);
	for(i=0;i<tamBici;i++)
	{
		if(listaBicicletas[i].idColor == color)
		{
			mostrarBicicleta(listaBicicletas[i], listaTipos, tamTipo, listaColores, tamColor, listaClientes, tamCliente);
			ret = 1;
		}
	}

	printf("\n****************************************************************************************\n");

	return ret;
}

int mostrarBicicletasTipo(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente)
{
	int tipo;
	int ret = 0;
	int i;

	listarTipos(listaTipos, tamTipo);

	printf("Ingrese el ID del tipo:");
	fflush(stdin);
	validarEntero(&tipo, 1000, 1003);

	printf("\n****************************Bicicletas con ID tipo: %d*******************************\n\n", tipo);
	for(i=0;i<tamBici;i++)
	{
		if(listaBicicletas[i].idTipo == tipo)
		{
			mostrarBicicleta(listaBicicletas[i], listaTipos, tamTipo, listaColores, tamColor, listaClientes, tamCliente);
			ret = 1;
		}
	}

	printf("\n*************************************************************************************\n");

	return ret;

}

int mostrarBicicletasMasMaterial(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo)
{
	int ret = 0;
	int contadorCarbono = 0;
	int contadorAluminio = 0;
	int i;

	for(i=0;i<tamBici;i++)
	{
		if(listaBicicletas[i].isEmpty == OCUPADO)
		{
			if(listaBicicletas[i].material == 'a')
			{
				contadorAluminio++;
			}

			if(listaBicicletas[i].material == 'c')
			{
				contadorCarbono++;
			}
		}

		ret = 1;
	}

	if(contadorCarbono > contadorAluminio)
	{
		printf("El material mas usado es Carbono en %d bicicletas\n", contadorCarbono);
		system("pause");
	}
	else if(contadorAluminio > contadorCarbono)
	{
		printf("El material mas usado es Aluminio en %d bicicletas\n", contadorAluminio);
		system("pause");
	}
	else
	{
		printf("Hay la misma cantidad de bicicletas de Carbono y Aluminio, con un total de %d de cada material\n", contadorAluminio);
		system("pause");
	}
	return ret;
}

int mostrarBicicletasPorTipo(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente)
{
	int ret = 0;
	int i;
	int j;
	eBicicleta auxBici;

	for(i=0;i<tamBici;i++)
	{
		for(j=0;j<tamBici-1;j++)
		{
			if(listaBicicletas[i].isEmpty == OCUPADO)
			{
				if(listaBicicletas[i].idTipo > listaBicicletas[j].idTipo)
				{
					auxBici = listaBicicletas[i];
					listaBicicletas[i] = listaBicicletas[j];
					listaBicicletas[j] = auxBici;
				}
			}
		}
		ret = 1;
	}

	mostrarBicicletas(listaBicicletas, tamBici, listaTipos, tamTipo, listaColores, tamColor, listaClientes, tamCliente);

	return ret;
}

int mostrarBicicletasMasColorYTipo(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo)
{
	int ret = 0;
	int tipo;
	int color;
	int contadorColorTipo = 0;
	int i;

	listarColores(listaColores, tamColor);

	printf("Ingrese el ID del color: ");
	fflush(stdin);
	validarEntero(&color, 5000, 5004);

	listarTipos(listaTipos, tamTipo);

	printf("Ingrese el ID del tipo: ");
	fflush(stdin);
	validarEntero(&tipo, 1000, 1004);

	for(i=0;i<tamBici;i++)
	{
		if(listaBicicletas[i].isEmpty == OCUPADO)
		{
			if(listaBicicletas[i].idColor == color && listaBicicletas[i].idTipo == tipo)
			{
				contadorColorTipo++;
			}
		}
		ret = 1;
	}

	if(contadorColorTipo > 0)
	{
		printf("\nHay un total de %d bicicletas con el color %d y el tipo %d\n\n", contadorColorTipo, color, tipo);
		system("pause");
	}
	else
	{
		printf("\nNo hay bicicletas con el color e tipo ingresados.\n\n");
		system("pause");
	}
	return ret;
}

int mostrarColorMasElegido(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo)
{
	int ret = 0;
	int i;
	int contadorRojo = 0;
	int contadorBlanco = 0;
	int contadorNegro = 0;
	int contadorAzul = 0;
	int contadorGris = 0;

	for(i=0;i<tamBici;i++)
	{
		if(listaBicicletas[i].isEmpty == OCUPADO)
		{
			if(listaBicicletas[i].idColor == 5000)
			{
				contadorGris++;
			}
			else if(listaBicicletas[i].idColor == 5001)
			{
				contadorBlanco++;
			}
			else if(listaBicicletas[i].idColor == 5002)
			{
				contadorAzul++;
			}
			else if(listaBicicletas[i].idColor == 5003)
			{
				contadorNegro++;
			}
			else if(listaBicicletas[i].idColor == 5004)
			{
				contadorRojo++;
			}
		}
		ret = 1;
	}

	if(contadorNegro > contadorBlanco && contadorNegro > contadorGris && contadorNegro > contadorAzul && contadorNegro > contadorRojo)
	{
		printf("\nEl color mas usado es el negro con un total de %d\n\n", contadorNegro);
		system("pause");
	}
	else if(contadorBlanco > contadorNegro && contadorBlanco > contadorGris && contadorBlanco > contadorAzul && contadorBlanco > contadorRojo)
	{
		printf("\nEl color mas usado es el blanco con un total de %d\n\n", contadorBlanco);
		system("pause");
	}
	else if(contadorGris > contadorNegro && contadorGris > contadorBlanco && contadorGris > contadorAzul && contadorGris > contadorRojo)
	{
		printf("\nEl color mas usado es el gris con un total de %d\n\n", contadorGris);
		system("pause");
	}
	else if(contadorAzul > contadorNegro && contadorAzul > contadorBlanco && contadorAzul > contadorGris && contadorAzul > contadorRojo)
	{
		printf("\nEl color mas usado es el azul con un total de %d\n\n", contadorAzul);
		system("pause");
	}
	else if(contadorRojo > contadorNegro && contadorRojo > contadorBlanco && contadorRojo > contadorGris && contadorRojo > contadorAzul)
	{
		printf("\nEl color mas usado es el rojo con un total de %d\n\n", contadorRojo);
		system("pause");
	}

	return ret;
}
