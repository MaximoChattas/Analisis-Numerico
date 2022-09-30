//
// Created by Maximo Chattas on 28/09/2022.
//

#include <iostream>
#include "Derivacion.h"
#include "../funcionesMatriz.h"

double Progresiva2Puntos(double** datos , int indice)
{
    return ((datos[indice+1][1] - datos[indice][1])/h);
}

double Regresiva2Puntos(double **datos, int indice) {
    return ((datos[indice][1] - datos[indice-1][1])/h);
}

double Centrada2Puntos(double **datos, int indice) {
    return ((datos[indice+1][1] - datos[indice-1][1])/(2*h));
}

void ingresoDatosDerivacion(double **datos)
{
    for (int i = 0 ; i < Puntos ; i++)
    {
        for (int j = 0 ; j < 2 ; j++)
        {
            if (j == 0)
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

void derivacion2Puntos(double **datos)
{
    std::cout << "X\tf(x)\tf'(x)\n";
    for (int i = 0 ; i < Puntos ; i++)
    {
        if (i > 0 && i < Puntos-1)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Centrada2Puntos(datos , i);
        }

        else if (i == 0)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Progresiva2Puntos(datos , i);
        }

        else if (i == Puntos-1)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Regresiva2Puntos(datos , i);
        }

        std::cout << '\n';
    }
}
