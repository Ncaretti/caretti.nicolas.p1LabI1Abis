/*
 * Servicio.h
 *
 *  Created on: Oct 26, 2021
 *      Author: Seether
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
	int id;
	char descripcion[20];
	int precio;
}eServicio;

int listarServicios(eServicio* listaServicios, int tamServicio);
int cargarServicios(eServicio* listaServicios, int tam, int id, char nombreServicio[]);

#endif /* SERVICIO_H_ */
