/*
 * Duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Federico Petre
 */

#ifndef DUENIO_H_
#define DUENIO_H_

#include "funcionesInputs.h"
#include <string.h>

typedef struct{
	int id;
	char nombreDuenio[41];
	int telefono;

} Duenio;

int Duenio_hardcodearDuenios(Duenio* duenios, int cantidadDuenios);
int Duenio_mostrarIdDuenios(Duenio* duenios, int cantidadDuenios);
int Duenio_encontrarDuenioPorID(Duenio* duenios, int cantidadDuenios, int id);
int Duenio_mostrarDuenioPorID(Duenio* duenios, int cantidadDuenios, int id);


#endif /* DUENIO_H_ */
