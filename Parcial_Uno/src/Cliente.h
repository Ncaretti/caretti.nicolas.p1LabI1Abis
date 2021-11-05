

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int id;
	char nombre[20];
	char apellido[20];
}eCliente;

int listarCliente(eCliente* listaClientes, int tamCliente);
int cargarCliente(eCliente* listaClientes, int tam, int id, char nombreCliente[]);

#endif /* CLIENTE_H_ */
