//
// Created by Maximo Chattas on 30/09/2022.
//

#include <iostream>
#include "funcionesMatriz.h"

double *crearArray(int filas)
{
    double* array = new double [filas];
    return array;
}

double **crearMatriz(int filas , int columnas)
{
    double** matriz = new double *[filas];
    for (int i = 0 ; i < filas ; i++)
    {
        matriz[i] = new double [columnas];
    }
    return matriz;
}

void mostrarArray(double *array)
{
    for (int i = 0 ; i < sizeof(array) ; i++)
    {
        std::cout << array[i] << '\t';
    }
    std::cout << '\n';

}

void mostrarMatriz(double **matriz, int filas, int columnas)
{
    for (int i = 0 ; i < filas ; i++)
    {
        for (int j = 0 ; j < columnas ; j++)
        {
            std::cout << matriz[i][j] << '\t';
        }
        std::cout << '\n';
    }

}