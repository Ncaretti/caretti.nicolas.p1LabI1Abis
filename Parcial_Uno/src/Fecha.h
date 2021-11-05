

#ifndef FECHA_H_
#define FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
