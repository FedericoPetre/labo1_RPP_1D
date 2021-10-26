/*
 * nexusPerroYEstadias.c
 *
 *  Created on: 9 oct. 2021
 *      Author: Federico Petre
 */

#include "nexusPerroYEstadias.h"

/**
 * @fn EstadiaDiaria nexusPerroYEstadias_reservarEstadia(int, char*, int, int, Fecha)
 * @brief Reservar una estadia en la guarderia de perros
 *
 * @param id ID de la estadia
 * @param nombreDuenio Nombre del duenio del perro
 * @param telefono telefono de contacto del duenio
 * @param idPerro ID del perro a ser cuidado
 * @param fecha Fecha de la estadia
 * @return Retorna una estadia reservada con los datos anteriores
 */
EstadiaDiaria nexusPerroYEstadias_reservarEstadia(int id, int idDuenio, int idPerro, Fecha fecha)
{
	EstadiaDiaria estadia;

	if(id>99999)
	{
		estadia.id = id;
		estadia.idDuenio = idDuenio;
		estadia.idPerro = idPerro;
		estadia.fecha = fecha;
		estadia.estadoReserva = OCUPADO;
	}
	return estadia;
}

/**
 * @fn int nexusPerroYEstadias_AltaEstadia(EstadiaDiaria*, int, int, perro*, int)
 * @brief Para dar de alta una estadia (reservarla), pidiendo todos los datos al usuario
 *
 * @param estadias listado de estadias, donde se registrara la nueva estadia
 * @param cantidadEstadias longitud de la lista
 * @param idEstadia ID de la estadia a ser reservada
 * @param perritos listado de perritos, se mostrara los IDS de los perritos a cuidar
 * @param cantidadPerritos longitud del listadod de perritos
 * @return Retorna 0 si se logro registrar la estadia exitosamente. -1 si los parametros son invalidos o el usuario decide no registrar la estadia
 */
int nexusPerroYEstadias_AltaEstadia(EstadiaDiaria* estadias, int cantidadEstadias, int idEstadia, perro* perritos, int cantidadPerritos, Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int estadiaDisponible;
	int idPerroAux;
	int indicePerro;
	Fecha fechaAux;
	char respuesta;
	int indiceDuenio;
	int idDuenioAux;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		estadiaDisponible = nexus_estadiaDiariaYDuenio_encontrarEstadiaVacia(estadias, cantidadEstadias);

		if(estadiaDisponible != -1)
		{
			Duenio_mostrarIdDuenios(duenios, cantidadDuenios);
			funcionesInputs_pedirYValidarEnteroSinRango("\nIngrese el ID del Duenio (30000: Federico, 30001: Luciano, 30002: Ignacio , 30003: Julian , 30004: Agustin)\n", "Error, reingrese el ID del Duenio (numérico) (30000: Federico, 30001: Luciano, 30002: Ignacio , 30003: Julian , 30004: Agustin)\n", &idDuenioAux);
			indiceDuenio = Duenio_encontrarDuenioPorID(duenios, cantidadDuenios, idDuenioAux);
			while(indiceDuenio == -1)
			{
				Duenio_mostrarIdDuenios(duenios, cantidadDuenios);
				funcionesInputs_pedirYValidarEnteroSinRango("\nError, reingrese el ID del Duenio (30000: Federico, 30001: Luciano, 30002: Ignacio , 30003: Julian , 30004: Agustin)\n", "Error, reingrese el ID del Duenio (numérico) (30000: Federico, 30001: Luciano, 30002: Ignacio , 30003: Julian , 30004: Agustin)\n", &idDuenioAux);
				indiceDuenio = Duenio_encontrarDuenioPorID(duenios, cantidadDuenios, idDuenioAux);
			}

			perro_mostrarIdPerros(perritos, cantidadPerritos);
			funcionesInputs_pedirYValidarEnteroSinRango("\nIngrese el ID del perro a cuidar (7000: Lobo , 7001: Sheila , 7002: Reina)\n", "Error, reingrese el ID del perro a cuidar (numérico) (7000: Lobo , 7001: Sheila , 7002: Reina)\n", &idPerroAux);
			indicePerro = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerroAux);
			while(indicePerro == -1)
			{
				perro_mostrarIdPerros(perritos, cantidadPerritos);
				funcionesInputs_pedirYValidarEnteroSinRango("\nError, reingrese el ID del perro a cuidar (7000: Lobo , 7001: Sheila , 7002: Reina)\n", "Error, reingrese el ID del perro a cuidar (numérico) (7000: Lobo , 7001: Sheila , 7002: Reina)\n", &idPerroAux);
				indicePerro = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerroAux);
			}
			fechaAux = nexus_estadiaDiariaYDuenio_registrarFecha();

			estadias[estadiaDisponible] = nexusPerroYEstadias_reservarEstadia(idEstadia, idDuenioAux, idPerroAux, fechaAux);
			printf("%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
			nexusPerroYEstadias_mostrarEstadiaConDuenio(estadias[estadiaDisponible],duenios[indiceDuenio]);
			funcionesInputs_pedirYValidarCaracter("Esta estadia se ingresara en el sistema\nEsta de acuerdo? (s/n)\n", "Error, esta estadia se ingresara en el sistema\nEsta de acuerdo? (s:si/n:no)(Ingrese caracter)\n", &respuesta);

			if(respuesta == 's')
			{
				printf("Estadia reservada con exito\n");
				retorno = 0;
			}
			else
			{
				estadias[estadiaDisponible].estadoReserva = VACIO;
				printf("Se ha cancelado la reserva de estadia\n");
				retorno = -1;
			}
		}

	}
	return retorno;
}

/**
 * @fn int nexusPerroYEstadias_modificarEstadia(EstadiaDiaria*, int, perro*, int)
 * @brief Para modificar los datos de una estadia
 *
 * @param estadias listado de las estadias (Se busca la estadia a modificar por ID)
 * @param cantidadEstadias longitud de la lista
 * @param perritos listado de los perritos (se podra modificar uno de estos perritos si el usuario lo decide)
 * @param cantidadPerritos longitud de la lista
 * @return Retorna -1 en caso de parametros invalidos o el usuario decidio no modificar la estadia. 0 en caso de modificarla con exito
 */
int nexusPerroYEstadias_modificarEstadia(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos, Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int idEstadiaAux;
	int indiceEstadiaAux;
	int opcion;
	int telefonoAux;
	int idPerroAux;
	int idPerroAnteriorAux;
	int indicePerroAux;
	char respuesta;
	int indiceDuenioAux;
	int telefonoAnteriorAux;

	if(estadias != NULL && cantidadEstadias > 0 && perritos != NULL && cantidadPerritos > 0)
	{
		printf("Mostrando IDS de estadias\n");
		nexus_estadiaDiariaYDuenio_mostrarIDS(estadias, cantidadEstadias);
		funcionesInputs_pedirYValidarEntero("\nIngrese ID de la estadia a modificar\n", "Error, reingrese ID de la estadia a modificar\n", 100000, 150000, &idEstadiaAux);

		indiceEstadiaAux = nexus_estadiaDiariaYDuenio_encontrarEstadiaPorID(estadias, cantidadEstadias, idEstadiaAux);
		indiceDuenioAux = Duenio_encontrarDuenioPorID(duenios, cantidadDuenios, estadias[indiceEstadiaAux].idDuenio);

		if(indiceEstadiaAux != -1)
		{
			printf("Mostrando estadia a modificar:\n%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
			nexusPerroYEstadias_mostrarEstadiaConDuenio(estadias[indiceEstadiaAux], duenios[indiceDuenioAux]);
			funcionesInputs_pedirYValidarEntero("Ingrese opcion:\n1- Modificar telefono de contacto\n2- Modificar perro\n", "Error, reingrese opcion: (1 o 2)\n1- Modificar telefono de contacto\n2- Modificar perro\n", 1, 2, &opcion);

			switch(opcion)
			{
				case 1:
					printf("Has elejido la opcion 1- Modificar telefono de contacto\n");
					funcionesInputs_pedirYValidarEntero("Ingrese nuevo telefono de contacto (celular)(1500000000 - 1600000000)\n ", "Error, reingrese nuevo telefono de contacto (celular)(1500000000 - 1600000000)\n ", 1500000000, 1600000000, &telefonoAux);
					telefonoAnteriorAux = duenios[indiceDuenioAux].telefono;
					duenios[indiceDuenioAux].telefono = telefonoAux;
					printf("Mostrando estadia modificada:\n%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
					nexusPerroYEstadias_mostrarEstadiaConDuenio(estadias[indiceEstadiaAux], duenios[indiceDuenioAux]);
					funcionesInputs_pedirYValidarCaracter("Esta seguro que desea guardar este nuevo telefono de contacto?(s/n)\n", "Error, esta seguro que desea guardar este nuevo telefono de contacto?(s/n)\n", &respuesta);

					if(respuesta == 's')
					{
						printf("Telefono de contacto modificado exitosamente\n");
					}
					else
					{
						duenios[indiceDuenioAux].telefono = telefonoAnteriorAux;
						printf("se ha cancelado la modificacion de datos\n");
					}
					break;
				case 2:
					printf("Has elejido la opcion 2- Modificar perro\n");
					perro_mostrarIdPerros(perritos, cantidadPerritos);
					funcionesInputs_pedirYValidarEnteroSinRango("\nIngrese el ID del nuevo perro a cuidar (7000: Lobo , 7001: Sheila , 7002: Reina)\n", "Error, reingrese el ID del nuevo perro a cuidar (numérico)(7000: Lobo , 7001: Sheila , 7002: Reina)\n", &idPerroAux);
					indicePerroAux = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerroAux);
					while(indicePerroAux == -1)
					{
						perro_mostrarIdPerros(perritos, cantidadPerritos);
						funcionesInputs_pedirYValidarEnteroSinRango("\nError ingrese el ID del perro a cuidar\n", "Error, reingrese el ID del perro a cuidar (numérico)\n", &idPerroAux);
						indicePerroAux = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerroAux);
					}
					idPerroAnteriorAux = estadias[indiceEstadiaAux].idPerro;
					estadias[indiceEstadiaAux].idPerro = idPerroAux;
					printf("Mostrando estadia modificada:\n%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
					nexusPerroYEstadias_mostrarEstadiaConDuenio(estadias[indiceEstadiaAux], duenios[indiceDuenioAux]);

					funcionesInputs_pedirYValidarCaracter("Esta seguro que desea modificar el perro?(s/n)\n", "Error, esta seguro que desea modificar el perro?(s/n)\n", &respuesta);
					if(respuesta == 's')
					{
						printf("Perro modificado exitosamente\n");
					}
					else
					{
						estadias[indiceEstadiaAux].idPerro = idPerroAnteriorAux;
						printf("se ha cancelado la modificacion del perro\n");
					}
					break;
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
 * @fn int nexusPerroYEstadias_contarEstadiasPerro(EstadiaDiaria*, int, perro)
 * @brief Contar la cantidad de estadias reservadas que tiene un perrito
 *
 * @param estadias listado de estadias
 * @param cantidadEstadias longitud de la lista
 * @param perrito Perrito que se cuenta en las estadias
 * @return Retorna 0 si el perrito no se encuentra en ninguna estadia reservada. Caso contrario retorna la cantidad de estadias reservadas que tiene
 */
int nexusPerroYEstadias_contarEstadiasPerro(EstadiaDiaria* estadias, int cantidadEstadias, perro perrito)
{
	int contadorPerro = 0;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(estadias[i].estadoReserva == OCUPADO && estadias[i].idPerro == perrito.id)
			{
				contadorPerro++;
			}
		}

	}
	return contadorPerro;
}

/**
 * @fn int nexusPerroYEstadias_encontrarYMostrarPerroConMasEstadias(EstadiaDiaria*, int, perro*, int)
 * @brief Encuentra y muestra el perro con mas estadías reservadas (en caso de que haya dos o más perros con la misma cantidad de estadias, muestra el primero que encuentra)
 *
 * @param estadias Listado de las estadias a buscar
 * @param cantidadEstadias longitud del listado
 * @param perritos Listado de perritos. De esta lista mostrará el que mas reservas tenga
 * @param cantidadPerritos longitud de la lista de perritos
 * @return Retorna -1 en caso de parametros invalidos. 0 en caso de encontrar el perrito con mas estadias
 */
int nexusPerroYEstadias_encontrarYMostrarPerroConMasEstadias(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int i;
	int indicePerroMax;
	int contadorPerro;
	int contadorMax;
	int indicePerro;

	if(estadias != NULL && cantidadEstadias > 0 && perritos != NULL && cantidadPerritos > 0)
	{
		for(i=0 ; i<cantidadEstadias; i++)
		{
			indicePerro = perro_encontrarPerroPorID(perritos, cantidadPerritos, estadias[i].idPerro);
			contadorPerro = nexusPerroYEstadias_contarEstadiasPerro(estadias, cantidadEstadias, perritos[indicePerro]);

			if(i == 0 || contadorPerro > contadorMax)
			{
				contadorMax = contadorPerro;
				indicePerroMax = indicePerro;
				retorno = 0;

			}
		}

		printf("Mostrando el perro con mas estadias reservadas...\n");
		perro_mostrarPerro(perritos[indicePerroMax]);

	}

	return retorno;
}

int nexusPerroYEstadias_mostrarEstadiaPorIDPerro(EstadiaDiaria* estadias, int cantidadEstadias, int idPerro, Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int i;
	int indiceDuenioAux;

	if(estadias != NULL && cantidadEstadias > 0 && idPerro>6999)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(estadias[i].idPerro == idPerro && estadias[i].estadoReserva == OCUPADO)
			{
				indiceDuenioAux = Duenio_encontrarDuenioPorID(duenios, cantidadDuenios, estadias[i].idDuenio);
				nexusPerroYEstadias_mostrarEstadiaConDuenio(estadias[i], duenios[indiceDuenioAux]);
				retorno = 0;
			}
		}

	}
	else
	{
		printf("Error al mostrar las estadias con ese perro\n");
	}
	return retorno;
}

/**
 * @fn int nexusPerroYEstadias_listarEstadiasPerros(EstadiaDiaria*, int, perro*, int)
 * @brief Muestra las estadias ordenadas por perro
 *
 * @param estadias
 * @param cantidadEstadias
 * @param perritos
 * @param cantidadPerritos
 * @return
 */
int nexusPerroYEstadias_listarEstadiasPerros(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos, Duenio* duenios, int cantidadDuenios)
{
	int retorno = -1;
	int i;
	int indicePerro;

	if(estadias != NULL && cantidadEstadias>0 && perritos != NULL && cantidadPerritos > 0)
	{
		nexus_estadiaDiariaYDuenio_ordenarEstadiasPorFecha(estadias, cantidadEstadias, duenios, cantidadDuenios);

		printf("Mostrando listado de perros con sus estadias diarias reservadas\n");
		for(i=0; i<cantidadPerritos; i++)
		{
			indicePerro = nexus_estadiaDiariaYDuenio_encontrarPerroPorIDEnEstadia(estadias, cantidadEstadias, perritos[i].id);
			if(indicePerro != -1)
			{
				printf("Monstrando estadias del perro con ID: %d - RAZA: %s - NOMBRE: %s\n", perritos[i].id, perritos[i].raza, perritos[i].nombre);
				printf("%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
				nexusPerroYEstadias_mostrarEstadiaPorIDPerro(estadias, cantidadEstadias, perritos[i].id, duenios, cantidadDuenios);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int nexusPerroYEstadias_mostrarEstadiaConDuenio(EstadiaDiaria estadia, Duenio duenioPerro)
{
	int retorno = -1;

	if(estadia.estadoReserva == OCUPADO)
	{
		printf("%-20d %-20s %-25d %-15d %-2d/%-2d/%-5d\n", estadia.id, duenioPerro.nombreDuenio, duenioPerro.telefono, estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio);
		retorno = 0;
	}
	return retorno;

}



