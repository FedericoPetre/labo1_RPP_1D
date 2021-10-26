/*
 * perro.c
 *
 *  Created on: 8 oct. 2021
 *      Author: Federico Petre
 */

#include "perro.h"

/**
 * @fn void perro_hardCodearPerros(perro[], int)
 * @brief Hardcodea la lista de perritos
 *
 * @param perritos lista de perritos
 * @param cantidadPerros Se hardcodean 3 perritos
 */
void perro_hardCodearPerros(perro* perritos, int cantidadPerros)
{
	int i;
	int idsPerros[] = {7000,7001,7002};
	char nombresPerro[][21] = {"Lobo", "Sheila", "Reina"};
	char razaPerros[][21] = {"Sharpei", "Golden", "Galgo"};
	int edadPerros[]= {2,12,13};

	if(perritos != NULL && cantidadPerros > 0)
	{
		for(i=0; i<3; i++)
		{
			perritos[i].id = idsPerros[i];
			strcpy(perritos[i].nombre, nombresPerro[i]);
			strcpy(perritos[i].raza, razaPerros[i]);
			perritos[i].edad = edadPerros[i];
			perritos[i].banderaPerro = OCUPADO;
		}
	}

}

/**
 * @fn int perro_inicializarPerros(perro*, int)
 * @brief Para inicializar la bandera de perros en Vacio
 *
 * @param perritos listado de perritos a ser inicializada
 * @param cantidadPerros cantidad de perros que se inicializa su bandera en VACIO
 * @return Retorna -1 en caso de error [Parametros invalidos]. Retorna 0 en caso contrario
 */
int perro_inicializarPerros(perro* perritos, int cantidadPerros)
{
	int retorno = -1;
	int i;

	if(perritos != NULL && cantidadPerros >0)
	{
		for(i=0; i<cantidadPerros; i++)
		{
			perritos[i].banderaPerro = VACIO;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * @fn perro perro_AltaPerro(int, char*, char*, int)
 * @brief Para cargar un perrito
 *
 * @param id Id del perrito a cargar
 * @param nombre Nombre del perrito
 * @param raza Raza del perrito
 * @param edad Edad del perrito
 * @return Retorna el perrito cargado con los parámetros anteriores
 */
perro perro_AltaPerro(int id, char* nombre, char* raza, int edad)
{
	perro perroAux;

	if(nombre != NULL && raza != NULL)
	{
		perroAux.id = id;
		strcpy(perroAux.nombre, nombre);
		strcpy(perroAux.raza, raza);
		perroAux.edad = edad;
		perroAux.banderaPerro = OCUPADO;
	}

	return perroAux;
}

/**
 * @fn int perro_listarPerros(perro*, int)
 * @brief Muestra todos los perritos cargados de una lista
 *
 * @param perritos lista de perritos
 * @param cantidadPerritos cantidad de perritos de la lista (incluye todos, cargados y no cargados)
 * @return Retorna -1 si la lista esta vacia o la cantidad de perritos es no valida. En caso de poder mostrarlos retorna 0
 */
int perro_ListarPerros(perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int i;

	if(perritos != NULL && cantidadPerritos >0)
	{
		printf("%-22s %-22s %-22s %-22s\n", "ID", "NOMBRE", "RAZA", "EDAD");
		for(i=0; i<cantidadPerritos; i++)
		{
			if(perritos[i].banderaPerro == OCUPADO)
			{
				printf("%-22d %-22s %-22s %-22d\n", perritos[i].id, perritos[i].nombre, perritos[i].raza, perritos[i].edad);
				retorno = 0;
			}

		}

	}
	return retorno;
}

/**
 * @fn int perro_encontrarPerroPorID(perro*, int, int)
 * @brief Para encontrar la posicion de la lista en donde se encuentra el perrito buscado por ID
 *
 * @param perritos Lista de todos los perritos
 * @param cantidadPerritos Longitud de la lista
 * @param id ID del perrito que esta siendo buscado
 * @return Retorna -1 en caso de no encontrar el perrito o parametros ingresados son inválidos. En caso de encontrarlo retorna la posicion de la lista en la que se encuentra el perrito.
 */
int perro_encontrarPerroPorID(perro* perritos, int cantidadPerritos, int id)
{
	int indiceEncontrado = -1;
	int i;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		for(i=0; i<cantidadPerritos; i++)
		{
			if(perritos[i].id == id && perritos[i].banderaPerro == OCUPADO)
			{
				indiceEncontrado = i;
				break;
			}
		}

	}
	return indiceEncontrado;
}

/**
 * @fn int perro_mostrarIdPerros(perro*, int)
 * @brief Para mostar los ids de los perritos en una linea.
 *
 * @param perritos lista de los perritos
 * @param cantidadPerritos Longitud de la lista.
 * @return Retorna -1 en caso de que el ingreso de los parametros es inválido. En caso de que pueda mostrarlos retorna 0.
 */
int perro_mostrarIdPerros(perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int i;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		printf("Mostrando IDS de los Perros...\n");
		for(i=0; i<cantidadPerritos; i++)
		{
			if(perritos[i].banderaPerro == OCUPADO)
			{
				printf("%d- ", perritos[i].id);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * @fn int perro_ModificarPerro(perro*, int, int)
 * @brief Para modificar los datos de un perrito ya cargado
 *
 * @param perritos Listado de perritos, se busca el perrito a ser modificado por ID.
 * @param cantidadPerritos Longitud de la lista de perritos.
 * @param idPerro ID del perrito a ser modificado (si es que se encuentra en la lista).
 * @return Retorna -1 en caso de que los parametros ingresados son invalidos o que el perrito no se encontro para modificar o que el usuario decidio no modificar los datos del perro. Retorna 0 en caso contrario.
 */
int perro_ModificarPerro(perro* perritos, int cantidadPerritos, int idPerro)
{
	int retorno = -1;
	int indicePerro;
	char nombrePerroAux[21];
	char razaPerroAux[21];
	int edadPerroAux;
	char respuesta;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		indicePerro = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerro);

		if(indicePerro != -1)
		{
			printf("Ingresando a la modificacion del perro...\n");

			funcionesInputs_pedirYValidarCadena("Ingrese nuevo nombre del perro (max 21 caracteres)\n", "Error, reingrese nuevo nombre del perro (max 21 caracteres)\n", 21, nombrePerroAux);
			funcionesInputs_pedirYValidarCadena("Ingrese nueva raza del perro (max 21 caracteres)\n", "Error, reingrese nueva raza del perro (max 21 caracteres)\n", 21, razaPerroAux);
			funcionesInputs_pedirYValidarEntero("Ingrese nueva edad del perro (min: 0, max: 20)\n", "Error, reingrese nueva edad del perro (min: 0, max: 20)\n", 0, 20, &edadPerroAux);

			funcionesInputs_pedirYValidarCaracter("Esta seguro que desea modificar los datos del perro?(s/n)\n", "Error, esta seguro que desea modificar los datos del perro?(s/n)\n", &respuesta);

			if(respuesta == 's')
			{
				perritos[indicePerro] = perro_AltaPerro(idPerro, nombrePerroAux, razaPerroAux, edadPerroAux);
				printf("Datos del perro modificados con exito\n");
				retorno = 0;
			}
			else
			{
				retorno = -1;
			}
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
 * @fn int perro_mostrarPerroPorID(perro*, int, int)
 * @brief Muestra un perrito segun el ID ingresado (si existe, lo muestra)
 *
 * @param perritos listado de perritos donde se busca por ID
 * @param cantidadPerritos longitud del listado
 * @param id ID del perro buscado
 * @return Retorna -1 en caso de no encontrar el perrito o parametros invalidos. 0 En caso de mostrarlo.
 */
int perro_mostrarPerroPorID(perro* perritos, int cantidadPerritos, int id)
{
	int retorno = -1;
	int indexPerro;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		indexPerro = perro_encontrarPerroPorID(perritos,cantidadPerritos, id);

		if(indexPerro != -1)
		{
			printf("%-22d %-22s %-22s %-22d\n", perritos[indexPerro].id, perritos[indexPerro].nombre, perritos[indexPerro].raza, perritos[indexPerro].edad);
			retorno = 0;
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
 * @fn int perro_mostrarPromedioDeEdad(perro*, int)
 * @brief Para calcular y mostrar el promedio de edad de los perros del listado
 *
 * @param perritos Listado de perros
 * @param cantidadPerritos longitud del listado
 * @return Retorna -1 en caso de recibir parametros invalidos, o en caso de poder calcular el promedio
 */
int perro_mostrarPromedioDeEdad(perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int i;
	int contadorPerritos =0;
	int acumuladorEdad = 0;
	float promedioEdad;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		for(i=0; i<cantidadPerritos; i++)
		{
			if(perritos[i].banderaPerro == OCUPADO)
			{
				acumuladorEdad = acumuladorEdad + perritos[i].edad;
				contadorPerritos++;
			}
		}

		if(contadorPerritos == 0)
		{
			promedioEdad = 0;
			retorno = 0;
		}
		else
		{
			promedioEdad = (float) acumuladorEdad / contadorPerritos;
			retorno = 0;
		}

		printf("\nPROMEDIO DE EDAD\n%.2f anios\n", promedioEdad);
	}
	return retorno;
}

int perro_BajaPerro(perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int indexPerro;
	int idAux;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		funcionesInputs_pedirYValidarEnteroSinRango("Ingrese el ID del perro a dar de baja\n", "Error, reingrese el ID del perro a dar de baja (ID numérico)\n", &idAux);

		indexPerro = perro_encontrarPerroPorID(perritos, cantidadPerritos, idAux);

		if(indexPerro != -1)
		{
			perritos[indexPerro].banderaPerro = VACIO;
			retorno = 0;
		}
	}
	return retorno;
}

int perro_mostrarPerro(perro perrito)
{
	int retorno = -1;
	printf("%-22s %-22s %-22s %-22s\n","ID PERRO", "NOMBRE PERRITO", "RAZA PERRITO", "EDAD PERRITO");
	printf("%-22d %-22s %-22s %-22d\n", perrito.id, perrito.nombre, perrito.raza, perrito.edad);
	retorno = 0;

	return retorno;
}

