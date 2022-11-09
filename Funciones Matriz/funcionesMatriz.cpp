//
// Created by Maximo Chattas on 30/09/2022.
//

#include <iostream>
#include <cmath>
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

void ingresoDatos(double **datos)
{
    for (int i = 0 ; i < cantPuntos ; i++)
    {
        for (int j = 0 ; j < 2 ; j++)
        {
            if (j==0)
            {
                std::cout << "X " << i << ": ";
            }
            else
            {
                std::cout << "Y " << i << ": ";
            }

            std::cin >> datos[i][j];
        }
    }
}

void ingresoDatosAutomatico(double **datos)
{
    float xi , xf , h;
    std::cout << "X inicial: ";
    std::cin >> xi;

    std::cout << "X final: ";
    std::cin >> xf;

    std::cout << "h: ";
    std::cin >> h;

    int i = 0;
    do {
        datos[i][0] = xi;
        datos[i][1] = f0(xi);

        xi += h;
        i++;

    }while(i < cantPuntos);
}

//Funcion para Derivacion, Integracion
double f0(double x)
{
    //Funcion f
    return (4*x + 1)/(pow(x , 2));
}