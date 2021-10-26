/*
 * funcionesInputs.h
 *
 *  Created on: 25 sep. 2021
 *      Author: Federico Petre
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef FUNCIONESINPUTS_H_
#define FUNCIONESINPUTS_H_


void funcionesInputs_pedirYValidarCadena(char* mensaje, char* mensajeError, int max, char* cadenaDeRetorno);
int funcionesInputs_verificarCadena(char* cadena);
int funcionesInputs_pedirYValidarEntero(char* mensaje, char* mensajeError, int min, int max, int* numeroRetornado);
int funcionesInputs_pedirYValidarFlotante(char* mensaje, char* mensajeError, float min, float max, float* numeroRetornado);
int funcionesInputs_pedirYValidarCaracter(char* mensaje, char* mensajeError, char* letraDeRetorno);
int funcionesInputs_pedirYValidarEnteroSinRango(char* mensaje, char* mensajeError, int* numeroRetornado);



#endif /* FUNCIONESINPUTS_H_ */
