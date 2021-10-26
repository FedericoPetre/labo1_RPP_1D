/*
 * estadiaDiaria.c
 *
 *  Created on: 8 oct. 2021
 *      Author: Federico Petre
 */

#include "nexus_estadiaDiariaYDuenio.h"

/**
 * @fn int nexus_estadiaDiariaYDuenio_inicializarEstadias_inicializarEstadias(EstadiaDiaria*, int)
 * @brief Para inicializar el listado de estadias (todas se inicializaran en VACIO)
 *
 * @param estadias listado de las estadias a inicializar
 * @param cantidadEstadias longitud de la lsita
 * @return Retorna -1 si hay error (parametros invalidos), 0 si las pudo inicializar
 */
int nexus_estadiaDiariaYDuenio_inicializarEstadias(EstadiaDiaria* estadias, int cantidadEstadias)
{
	int retorno = -1;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			estadias[i].estadoReserva = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int nexus_estadiaDiariaYDuenio_encontrarEstadiaVacia(EstadiaDiaria*, int)
 * @brief Buscar el primer lugar vacio en la lista de estadias
 *
 * @param estadias Listado de las estadias donde se busca el lugar vacio
 * @param cantidadEstadias longitud de la lista
 * @return Retorna -1 si no encuentra un lugar vacio. Caso contrario retorna el indice de la primer posicion vacia
 */
int nexus_estadiaDiariaYDuenio_encontrarEstadiaVacia(EstadiaDiaria* estadias, int cantidadEstadias)
{
	int indiceEstadiaVacia=-1;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(estadias[i].estadoReserva == VACIO)
			{
				indiceEstadiaVacia = i;
				break;
			}
		}
	}
	return indiceEstadiaVacia;
}

/**
 * @fn Fecha estadiaDiaria_registrarFecha(void)
 * @brief Para registrar el ingreso de una fecha
 *
 * @return Retorna la fecha ingresada
 */
Fecha nexus_estadiaDiariaYDuenio_registrarFecha(void)
{
	Fecha fechaIngresada;
	printf("Ingrese fecha a reservar estadia...\n");
	funcionesInputs_pedirYValidarEntero("Ingrese dia (1-31) :", "Error, ingrese dia (1-31) :", 1, 31, &fechaIngresada.dia);
	funcionesInputs_pedirYValidarEntero("Ingrese mes (1-12) :", "Error, ingrese mes (1-12) :", 1, 12, &fechaIngresada.mes);
	funcionesInputs_pedirYValidarEntero("Ingrese anio (2021-2030) :", "Error, ingrese anio (2021-2030) :", 2021, 2030, &fechaIngresada.anio);

	return fechaIngresada;
}

int nexus_estadiaDiariaYDuenio_mostrarEstadia(EstadiaDiaria estadia, Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int indexDuenio;

	indexDuenio = Duenio_encontrarDuenioPorID(duenios, cantidadDuenios, estadia.idDuenio);

	if(indexDuenio != -1 && estadia.estadoReserva == OCUPADO)
	{
		printf("%-20d %-20s %-25d %-15d %-2d/%-2d/%-5d\n", estadia.id, duenios[indexDuenio].nombreDuenio, duenios[indexDuenio].telefono, estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio);
		retorno = 0;
	}
	return retorno;

}

/**
 * @fn int estadiaDiaria_listarEstadias(EstadiaDiaria*, int)
 * @brief Muestra el listado de estadias reservadas
 *
 * @param estadias listado de estadias
 * @param cantidadEstadias longitud del listado
 * @return Retorna -1 en caso de parametros invalidos, 0 si logro mostrar las estadias
 */
int nexus_estadiaDiariaYDuenio_listarEstadias(EstadiaDiaria* estadias, int cantidadEstadias, Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(i==0)
			{
				printf("%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
			}
			nexus_estadiaDiariaYDuenio_mostrarEstadia(estadias[i] ,duenios ,cantidadDuenios);
			retorno = 0;
		}
	}
	else
	{
		printf("Error al mostrar las estadias\n");
	}
	return retorno;
}

/**
 * @fn int estadiaDiaria_encontrarEstadiaPorID(EstadiaDiaria*, int, int)
 * @brief Busca la estadia que tenga el mismo id que se ingresa
 *
 * @param estadias Listado de todas las estadias registradas
 * @param cantidadEstadias cantidad maxima de estadias que pueden registrarse
 * @param id ID de la estadia buscada
 * @return Retorna -1 en caso de no encontrar la estadia. Si la encuentra retorna la posicion en que se encuentra la estadia en la lista
 */
int nexus_estadiaDiariaYDuenio_encontrarEstadiaPorID(EstadiaDiaria* estadias, int cantidadEstadias, int id)
{
	int indiceEncontrado = -1;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(estadias[i].estadoReserva == OCUPADO && estadias[i].id == id)
			{
				indiceEncontrado = i;
				break;
			}
		}
	}
	return indiceEncontrado;
}

/**
 * @fn int estadiaDiaria_mostrarIDS(EstadiaDiaria*, int)
 * @brief Muestra los IDS de las estadias ocupadas en una linea
 *
 * @param estadias Listado de todas las estadias
 * @param cantidadEstadias longitud de la lista
 * @return Retorna -1 en caso de error (parametros invalidos). retorna 0 en caso de poder mostrar aunque sea un id
 */
int nexus_estadiaDiariaYDuenio_mostrarIDS(EstadiaDiaria* estadias, int cantidadEstadias)
{
	int retorno = -1;
	int i;
	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(estadias[i].estadoReserva == OCUPADO)
			{
				printf("%d -", estadias[i].id);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * @fn int estadiaDiaria_bajaEstadia(EstadiaDiaria*, int)
 * @brief Dar de baja logica una estadia buscada por ID.
 *
 * @param estadias listado de estadias
 * @param cantidadEstadias longitud del listado
 * @return Retorna -1 en caso de error (parametros invalidos). 0 en caso de darla de baja
 */
int nexus_estadiaDiariaYDuenio_bajaEstadia(EstadiaDiaria* estadias, int cantidadEstadias, Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int idEstadiaAux;
	int indiceEstadiaAux;
	char respuesta;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		printf("Mostrando IDS de estadias\n");
		nexus_estadiaDiariaYDuenio_mostrarIDS(estadias, cantidadEstadias);
		funcionesInputs_pedirYValidarEntero("\nIngrese ID de la estadia a cancelar\n", "Error, reingrese ID de la estadia a cancelar\n", 100000, 150000, &idEstadiaAux);

		indiceEstadiaAux = nexus_estadiaDiariaYDuenio_encontrarEstadiaPorID(estadias, cantidadEstadias, idEstadiaAux);

		if(indiceEstadiaAux != -1)
		{
			printf("Mostrando estadia a dar de baja\n%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
			nexus_estadiaDiariaYDuenio_mostrarEstadia(estadias[indiceEstadiaAux], duenios, cantidadDuenios);
			funcionesInputs_pedirYValidarCaracter("Esta seguro de que desea cancelar esa estadia? (s/n)\n", "Error, esta seguro de que desea cancelar esa estadia? (s : si/n : no)\n", &respuesta);
			if(respuesta == 's')
			{
				estadias[indiceEstadiaAux].estadoReserva = VACIO;
				retorno = 0;
				printf("La estadia ha sido cancelada con exito\n");
			}
			else
			{
				printf("La estadia aun sigue en pie\n");
				retorno = -1;
			}
		}
		else
		{
			printf("Error, no se encontro la estadia\n");
		}
	}
	return retorno;
}

/**
 * @fn int estadiaDiaria_compararFechas(Fecha, Fecha)
 * @brief Para comparar dos fechas ingresadas
 *
 * @param fecha1 Primera fecha ingresada
 * @param fecha2 Segunda fecha ingresada
 * @return Retorna 1 si fecha1 esta antes que fecha2. Retorna -1 si fecha2 esta antes. Si las fechas son iguales retorna 0.
 */
int nexus_estadiaDiariaYDuenio_compararFechas(Fecha fecha1, Fecha fecha2)
{
	int retorno;

	if(fecha1.anio < fecha2.anio)
	{
		retorno = 1;
	}
	else
	{
		if(fecha1.anio > fecha2.anio)
		{
			retorno = -1;
		}
		else
		{
			if(fecha1.anio == fecha2.anio)
			{
				if(fecha1.mes < fecha2.mes)
				{
					retorno = 1;
				}
				else
				{
					if(fecha1.mes > fecha2.mes)
					{
						retorno = -1;
					}
					else
					{
						if(fecha1.mes == fecha2.mes)
						{
							if(fecha1.dia < fecha2.dia)
							{
								retorno = 1;
							}
							else
							{
								if(fecha1.dia > fecha2.dia)
								{
									retorno = -1;
								}
								else
								{
									if(fecha1.dia == fecha2.dia)
									{
										retorno = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * @fn int estadiaDiaria_ordenarEstadiasPorFecha(EstadiaDiaria*, int)
 * @brief Para ordenar un listado de estadias segun fecha (/y nombre del duenio del perro de la estadia)
 *
 * @param estadias listado de estadias
 * @param cantidadEstadias longitud de la lista
 * @return Retorna -1 en caso de parametro invalidos. 0 si logro su objetivo
 */
int nexus_estadiaDiariaYDuenio_ordenarEstadiasPorFecha(EstadiaDiaria* estadias, int cantidadEstadias, Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int i;
	int flagSwap;
	EstadiaDiaria estadiaAux;
	int nuevoLimite;
	int indiceDuenioAnterior;
	int indiceDuenioSiguiente;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		nuevoLimite = cantidadEstadias -1;
		do{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(nexus_estadiaDiariaYDuenio_compararFechas(estadias[i].fecha, estadias[i+1].fecha) == 1)
				{
					estadiaAux = estadias[i];
					estadias[i] = estadias[i+1];
					estadias[i+1] = estadiaAux;
					flagSwap = 1;
				}
			}
			nuevoLimite --;
		}while(flagSwap);

		nuevoLimite = cantidadEstadias -1;
		do{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				indiceDuenioAnterior = Duenio_encontrarDuenioPorID(duenios, cantidadDuenios, estadias[i].idDuenio);
				indiceDuenioSiguiente = Duenio_encontrarDuenioPorID(duenios, cantidadDuenios, estadias[i+1].idDuenio);
				if(nexus_estadiaDiariaYDuenio_compararFechas(estadias[i].fecha, estadias[i+1].fecha) == 0 && strcmp(duenios[indiceDuenioAnterior].nombreDuenio, duenios[indiceDuenioSiguiente].nombreDuenio) == 1)
				{
					estadiaAux = estadias[i];
					estadias[i] = estadias[i+1];
					estadias[i+1] = estadiaAux;
					flagSwap = 1;
				}
			}
			nuevoLimite --;
		}while(flagSwap);

		retorno = 0;
	}
	return retorno;
}

int nexus_estadiaDiariaYDuenio_encontrarPerroPorIDEnEstadia(EstadiaDiaria* estadias, int cantidadEstadias, int idPerro)
{
	int indicePerro = -1;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(estadias[i].estadoReserva == OCUPADO && estadias[i].idPerro == idPerro)
			{
				indicePerro = i;
			}
		}
	}
	return indicePerro;
}






