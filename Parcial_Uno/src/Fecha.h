/*
 * Fecha.h
 *
 *  Created on: Oct 26, 2021
 *      Author: Seether
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bicicleta.h"
#include "Color.h"
#include "Servicio.h"
#include "Tipo.h"
#include "Trabajo.h"
#include "Validacion.h"
#include "Cliente.h"

typedef struct
{
	int id;
	int dia;
	int mes;
	int anio;
}eFecha;

int listarFechas(eFecha* listaFechas, int tamFecha);
int cargarFechas(eFecha* listaFechas, int tamFecha, int id);



#endif /* FECHA_H_ */
