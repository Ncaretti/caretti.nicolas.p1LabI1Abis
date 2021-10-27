/*
 * Trabajo.h
 *
 *  Created on: Oct 26, 2021
 *      Author: Seether
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "Bicicleta.h"
#include "Fecha.h"
#include "Cliente.h"



typedef struct
{
	int id;
	int idBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

int inicializarTrabajos(eTrabajo* listaTrabajos, int tam);
int buscarTrabajoLibre(eTrabajo* listaTrabajos, int tam);
int altaTrabajo(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eServicio* listaServicios, int tamServicio, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, int* idSiguiente, eCliente* listaClientes, int tamCliente);
void mostrarTrabajo(eTrabajo miTrabajo, eServicio* listaServicios, int tamServicio);
int mostrarTrabajos(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eServicio* listaServicios, int tamServicio, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor);
int mostrarTrabajosBicicleta(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eServicio* listaServicios, int tamServicio);
int mostrarSumaTotalTrabajo(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eServicio* listaServicios, int tamServicio);


#endif /* TRABAJO_H_ */
