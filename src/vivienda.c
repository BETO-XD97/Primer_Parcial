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
#include <conio.h>

#include "censista.h"
#include "vivienda.h"
#include "utn_Input.h"

#define OCUPADO 1
#define DESOCUPADO 0
#define MAX 1000000
#define TAMC 25

int opcionMM;
int valChar;

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
			do{
				valChar = rellenarChar((vivienda+i)->calle,"\n\nIngrese la calle: \n---> ");
			}while(valChar != 0);
			strupr((vivienda+i)->calle);
			rellenarInt(&(vivienda+i)->cantPersonas, "\nIngrese la cantidad de personas en la vivienda: \n---> ", "\nError! Reintente ---> ", 1, MAX);
			rellenarInt(&(vivienda+i)->cantHabitaciones, "\nIngrese la cantidad de habitaciones en la vivienda: \n---> ", "\nError! Reintente ---> ", 1, MAX);
			rellenarInt(&(vivienda+i)->tipoVivienda, "\n1)CASA\n2)DEPARTAMENTO\n3)CASILLA\n4)RANCHO\nIngrese el tipo de vivienda: \n--->", "\nError! Reintente ---> ", 1, 4);
			rellenarInt(&(vivienda+i)->legajoCensista, "\nIngrese el legajo del censista-> 100-Ana / 101-Juan / 102-Sol \n--->", "\nError! Reintente ---> ", 100, 102);
			(vivienda+i)->isEmpty = OCUPADO;
		break;
			}
		}
	} else {
		printf("Hubo un error!");
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
							"\n\nIngrese la opcion a modificar ---> ");
					scanf("%d", &opcionMM);
					fflush(stdin);
					switch(opcionMM){
						case 1:
							printf("\nEl nombre de la calle a modificar es: %s", (vivienda+i)->calle);
							do{
								valChar = rellenarChar((vivienda+i)->calle,"\n\nIngrese la calle: \n---> ");
							}while(valChar != 0);
							strupr((vivienda+i)->calle);
							break;
						case 2:
							printf("\nLa cantidad de personas en la vivienda son: %d", (vivienda+i)->cantPersonas);
							rellenarInt(&(vivienda+i)->cantPersonas, "\nIngrese la cantidad de personas actualizada: ", "\nError! Reingrese ---> ",0,MAX);
							break;
						case 3:
							printf("\nLa cantidad de habitaciones en la vivienda son: %d", (vivienda+i)->cantHabitaciones);
							rellenarInt(&(vivienda+i)->cantHabitaciones, "\nIngrese la cantidad de habitaciones actualizada: ", "\nError! Reingrese ---> ",0,MAX);
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
							rellenarInt(&(vivienda+i)->tipoVivienda, "\n1)CASA\n2)DEPARTAMENTO\n3)CASILLA\n4)RANCHO\nIngrese el nuevo tipo de vivienda: ", "\nError! Reingrese ---> ",1,4);
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
	int id, opcion;
	int retorno;
	id = buscarVivienda(vivienda, len, idElim);

	if(vivienda != NULL && len > 0){
		for(int i=0; i<len; i++){
			if((vivienda+i)->idVivienda == id){
				rellenarInt(&opcion, "\nSeguro que desea eliminar esta ID 1-Si / 2-No \n---> ", "\nError! Reintentar ---> ", 1, 2);
				if(opcion == 1){
					if((vivienda+i)->idVivienda == id && (vivienda+i)->isEmpty == OCUPADO){
						(vivienda+i)->isEmpty = DESOCUPADO;
						retorno = 1;
						break;
					}
				} else {
					retorno = 2;
					break;
				}
			} else {
				retorno = 3;
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
				if((strcmp((vivienda+i)->calle, (vivienda+j)->calle))>0){
					listaAux = vivienda[i];
					vivienda[i] = vivienda[j];
					vivienda[j] = listaAux;
				} else {
					if(strcmp((vivienda+i)->calle, (vivienda+j)->calle) == 0 && (vivienda+i)->cantPersonas > (vivienda+j)->cantPersonas){
						listaAux = vivienda[i];
						vivienda[i] = vivienda[j];
						vivienda[j] = listaAux;
					}
				}
			}
		}
	}


}

void imprimirVivienda(eVivienda* vivienda, int len){

	listaVivienda(vivienda,len);

	printf("\n\n-----------------Lista de viviendas--------------------------");
		printf("\n\n VIVIENDA   |  L.CENSISTA  |      CALLE        | PERSONAS | HABITACIONES  |   TIPO DE VIVIENDA  ");
		if(vivienda != NULL && len > 0){
			for(int i=0; i<len; i++){
				if((vivienda+i)->isEmpty == OCUPADO){
					printf("\n------------------------------------------------------------------------------------------------------");
					printf("\n   %d    |      %d     | %s           |     %d    |      %d        |         ",
							(vivienda+i)->idVivienda,(vivienda+i)->legajoCensista, (vivienda+i)->calle, (vivienda+i)->cantPersonas, (vivienda+i)->cantHabitaciones);
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

