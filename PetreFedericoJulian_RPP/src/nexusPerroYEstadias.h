/*
 * nexusPerroYEstadias.h
 *
 *  Created on: 9 oct. 2021
 *      Author: Federico Petre
 */

#ifndef NEXUSPERROYESTADIAS_H_
#define NEXUSPERROYESTADIAS_H_

#include "perro.h"
#include "Duenio.h"
#include "nexus_estadiaDiariaYDuenio.h"

EstadiaDiaria nexusPerroYEstadias_reservarEstadia(int id, int idDuenio, int idPerro, Fecha fecha);
int nexusPerroYEstadias_AltaEstadia(EstadiaDiaria* estadias, int cantidadEstadias, int idEstadia, perro* perritos, int cantidadPerritos, Duenio* duenios, int cantidadDuenios);
int nexusPerroYEstadias_modificarEstadia(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos, Duenio* duenios, int cantidadDuenios);
int nexusPerroYEstadias_contarEstadiasPerro(EstadiaDiaria* estadias, int cantidadEstadias, perro perrito);
int nexusPerroYEstadias_encontrarYMostrarPerroConMasEstadias(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos);
int nexusPerroYEstadias_mostrarEstadiaPorIDPerro(EstadiaDiaria* estadias, int cantidadEstadias, int idPerro, Duenio* duenios, int cantidadDuenios);
int nexusPerroYEstadias_listarEstadiasPerros(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos, Duenio* duenios, int cantidadDuenios);
int nexusPerroYEstadias_mostrarEstadiaConDuenio(EstadiaDiaria estadia, Duenio duenioPerro);



#endif /* NEXUSPERROYESTADIAS_H_ */
