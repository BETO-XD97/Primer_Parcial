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

/**
 * brief Inicializa los idVivienda en 20000 y el isEmpty en 0
 * @param vivienda nombre de estructura
 * @param len tamaño de la estructura
 * @return 1 inicializacion exitosa, 0 no exitosa
 */
int iniciarVivienda(eVivienda* vivienda, int len);

/**
 *	brief Ingreso los datos de las vivienda
 * @param vivienda nombre de estructura
 * @param len tamaño de la estructura
 * @param idV contador de la vivienda
 */
void altaVivienda(eVivienda* vivienda, int len, int idV);

/**
 * brief Modifica los datos calle, personas, habitaciones, tipo de la vivienda
 * @param vivienda nombre de estructura
 * @param len tamaño de la estructura
 * @param idMod ingreso del id a modificar
 * @return 1 modificacion exitosa, 0 no exitosa
 */
int modificarVivienda(eVivienda* vivienda, int len, int idMod);

/**
 * brief Elimina la vivienda segun el id
 * @param vivienda nombre de estructura
 * @param len tamaño de la estructura
 * @param idElim ingreso del id a eliminar
 * @return 1 eliminacion exitosa, 2 eliminacion no exitosa, 3 id no encontrado
 */
int eliminarVivienda(eVivienda* vivienda, int len, int idElim);

/**
 *	brief Lista las vivienda segun calle o segun cantidad personas
 * @param vivienda nombre de estructura
 * @param len tamaño de la estructura
 */
void listaVivienda(eVivienda* vivienda, int len);

/**
 * brief Imprime la lista de viviendas
 * @param vivienda nombre de estructura
 * @param len tamaño de la estructura
 */
void imprimirVivienda(eVivienda* vivienda, int len);
