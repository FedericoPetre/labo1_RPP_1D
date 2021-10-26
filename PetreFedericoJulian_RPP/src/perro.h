/*
 * perro.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Federico Petre
 */

#ifndef PERRO_H_
#define PERRO_H_

#define VACIO 0
#define OCUPADO 1
#define CANTPERROS 5

#include "funcionesInputs.h"

typedef struct {
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int banderaPerro;
} perro;

perro perros[CANTPERROS];

void perro_hardCodearPerros(perro* perritos, int cantidadPerros);
int perro_inicializarPerros(perro* perritos, int cantidadPerros);
perro perro_AltaPerro(int id, char* nombre, char* raza, int edad);
int perro_ListarPerros(perro* perritos, int cantidadPerritos);
int perro_encontrarPerroPorID(perro* perritos, int cantidadPerritos, int id);
int perro_mostrarIdPerros(perro* perritos, int cantidadPerritos);
int perro_ModificarPerro(perro* perritos, int cantidadPerritos, int idPerro);
int perro_mostrarPerroPorID(perro* perritos, int cantidadPerritos, int id);
int perro_mostrarPromedioDeEdad(perro* perritos, int cantidadPerritos);
int perro_BajaPerro(perro* perritos, int cantidadPerritos);
int perro_mostrarPerro(perro perrito);

#endif /* PERRO_H_ */
