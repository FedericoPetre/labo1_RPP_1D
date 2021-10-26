/*
 * Duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Federico Petre
 */

#include "Duenio.h"

int Duenio_hardcodearDuenios(Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int i;

	int id[] = {30000,30001,30002,30003,30004};
	char nombre[][41] = {"Federico", "Luciano", "Ignacio", "Julian", "Agustin"};
	int telefono[] = {1520202020, 1530303030, 1540404040, 1550505050, 1560606060};

	if(duenios != NULL && cantidadDuenios > -1)
	{
		for(i=0; i<5; i++)
		{
			duenios[i].id = id[i];
			strcpy(duenios[i].nombreDuenio, nombre[i]);
			duenios[i].telefono = telefono[i];
			retorno = 0;
		}
	}
	return retorno;
}

int Duenio_mostrarIdDuenios(Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int i;

	if(duenios != NULL && cantidadDuenios > 0)
	{
		printf("Mostrando IDS de los Duenios...\n");
		for(i=0; i<cantidadDuenios; i++)
		{
			printf("%d- ", duenios[i].id);
			retorno = 0;
		}
	}
	return retorno;
}

int Duenio_encontrarDuenioPorID(Duenio* duenios, int cantidadDuenios, int id)
{
	int indiceEncontrado = -1;
	int i;

	if(duenios != NULL && cantidadDuenios > 0)
	{
		for(i=0; i<cantidadDuenios; i++)
		{
			if(duenios[i].id == id)
			{
				indiceEncontrado = i;
				break;
			}
		}

	}
	return indiceEncontrado;
}

int Duenio_mostrarDuenioPorID(Duenio* duenios, int cantidadDuenios, int id)
{
	int retorno = -1;
	int indexDuenio;

	if(duenios != NULL && cantidadDuenios > 0)
	{
		indexDuenio = Duenio_encontrarDuenioPorID(duenios,cantidadDuenios, id);

		if(indexDuenio != -1)
		{
			printf("%-22d %-22s %-22d\n", duenios[indexDuenio].id, duenios[indexDuenio].nombreDuenio, duenios[indexDuenio].telefono);
			retorno = 0;
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}


