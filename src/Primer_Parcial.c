/*
 ============================================================================
 Name        : Primer_Parcial.c
 Author      : Roberto Rocabado
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "vivienda.h"
#include "censista.h"
#include "utn_Input.h"

#define TAMV 5
#define TAMCEN 3
#define TAMC 25
#define MAX 1000000

//Variables generales

int opcionMP;
int rtn;
int idMod;
int idElim;
int idModificado;
int idEliminado;
int idV = 20000;
int datoUno = 0;

int main(void) {
	setbuf(stdout, NULL);

	eVivienda vivienda[TAMV];
	eVivienda* pVivienda;
	pVivienda = vivienda;

	eCensista censista[TAMCEN] = {{100, "Ana", 34, "1203-2345"},
								  {101, "Juan", 24, "4301-54678"},
								  {102, "Sol", 47, "5902-37487"}
								 };
	eCensista* pCensista;
	pCensista = censista;

	rtn = iniciarVivienda(pVivienda,TAMV);

	if(rtn == 1){
		do{
			printf("\n\n-----------------Bienvenido al censo 2022---------------------");
			printf("\n\n1)ALTA VIVIENDA"
					"\n2)MODIFICAR VIVIENDA"
					"\n3)BAJA VIVIENDA"
					"\n4)LISTAR VIVIENDA"
					"\n5)LISTAR CENSISTA"
					"\n6)SALIR"
					"\nIngrese su opcion--->");
			fflush(stdin);
			scanf("%d", &opcionMP);

			switch(opcionMP){
				case 1:
						idV++;
						for(int i=0;i<TAMV;i++){
							altaVivienda(pVivienda, TAMV, idV);
							break;
						}
						datoUno = 1;
					break;

				case 2:
						if(datoUno == 1){
							rellenarInt(&idMod, "\nIngrese el ID de la vivienda a modificar: \n--->", "\nError! Reintente ---> ", 0, MAX);

							idModificado = modificarVivienda(pVivienda, TAMV, idMod);

							if(idModificado == 1){
								printf("\n\n\nEl usuario ha sido modificado con exito");
							} else {
								printf("\nEl ID de la vivienda no ha sido encontrado");
							}
						} else {
							printf("\nNo ha ingresado ningun dato!");
						}
					break;

				case 3:
						if(datoUno == 1){
							rellenarInt(&idElim, "\nIngrese el ID de la vivienda a eliminar: \n--->", "\nError! Reintente ---> ", 0, MAX);

							idEliminado = eliminarVivienda(pVivienda, TAMV, idElim);

							switch(idEliminado){
							 	case 1:
							 		printf("\nEl usuario ha sido eliminado con exito!\n");
							 		break;
							 	case 2:
							 		printf("\nUsted decidio no elminar el ID de la vivienda!\n");
							 		break;
							 	case 3:
							 		printf("\nEl ID de la vivienda no ha sido encontrado o ya fue eliminado!\n");
							 		break;
							}
						} else {
							printf("\nNo ha ingresado ningun dato!");
						}
					break;

				case 4:
						if(datoUno == 1){
							imprimirVivienda(pVivienda, TAMV);
						} else {
							printf("\nNo ha ingresado ningun dato!");
						}
					break;

				case 5:

						imprimirCensista(pCensista, TAMCEN);

					break;

				case 6:

						printf("\nSaliendo del sistema!!!");
					break;

				default:
					printf("\nLa opcion NO es valida, reintentar!!!");
					break;
			}

		}while(opcionMP != 6);

	} else {
		printf("Hubo un problema al cargar el sistema!!!");
	}

	return 0;
}
