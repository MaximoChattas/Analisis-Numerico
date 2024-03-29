//
// Created by Maximo Chattas on 30/09/2022.
//

#ifndef MÉTODOS_FUNCIONESMATRIZ_H
#define MÉTODOS_FUNCIONESMATRIZ_H

#define cantPuntos 10

double *crearArray(int filas);

double **crearMatriz(int filas, int columnas);

void mostrarArray(double* array);

void mostrarMatriz(double** matriz , int filas , int columnas);

void ingresoDatos(double **datos);

void ingresoDatosAutomatico(double **datos);

double f0(double x);

#endif //MÉTODOS_FUNCIONESMATRIZ_H
