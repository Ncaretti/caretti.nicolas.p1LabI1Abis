/*
 * Bicicleta.h
 *
 *  Created on: Oct 26, 2021
 *      Author: Seether
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_
#include "Color.h"
#include "Servicio.h"
#include "Tipo.h"
#include "Trabajo.h"
#include "Validacion.h"
#include "Cliente.h"

typedef struct
{
	int id;
	char marca[20];
	int idTipo;
	int idColor;
	char material;
	int isEmpty;
	int idCliente;
}eBicicleta;

int inicializarBicicletas(eBicicleta* listaBicicletas, int tam);
int buscarLibre(eBicicleta* listaBicicletas, int tam);
int altaBicicleta(eBicicleta* listaBicicletas, int tam, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, int* idSiguiente, eCliente* listaClientes, int tamCliente);
void mostrarBicicleta(eBicicleta miBicicleta, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, eCliente* listaClientes, int tamCliente);
int mostrarBicicletas(eBicicleta* listaBicicletas, int tamBici, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, eCliente* listaClientes, int tamCliente);
int modificarBicicleta(eBicicleta* listaBicicletas, int tamBici, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, eCliente* listaClientes, int tamCliente);
int bajaBicicleta(eBicicleta* listaBicicletas, int tam, eTipo* listaTipos, int tamTipo, eColor* listaColores, int tamColor, eCliente* listaClientes, int tamCliente);
int buscarBicicletaPorId(eBicicleta* listaBicicletas, int tam, int id);
int mostrarBicicletasColor(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente);
int mostrarBicicletasTipo(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente);
int mostrarBicicletasMasMaterial(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo);
int mostrarBicicletasPorTipo(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente);
int mostrarBicicletasMasColorYTipo(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo);
int mostrarColorMasElegido(eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo);
int mostrarFechaServicios(eServicio* listaServicios, int tamServicio, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eTrabajo* listaTrabajos, int tamTrabajo, eFecha* listaFechas, int tamFecha);
int mostrarServiciosHechos(eServicio* listaServicios, int tamServicio, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eTrabajo* listaTrabajos, int tamTrabajo);

#endif /* BICICLETA_H_ */
