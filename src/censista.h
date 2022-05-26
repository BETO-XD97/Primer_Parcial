/*
 * censista.h
 *
 *  Created on: 20 may. 2022
 *      Author: BETO
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#define TAMC 25

typedef struct{

	int legajo;
	char nombre[TAMC];
	int edad;
	char telefono[TAMC];

} eCensista;

#endif /* CENSISTA_H_ */

void listaCensista(eCensista* censista, int len);

void imprimirCensista(eCensista* censista, int len);
