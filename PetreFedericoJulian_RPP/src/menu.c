/*
 * menu.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Federico Petre
 */

#include "menu.h"

void mostrarMenu(void)
{
	setbuf(stdout, NULL);
	int opcion = -1;
	int contadorEstadias = 0;
	int idEstadia = 100000;
	int confirmacionReservaAltaCancelacion;

	EstadiaDiaria estadias[30];

	perro perros[CANTPERROS];

	Duenio duenios[5];

	perro_inicializarPerros(perros, CANTPERROS);
	perro_hardCodearPerros(perros, CANTPERROS);
	nexus_estadiaDiariaYDuenio_inicializarEstadias(estadias, CANTESTADIAS);

	Duenio_hardcodearDuenios(duenios, 5);

	printf("Bienvenido a la guardería de perros\n");

	while(opcion != 9)
	{
		 funcionesInputs_pedirYValidarEntero("Elija una opcion (1-9):\n1- RESERVAR ESTADIA\n2- MODIFICAR ESTADIA\n3- CANCELAR ESTADIA\n4- LISTAR ESTADIAS\n5- LISTAR PERROS\n6- Promedio de edad de los perros\n7- Perro con mas estadias reservadas\n8- Listado de perros con sus estadias diarias reservadas\n9- SALIR\n", "Error, elija una opcion (1-9):\n1- RESERVAR ESTADIA\n2- MODIFICAR ESTADIA\n3- CANCELAR ESTADIA\n4- LISTAR ESTADIAS\n5- LISTAR PERROS\n6- Promedio de edad de los perros\n7- Perro con mas estadias reservadas\n8- Listado de perros con sus estadias diarias reservadas\n9- SALIR\n", 1, 9, &opcion);

		 switch(opcion)
		 {
			 case 1:
				 printf("Ha elejido la opcion 1- RESERVAR ESTADIA\n");
				 confirmacionReservaAltaCancelacion = nexusPerroYEstadias_AltaEstadia(estadias, CANTESTADIAS, idEstadia , perros, CANTPERROS, duenios, 5);
				 contadorEstadias++;
				 idEstadia++;
				 if(confirmacionReservaAltaCancelacion == -1)
				 {
					 contadorEstadias--;
					 idEstadia--;
				 }
				 break;
			 case 2:
				 printf("Ha elejido la opcion 2- MODIFICAR ESTADIA\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 nexusPerroYEstadias_modificarEstadia(estadias, CANTESTADIAS, perros, CANTPERROS, duenios, 5);
				 }

				 break;
			 case 3:
				 printf("Ha elejido la opcion 3- CANCELAR ESTADIA\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 confirmacionReservaAltaCancelacion = nexus_estadiaDiariaYDuenio_bajaEstadia(estadias, CANTESTADIAS, duenios, 5);
					 if(confirmacionReservaAltaCancelacion == 0)
					 {
						 contadorEstadias--;
					 }
				 }

				 break;
			 case 4:
				 printf("Ha elejido la opcion 4- LISTAR ESTADIAS\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 nexus_estadiaDiariaYDuenio_ordenarEstadiasPorFecha(estadias, CANTESTADIAS, duenios, 5);
					 nexus_estadiaDiariaYDuenio_listarEstadias(estadias, CANTESTADIAS, duenios, 5);
				 }

				 break;
			 case 5:
				 printf("Ha elejido la opcion 5- LISTAR PERROS\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 perro_ListarPerros(perros, CANTPERROS);
				 }

				 break;
			 case 6:
				 printf("Ha elejido la opcion 6- Promedio de edad de los perros\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 perro_mostrarPromedioDeEdad(perros, CANTPERROS);
				 }

				 break;
			 case 7:
				 printf("Ha elejido la opcion 7- Perro con mas estadias reservadas\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 nexusPerroYEstadias_encontrarYMostrarPerroConMasEstadias(estadias, CANTESTADIAS, perros, CANTPERROS);
				 }
				 break;
			 case 8:
				 printf("Ha elejido la opcion 8- Listado de perros con sus estadias diarias reservadas\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 nexusPerroYEstadias_listarEstadiasPerros(estadias, CANTESTADIAS, perros, CANTPERROS, duenios, 5);
				 }
				 break;
			 case 9:
				 printf("Ha elejido la opcion 9- SALIR\nSaliendo del sistema....\nHas salido del sistema\n");
				 break;
		 }

		 if(opcion != 9)
		 {
			 system("pause");
		 }

	}

}

