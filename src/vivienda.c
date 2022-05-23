/*
 * vivienda.c
 *
 *  Created on: 20 may. 2022
 *      Author: BETO
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "censista.h"
#include "vivienda.h"
#include "utn_Input.h"

#define OCUPADO 1
#define DESOCUPADO 0

int opcionMM;

int iniciarVivienda(eVivienda* vivienda, int len){
	int retorno;

	if(vivienda != NULL && len > 0){
		for(int i=0; i<len;i++){
			(vivienda+i)->idVivienda = 20000;
			(vivienda+i)->isEmpty = DESOCUPADO;
			retorno = 1;
		}
	} else {
		retorno = 0;
	}
	return retorno;
}

int buscarVivienda(eVivienda* vivienda, int len, int id){
	int retorno;

	if(vivienda != NULL && len > 0){
		for(int i=0; i<len; i++){
			if((vivienda+i)->idVivienda == id && (vivienda+i)->isEmpty == OCUPADO){
				retorno = id;
				break;
			} else {
				retorno = 1;
			}
		}
	} else {
		retorno = 2;
	}
	return retorno;
}

void altaVivienda(eVivienda* vivienda, int len, int idV){

	if(vivienda != NULL && len > 0){
		for(int i=0; i<TAM; i++){
			if((vivienda+i)->isEmpty == DESOCUPADO){
			fflush(stdin);
			printf("\n-----------------Ingreso de datos---------------------------\n");
			(vivienda+i)->idVivienda = idV;
			printf("%d", (vivienda+i)->idVivienda);
			rellenarChar((vivienda+i)->calle,"\n\nIngrese la calle: \n---> ");
			strupr((vivienda+i)->calle);
			rellenarInt(&(vivienda+i)->cantPersonas, "\nIngrese la cantidad de personas en la vivienda: \n---> ", "\nError! Reintente--->");
			rellenarInt(&(vivienda+i)->cantHabitaciones, "\nIngrese la cantidad de habitaciones en la vivienda: \n---> ", "\nError! Reintente--->");
			rellenarInt(&(vivienda+i)->tipoVivienda, "\n1)CASA\n2)DEPARTAMENTO\n3)CASILLA\n4)RANCHO\nIngrese el tipo de vivienda: \n--->", "\nError! Reintente--->");
			rellenarInt(&(vivienda+i)->legajoCensista.legajo, "\nIngrese el legajo del censista: \n--->", "\nError! Reintente--->");
			(vivienda+i)->isEmpty = OCUPADO;
		break;
			}
		}
	} else {
		printf("Hubo un error!!!");
	}
}

int modificarVivienda(eVivienda* vivienda, int len, int idMod){
	int id;
	int retorno = 0;
	id = buscarVivienda(vivienda, len, idMod);

	if(vivienda != NULL && len > 0){
		for(int i=0; i<len; i++){
			if((vivienda+i)->idVivienda == id && (vivienda+i)->isEmpty == OCUPADO){
				do{
					printf("\n1-Calle."
							"\n2-Cantidad de personas en la vivienda."
							"\n3-Cantidad de habitaciones en la vivienda."
							"\n4-Tipo de vivienda."
							"\n5-Salir"
							"\n\nIngrese la opcion a modificar: ");
					scanf("%d", &opcionMM);
					fflush(stdin);
					switch(opcionMM){
						case 1:
							printf("\nEl nombre de la calle a modificar es: %s", (vivienda+i)->calle);
							rellenarChar((vivienda+i)->calle, "\nIngrese el nuevo nombre de la calle: ");
							strupr((vivienda+i)->calle);
							break;
						case 2:
							printf("\nLa cantidad de personas en la vivienda son: %d", (vivienda+i)->cantPersonas);
							rellenarInt(&(vivienda+i)->cantPersonas, "\nIngrese la cantidad de personas actualizada: ", "\nError! Reingrese: ");
							break;
						case 3:
							printf("\nLa cantidad de habitaciones en la vivienda son: %d", (vivienda+i)->cantHabitaciones);
							rellenarInt(&(vivienda+i)->cantHabitaciones, "\nIngrese la cantidad de habitaciones actualizada: ", "\nError! Reingrese: ");
							break;
						case 4:
							printf("\nEl tipo de vivienda a modificar es");
							if((vivienda+i)->tipoVivienda == 1){
								printf(" CASA");
							} else {
								if((vivienda+i)->tipoVivienda == 2){
										printf(" DEPARTAMENTO");
								} else {
									if((vivienda+i)->tipoVivienda == 3){
										printf(" CASILLA");
									} else {
										printf(" RANCHO");
									}
								}
							}
							rellenarInt(&(vivienda+i)->tipoVivienda, "\n1)CASA\n2)DEPARTAMENTO\n3)CASILLA\n4)RANCHO\nIngrese el nuevo tipo de vivienda: ", "\nError!, Reingrese: ");
							break;
						case 5:
							printf("\nVolviendo al menu principal...");
							break;
						default:
							printf("\nOpcion incorrecta!");
							break;
					}
				}while(opcionMM != 5);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int eliminarVivienda(eVivienda* vivienda, int len, int idElim){
	int id;
	int retorno = 0;
	id = buscarVivienda(vivienda, len, idElim);

	if(vivienda != NULL && len > 0){
		for(int i=0; i<len; i++){
			if((vivienda+i)->idVivienda == id && (vivienda+i)->isEmpty == OCUPADO){
				(vivienda+i)->isEmpty = DESOCUPADO;
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

void listaVivienda(eVivienda* vivienda, int len){

	eVivienda listaAux;

	for(int i=0; i<len; i++){
		for(int j=i+1; j<len; j++){
			if((vivienda+i)->isEmpty == OCUPADO && (vivienda+j)->isEmpty == OCUPADO){
				if((strcmp((vivienda+i)->calle, (vivienda+j)->calle))>0){ // || (vivienda+i)->tipoVivienda < (vivienda+1)->tipoVivienda
					listaAux = vivienda[i];
					vivienda[i] = vivienda[j];
					vivienda[j] = listaAux;
				} else {
					if(strcmp((vivienda+i)->calle, (vivienda+j)->calle) == 0 && (vivienda+i)->tipoVivienda < (vivienda+j)->tipoVivienda){
						listaAux = vivienda[i];
						vivienda[i] = vivienda[j];
						vivienda[j] = listaAux;
					}
				}
			}
		}
	}

	printf("\n\n-----------------Lista de viviendas--------------------------");
	printf("\n VIVIENDA   ||        CALLE        || PERSONAS || HABITACIONES  ||   TIPO DE VIVIENDA   ");
	if(vivienda != NULL && len > 0){
		for(int i=0; i<len; i++){
			if((vivienda+i)->isEmpty == OCUPADO){
				printf("\n------------------------------------------------------------------------------------------------------");
				printf("\n   %d         %s                  %d             %d                ",
						(vivienda+i)->idVivienda, (vivienda+i)->calle, (vivienda+i)->cantPersonas, (vivienda+i)->cantHabitaciones);
				if((vivienda+i)->tipoVivienda == 1){
					printf("CASA");
				} else {
					if((vivienda+i)->tipoVivienda == 2){
						printf("DEPARTAMENTO");
					} else {
						if((vivienda+i)->tipoVivienda == 3){
							printf("CASILLA");
						} else {
							printf("RANCHO");
						}
					}
				}
			}
		}
	}
}