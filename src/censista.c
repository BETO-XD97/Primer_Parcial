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

#include "vivienda.h"

//eCensista censista[3] = {{100, "Ana", 34, 1203-2345},{101, "Juan", 24, 4301-54678}, {102, "Sol", 47, 5902-37487}};
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
	printf("\n-------------------CENSISTAS-----------------------");
	printf("\n  LEGAJO ||   NOMBRE ||   EDAD   || TELEFONO  ");
	for(int i=0; i<len; i++){
		printf("\n-------------------------------------------------------"
				"\n   %d        %s           %d        %s   ",
				(censista+i)->legajo,(censista+i)->nombre, (censista+i)->edad,(censista+i)->telefono);
	}
}
