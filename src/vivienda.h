/*
 * vivienda.h
 *
 *  Created on: 20 may. 2022
 *      Author: BETO
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#include "censista.h"
#include "utn_Input.h"

#define TAM 5
#define TAMC 25

typedef struct{

	int idVivienda;
	char calle[TAMC];
	int cantPersonas;
	int cantHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;

} eVivienda;

#endif /* VIVIENDA_H_ */

int iniciarVivienda(eVivienda* vivienda, int len);

void altaVivienda(eVivienda* vivienda, int len, int idV);

int modificarVivienda(eVivienda* vivienda, int len, int idMod);

int eliminarVivienda(eVivienda* vivienda, int len, int idElim);

void listaVivienda(eVivienda* vivienda, int len);

void imprimirVivienda(eVivienda* vivienda, int len);
