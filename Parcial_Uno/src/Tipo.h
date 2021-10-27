/*
 * Tipo.h
 *
 *  Created on: Oct 26, 2021
 *      Author: Seether
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int id;
	char descripcion[20];
}eTipo;

int listarTipos(eTipo* listaTipos, int tamTipo);
int cargarTipo(eTipo* listaTipos, int tam, int id, char nombreTipo[]);

#endif /* TIPO_H_ */
