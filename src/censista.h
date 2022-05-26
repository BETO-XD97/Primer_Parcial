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

/**
 * brief Lista a los censistas segun nombre
 * @param censista
 * @param len
 */
void listaCensista(eCensista* censista, int len);

/**
 * brief Imprime la lista de censista
 * @param censista
 * @param len
 */
void imprimirCensista(eCensista* censista, int len);
