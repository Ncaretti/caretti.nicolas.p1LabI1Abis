#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "Fecha.h"
#include "Cliente.h"
#include "Color.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Bicicleta.h"

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
int mostrarServiciosHechos(eServicio* listaServicios, int tamServicio, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eTrabajo* listaTrabajos, int tamTrabajo);
int mostrarTrabajosBicicleta(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eServicio* listaServicios, int tamServicio);
int mostrarSumaTotalTrabajo(eTrabajo* listaTrabajos, int tamTrabajo, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eServicio* listaServicios, int tamServicio);
int mostrarFechaServicios(eServicio* listaServicios, int tamServicio, eBicicleta* listaBicicletas, int tamBici, eColor* listaColores, int tamColor, eTipo* listaTipos, int tamTipo, eCliente* listaClientes, int tamCliente, eTrabajo* listaTrabajos, int tamTrabajo, eFecha* listaFechas, int tamFecha);


#endif /* TRABAJO_H_ */
