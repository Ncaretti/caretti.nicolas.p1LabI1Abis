

#ifndef COLOR_H_
#define COLOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	int id;
	char nombreColor[20];
}eColor;

int listarColores(eColor* listaColores, int tamColor);
int cargarColor(eColor* listaColores, int tam, int id, char nombreColor[]);

#endif /* COLOR_H_ */
