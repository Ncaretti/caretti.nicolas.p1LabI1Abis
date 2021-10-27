#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bicicleta.h"
#include "Color.h"
#include "Servicio.h"
#include "Tipo.h"
//#include "Trabajo.h"
#include "Validacion.h"
#include "Fecha.h"
#include "Cliente.h"

#define TAMTIP 4
#define TAMCOL 5
#define TAMSERV 4
#define TAMBICI 1000
#define TAMTRA 1000
#define TAMCLI 5
#define TAMFEC 4
#define VACIO 0
#define OCUPADO 1




int menuInformes();

int main(void)
{
	setbuf(stdout, NULL);
    int opcion;
    int idSiguienteB = 1;
    int idSiguienteT = 1;
    int flagAlta = 1;
    int flagContinuar = 1;
    int i;

    eBicicleta listaBicicletas[TAMBICI] =
    {
    		{1,"TMX",1003,5003,'a',OCUPADO,1},
			{2,"Moun",1000,5000,'c',OCUPADO,5},
			{3,"NOSE",1001, 5002,'c',OCUPADO,4},
			{4,"High",1002,5002,'c',OCUPADO,3},
			{5,"Low",1001,5004,'c',OCUPADO,2}
    };

    //inicializarBicicletas(listaBicicletas, TAMBICI);
    //inicializarTrabajos(listaTrabajos, TAMTRA);

    eTipo listaTipos[TAMTIP] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eColor listaColores[TAMCOL] =
    {
        {5000, "Gris"},
		{5001, "Blanco"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"}
    };
    eServicio listaServicios[TAMSERV] =
    {
        {20000, "Limpieza",30},
        {20001, "Parche",400},
        {20002, "Centrado",500},
        {20003, "Cadena",450}
    };

    eCliente listaClientes[TAMCLI] =
    {
    		{1,"Jorge","Mendez"},
			{2,"Hugo","Pena"},
			{3,"Gregorio","Galas"},
			{4,"Lautaro","Martinez"},
			{5,"Rodrigo","Tapari"}
    };

    eTrabajo listaTrabajos[TAMTRA] =
    {
    		{1,1,20001,{1,5,7,2021},OCUPADO},
			{2,3,20003,{2,8,2,2021},OCUPADO},
			{3,2,20003,{3,9,7,2022},OCUPADO}
    };

    eFecha listaFechas[TAMFEC] =
    {
    		{1,5,7,2021},
			{2,8,2,2021},
			{3,9,7,2022},
			{4,7,2,2021}
    };

    do
    {
		system("cls");
		printf("\n*************MENU*************\n\n");
		printf("1- ALTA BICICLETA\n");
		printf("2- MODIFICAR BICICLETA\n");
		printf("3- BAJA BICICLETA\n");
		printf("4- LISTAR BICICLETAS\n");
		printf("5- LISTAR TIPOS\n");
		printf("6- LISTAR COLORES\n");
		printf("7- LISTAR SERVICIOS\n");
		printf("8- ALTA TRABAJO\n");
		printf("9- LISTAR TRABAJOS\n");
		printf("10- INFORMES\n");
		printf("11- SALIR\n\n");
		scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
        	if(altaBicicleta(listaBicicletas, TAMBICI, listaTipos, TAMTIP, listaColores, TAMCOL, &idSiguienteB, listaClientes, TAMCLI))
        	{
        		flagAlta = 1;
        		printf("Bicicleta dada de alta con exito.\n");
        		system("pause");
        	}
        	else
        	{
        		printf("Hubo un error al dar de alta la bicicleta.\n");
        	}
        break;

        case 2:
        	if(flagAlta)
        	{
        		modificarBicicleta(listaBicicletas, TAMBICI, listaTipos, TAMTIP, listaColores, TAMCOL, listaClientes, TAMCLI);
        	}
        	else
        	{
        		printf("No hay bicicletas en el sistema.\n");
        		system("pause");
        	}
        break;

        case 3:
        	if(flagAlta)
        	{
        		if(bajaBicicleta(listaBicicletas, TAMBICI, listaTipos, TAMTIP, listaColores, TAMCOL, listaClientes, TAMCLI))
				{
					printf("Bicicleta dada de baja con exito.\n");
					flagAlta = 0;

					for(i=0;i<TAMBICI;i++)
					{
						if(listaBicicletas[i].isEmpty == OCUPADO)
						{
							flagAlta = 1;
							break;
						}
					}
					system("pause");
				}
        	}
        	else
        	{
        		printf("No hay bicicletas en el sistema.\n");
        		system("pause");
        	}
        break;

        case 4:
        	if(flagAlta)
        	{
        		mostrarBicicletas(listaBicicletas, TAMBICI, listaTipos, TAMTIP, listaColores, TAMCOL, listaClientes, TAMCLI);
        		system("pause");
        	}
        	else
        	{
        		printf("No hay bicicletas en el sistema.\n");
        		system("pause");
        	}
        break;

        case 5:
        	listarTipos(listaTipos, TAMTIP);
        	system("pause");
        break;

        case 6:
        	listarColores(listaColores, TAMCOL);
        	system("pause");
        break;

        case 7:
        	listarServicios(listaServicios, TAMSERV);
        	system("pause");
        break;

        case 8:
        	if(flagAlta)
        	{
        		if(altaTrabajo(listaTrabajos, TAMTRA, listaBicicletas, TAMBICI, listaServicios, TAMSERV, listaTipos, TAMTIP, listaColores, TAMCOL, &idSiguienteT, listaClientes, TAMCLI))
        		{
					printf("Trabajo dado de alta con exito.\n");
					system("pause");
        		}
        	}
        	else
        	{
        		printf("No hay bicicletas en el sistema.\n");
        		system("pause");
        	}
		break;

        case 9:
        	mostrarTrabajos(listaTrabajos, TAMTRA, listaBicicletas, TAMBICI, listaServicios, TAMSERV, listaTipos, TAMTIP, listaColores, TAMCOL);
        break;

        case 10:
        	do
        	{
        		system("cls");
        		switch(menuInformes())
        		{
        		    case 1:
        		    	if(!mostrarBicicletasColor(listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP, listaClientes, TAMCLI))
        		    	{
        		    		printf("No se encontraron bicicletas del color indicado.");
        		    		system("pause");
        		    	}
        		    	else
        		    	{
        		    		system("pause");
        		    	}
        		    break;

        		    case 2:
        		    	if(!mostrarBicicletasTipo(listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP, listaClientes, TAMCLI))
        		    	{
        		    		printf("No se encontraron bicicletas del tipo indicado.");
        		    		system("pause");
        		    	}
        		    	else
        		    	{
        		    		system("pause");
        		    	}
        		    break;

        		    case 3:
        		    	mostrarBicicletasMasMaterial(listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP);
        		    break;

        		    case 4:
        		    	mostrarBicicletasPorTipo(listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP, listaClientes, TAMCLI);
        		    break;

        		    case 5:
        		    	mostrarBicicletasMasColorYTipo(listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP);
        		    break;

        		    case 6:
        		    	mostrarColorMasElegido(listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP);
        		    break;

        		    case 7:
        		    	if(!mostrarTrabajosBicicleta(listaTrabajos, TAMTRA, listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP, listaClientes, TAMCLI, listaServicios, TAMSERV))
        		    	{
        		    		printf("\nNo hay trabajos hechos/pendientes con la bicicleta ingresada.\n\n");
        		    		system("pause");
        		    	}
        		    	else
        		    	{
        		    		system("pause");
        		    	}
        		    break;

        		    case 8:
        		    	mostrarSumaTotalTrabajo(listaTrabajos, TAMTRA, listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP, listaClientes, TAMCLI, listaServicios, TAMSERV);
        		    break;

        		    case 9:
        		    	if(!mostrarServiciosHechos(listaServicios, TAMSERV, listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP, listaClientes, TAMCLI, listaTrabajos, TAMTRA))
        		    	{
        		    		printf("\nNo hay bicicletas a las que se le haya realizado ese servicio.\n\n");
        		    		system("pause");
        		    	}
        		    	else
        		    	{
        		    		system("pause");
        		    	}
        		    break;

        		    case 10:
        		    	if(!mostrarFechaServicios(listaServicios, TAMSERV, listaBicicletas, TAMBICI, listaColores, TAMCOL, listaTipos, TAMTIP, listaClientes, TAMCLI, listaTrabajos, TAMTRA, listaFechas, TAMFEC))
        		    	{
        		    		printf("\nNo hay servicios realizados en la fecha ingresada.\n\n");
        		    		system("pause");
        		    	}
        		    	else
        		    	{
        		    		system("pause");
        		    	}
        		    break;

        		    case 11:
        		    	printf("Ha salido con exito");
        		    	flagContinuar = 0;
        		    break;
        		}
        	}while(flagContinuar == 1);

        break;

        case 11:
        	printf("Ha salido con exito.\n");
        break;

        default:
            printf("Error, ingrese una opcion valida.");
            system("pause");
        break;
        }
    }
    while(opcion != 11);


	return EXIT_SUCCESS;
}

int menuInformes()
{
	int opcionMenu;

	system("cls");

	printf("********Menu de Informes********\n\n"
			"1- MOSTRAR BICICLETAS DEL COLOR SELECCIONADO POR EL USUARIO\n"
			"2- MOSTRAR BICICLETAS DE UN TIPO SELECCIONADO\n"
			"3- INFORMAR SI HAY MAS BICICLETAS DE CARBONO O ALUMINIO Y MOSTRAR CANTIDAD\n"
			"4- MOSTRAR UN LISTADO DE LAS BICICLETAS SEPARADAS POR TIPO\n"
			"5- ELEGIR UN COLOR Y UN TIPO Y CONTAR CUANTAS BICICLETAS HAY DE ESE COLOR Y ESE TIPO\n"
			"6- MOSTRAR EL O LOS COLORES MAS ELEGIDOS POR LOS CLIENTES\n"
			"7- PEDIR UNA BICICLETA Y MOSTRAR TODOS LOS TRABAJOS QUE SE LE HICIERON\n"
			"8- PEDIR UNA BICICLETA E INFORMAR LA SUMA DE LOS IMPORTES DE LOS SERVICIOS QUE SE LE HICIERON A LA MISMA\n"
			"9- PEDIR UN SERVICIO Y MOSTRAR LAS BICICLETAS A LAS QUE SE LES REALIZO ESE SERVICIO Y LA FECHA\n"
			"10- PEDIR UNA FECHA Y MOSTRAR TODOS LOS SERVICIOS REALIZADOS A LA MISMA\n"
			"11- SALIR\n"
			"Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcionMenu);

	return opcionMenu;
}

