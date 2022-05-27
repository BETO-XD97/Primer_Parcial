/*
 * censista.c
 *
 *  Created on: 20 may. 2022
 *      Author: BETO
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define OCUPADO 1
#include "vivienda.h"
#include "censista.h"
int censista100=0;
int censista101=0;
int censista102=0;

void listaCensista(eCensista* censista, int len){

	eCensista listaAux;

	if(censista != NULL && len > 0){
		for(int i=0; i<len; i++){
			for(int j=i+1; j<len; j++){
			if((strcmp((censista+i)->nombre,(censista+j)->nombre))>0){
				listaAux = censista[i];
				censista[i] = censista[j];
				censista[j] = listaAux;
			}
			}
		}
	}

}

void imprimirCensista(eCensista* censista,int len,eVivienda* vivienda, int lenV){

	listaCensista(censista,len);


	printf("\n-------------------CENSISTAS-----------------------");
		printf("\n\n  LEGAJO  |   NOMBRE  |   EDAD  | TELEFONO  ");
		for(int i=0; i<len; i++){
			printf("\n------------------------------------------------"
					"\n   %d    |   %s     |   %d    | %s   ",
					(censista+i)->legajo,(censista+i)->nombre, (censista+i)->edad,(censista+i)->telefono);

		}


		printf("\n\n-----------------Lista de viviendas--------------------------");
				printf("\n\n VIVIENDA   |  L.CENSISTA  |      CALLE        | PERSONAS | HABITACIONES  |   TIPO DE VIVIENDA  ");
				if(vivienda != NULL && len > 0){
					for(int i=0; i<lenV; i++){
						if((vivienda+i)->isEmpty == OCUPADO && ((vivienda+i)->legajoCensista == (censista+i)->legajo)){
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
		for(int i=0;i<lenV;i++){
			if((vivienda+i)->legajoCensista == 101){
				censista100++;
			} else {
				if((vivienda+i)->legajoCensista == 102){
					censista101++;
				} else {
					if((vivienda+i)->legajoCensista == 103){
						censista102++;
					}
				}
			}
		}

		if(censista100 > censista101 && censista100 > censista102){
			printf("\n\nEl censista con mas vivienda censadas fue Ana con legajo 100");

		} else {
			if(censista101 > censista102){
				printf("\n\nEl censista con mas vivienda censadas fue Juan con legajo 101");
			} else {
				printf("\n\nEl censista con mas vivienda censadas fue Sol con legajo 102");
			}
		}
}

