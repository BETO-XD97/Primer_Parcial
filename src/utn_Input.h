/*
 * utn_Input.h
 *
 *  Created on: 21 may. 2022
 *      Author: BETO
 */

#ifndef UTN_INPUT_H_
#define UTN_INPUT_H_


#endif /* UTN_INPUT_H_ */

/**
 * \brief Enter a number and store it in a memory space of type int
 * @param inputInt* int
 * @param inputChar[] char
 * @param inputError[] char
 */
void rellenarInt(int* inputInt, char inputChar[], char inputError[]);

/**
 * \brief Enter a number and store it in a memory space of type float
 * @param inputFloat*
 * @param inputChar[] char
 * @param inputError[] char
 */
void rellenarFloat(float* inputFloat, char inputChar[], char inputError[]);

/**
 * Enter a data of type char and save it in a memory space of type char
 * @param inputChar[] char
 * @param outputChar[] char
 */
void rellenarChar(char inputChar[], char outputChar[]);
