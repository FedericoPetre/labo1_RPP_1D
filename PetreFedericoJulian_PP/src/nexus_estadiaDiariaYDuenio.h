/*
 * estadiaDiaria.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Federico Petre
 */

#ifndef NEXUS_ESTADIADIARIAYDUENIO_H_
#define NEXUS_ESTADIADIARIAYDUENIO_H_

#include "funcionesInputs.h"
#include "perro.h"
#include "Duenio.h"

#define OCUPADA 1
#define DISPONIBLE 0
#define CANTESTADIAS 10

typedef struct{
	int dia;
	int mes;
	int anio;
} Fecha;

typedef struct{
	int id;
	int idDuenio;
	int idPerro;
	Fecha fecha;
	int estadoReserva;

} EstadiaDiaria;

int nexus_estadiaDiariaYDuenio_inicializarEstadias(EstadiaDiaria* estadias, int cantidadEstadias);
int nexus_estadiaDiariaYDuenio_encontrarEstadiaVacia(EstadiaDiaria* estadias, int cantidadEstadias);
Fecha nexus_estadiaDiariaYDuenio_registrarFecha(void);
int nexus_estadiaDiariaYDuenio_mostrarEstadia(EstadiaDiaria estadia, Duenio* duenios, int cantidadDuenios);
int nexus_estadiaDiariaYDuenio_listarEstadias(EstadiaDiaria* estadias, int cantidadEstadias, Duenio* duenios, int cantidadDuenios);
int nexus_estadiaDiariaYDuenio_encontrarEstadiaPorID(EstadiaDiaria* estadias, int cantidadEstadias, int id);
int nexus_estadiaDiariaYDuenio_mostrarIDS(EstadiaDiaria* estadias, int cantidadEstadias);
int nexus_estadiaDiariaYDuenio_bajaEstadia(EstadiaDiaria* estadias, int cantidadEstadias, Duenio* duenios, int cantidadDuenios);
int nexus_estadiaDiariaYDuenio_compararFechas(Fecha fecha1, Fecha fecha2);
int nexus_estadiaDiariaYDuenio_ordenarEstadiasPorFecha(EstadiaDiaria* estadias, int cantidadEstadias, Duenio* duenios, int cantidadDuenios);
int nexus_estadiaDiariaYDuenio_encontrarPerroPorIDEnEstadia(EstadiaDiaria* estadias, int cantidadEstadias, int idPerro);





#endif /* NEXUS_ESTADIADIARIAYDUENIO_H_ */
