/*
 * funcionesInputs.c
 *
 *  Created on: 25 sep. 2021
 *      Author: Federico Petre
 */

#include "funcionesInputs.h"

/**
 * @fn void pedirYValidarCadena(char*, char*, int, char*)
 * @brief Pide, valida y retorna una cadena de caracteres
 *
 * @param mensaje Mensaje que se muestra para pedir la cadena de caracteres
 * @param mensajeError Mensaje que se muestra en caso de que la cadena de caracteres ingresada no es válida
 * @param max Cantidad máxima de caracteres que puede poseer la cadena
 * @param cadenaDeRetorno Cadena de caracteres que retorna la funcion (a través de un puntero)
 */
void funcionesInputs_pedirYValidarCadena(char* mensaje, char* mensajeError, int max, char* cadenaDeRetorno)
{
	char cadenaAux[300];
	int numeroValidacion1;
	int largoCadena;
	int numeroDeValidacion2;

	if(mensaje != NULL && mensajeError != NULL && cadenaDeRetorno != NULL && max>0)
	{
		printf("%s",mensaje);
		fflush(stdin);

		numeroValidacion1 = scanf("%[^\n]", cadenaAux);
		largoCadena = strlen(cadenaAux);
		numeroDeValidacion2 = funcionesInputs_verificarCadena(cadenaAux);
		strlwr(cadenaAux);
		cadenaAux[0] = toupper(cadenaAux[0]);

		while(numeroValidacion1 == 0 || largoCadena > max || numeroDeValidacion2 != -1)
		{
			printf("%s",mensajeError);
			fflush(stdin);

			numeroValidacion1 = scanf("%[^\n]", cadenaAux);
			largoCadena = strlen(cadenaAux);
			numeroDeValidacion2 = funcionesInputs_verificarCadena(cadenaAux);
			strlwr(cadenaAux);
			cadenaAux[0] = toupper(cadenaAux[0]);
		}
		strcpy(cadenaDeRetorno, cadenaAux);
	}
}

/**
 * @fn int verificarCadena(char*)
 * @brief Verifica que en todas las posiciones de la cadena no haya ningun caracter no valido (es se verifica que todas sean letra)
 *
 * @param cadena Cadena que se verifica toda sus posiciones
 * @return Si la cadena tiene alguna posicion cargada con un elemento que no sea un caracter, la funcion retorna esa posicion. De lo contrario retorna -1 (todo está Ok).
 */
int funcionesInputs_verificarCadena(char* cadena)
{
	int index = -1;
	int longitudCadena;
	int i;

	longitudCadena = strlen(cadena);

	for(i=0; i<longitudCadena; i++)
	{
		if(isalpha(cadena[i]) == 0)
		{
			index = i;
			break;
		}

	}
	return index;
}

/**
 * @fn int pedirYValidarEntero(char*, char*, int, int, int*)
 * @brief pide, valida y retorna un numero entero, en un rango determinado
 *
 * @param mensaje Mensaje mostrado al usuario para pedir el ingreso de un número entero
 * @param mensajeError Mensaje mostrado al usuario para avisar que el número ingresado no es válido
 * @param min Valor mínimo del rango en el que se debe encontrar el número
 * @param max Valor máximo del rango en el que se debe encontrar el número
 * @param numeroRetornado número que retorna la función (a través de un puntero)
 * @return
 */
int funcionesInputs_pedirYValidarEntero(char* mensaje, char* mensajeError, int min, int max, int* numeroRetornado)
{
	int retorno = -1;
	int numeroValidacion;
	int numeroAux;

	if(mensaje != NULL && mensajeError != NULL && numeroRetornado != NULL && min < max)
	{
		printf("%s",mensaje);
		fflush(stdin);

		numeroValidacion = scanf("%d", &numeroAux);

		while(numeroValidacion == 0 || numeroAux < min || numeroAux > max)
		{
			printf("%s",mensajeError);
			fflush(stdin);

			numeroValidacion = scanf("%d", &numeroAux);
		}
		*numeroRetornado = numeroAux;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int pedirYValidarFlotante(char*, char*, float, float, float*)
 * @brief pide valida y retorna un flotante en un rango determinado
 *
 * @param mensaje Mensaje mostrado al usuario para el ingreso del número flotante
 * @param mensajeError Mensaje mostrado al usuario para avisar de que el número ingresado no es válido
 * @param min Minimo valor del rango en el que se debe encontrar el número
 * @param max Máximo valor del rango en el que se debe encontrar el número
 * @param numeroRetornado Numero flotante retornado por la función (por puntero).
 * @return
 */
int funcionesInputs_pedirYValidarFlotante(char* mensaje, char* mensajeError, float min, float max, float* numeroRetornado)
{
	int retorno = -1;
	int numeroValidacion;
	float numeroAux;

	if(mensaje != NULL && mensajeError != NULL && numeroRetornado != NULL && min < max)
	{
		printf("%s",mensaje);
		fflush(stdin);

		numeroValidacion = scanf("%f", &numeroAux);

		while(numeroValidacion == 0 || numeroAux < min || numeroAux > max)
		{
			printf("%s",mensajeError);
			fflush(stdin);

			numeroValidacion = scanf("%f", &numeroAux);
		}
		*numeroRetornado = numeroAux;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int funcionesInputs_pedirYValidarCaracter(char*, char*, char*)
 * @brief Pide un caracter, lo valida y lo retorna.
 *
 * @param mensaje Mensaje que se muestra para pedir el ingreso del caracter (letra)
 * @param mensajeError Mensaje mostrado en caso de ser erroneo el ingreso del caracter
 * @param letraDeRetorno Puntero, por donde se retorna la letra pedida
 * @return Retorna -1 si hay algún error 0 si no.
 */
int funcionesInputs_pedirYValidarCaracter(char* mensaje, char* mensajeError, char* letraDeRetorno)
{
	int retorno = -1;
	char letra;
	int numeroValidacion;

	if(mensaje != NULL && mensajeError != NULL && letraDeRetorno != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		numeroValidacion = scanf("%c", &letra);

		while(numeroValidacion == 0 || isalpha(letra) == 0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			numeroValidacion = scanf("%c", &letra);
		}

		*letraDeRetorno = letra;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int funcionesInputs_pedirYValidarEnteroSinRango(char*, char*, int*)
 * @brief Pide, valida y retorna un entero cualquiera
 *
 * @param mensaje Mensaje mostrado para pedir el ingreso del número
 * @param mensajeError Mensaje mostrado para avisar de que el numero ingresado no es valido
 * @param numeroRetornado Puntero, por donde se retorna el numero pedido
 * @return Retorna -1 si hay algún error 0 si no.
 */
int funcionesInputs_pedirYValidarEnteroSinRango(char* mensaje, char* mensajeError, int* numeroRetornado)
{
	int retorno = -1;
	int numeroValidacion;
	int numeroAux;

	if(mensaje != NULL && mensajeError != NULL && numeroRetornado != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		numeroValidacion = scanf("%d", &numeroAux);

		while(numeroValidacion == 0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			numeroValidacion = scanf("%d", &numeroAux);
		}

		*numeroRetornado = numeroAux;
		retorno = 0;
	}
	return retorno;
}

