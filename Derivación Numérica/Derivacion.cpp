//
// Created by Maximo Chattas on 28/09/2022.
//

#include <iostream>
#include "Derivacion.h"
#include "../funcionesMatriz.h"
#include <cmath>

double f0(double x)
{
    //Funcion f
    return exp(x) * cos(x);
}

void ingresoDatosDerivacionManual(double **datos)
{
    for (int i = 0 ; i < n ; i++)
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

//void ingresoDatosDerivacionAutomatico(double **datos)
//{
//    double xi , xf;
//    std::cout << "X inicial: ";
//    std::cin >> xi;
//
//    std::cout << "X final: ";
//    std::cin >> xf;
//
//    double paso = (xf-xi)/h;
//
//    for (int i = 0 ; i < paso ; i++)
//    {
//        datos[0][i] = xi+h*i;
//        datos[1][i] = f0(datos[0][i]);
//    }
//}

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

void derivacion2Puntos()
{
    double **datos = crearMatriz(n+1 , 2);
    ingresoDatosDerivacionManual(datos);
    std::cout << "X\tf(x)\tf'(x)\n";
    for (int i = 0 ; i < n ; i++)
    {
        if (i > 0 && i < n-1)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Centrada2Puntos(datos , i);
        }

        else if (i == 0)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Progresiva2Puntos(datos , i);
        }

        else if (i == n-1)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Regresiva2Puntos(datos , i);
        }

        std::cout << '\n';
    }
}

double Progresiva3Puntos(double **datos, int indice)
{
    return (-3*datos[indice][1] + 4*datos[indice+1][1] - datos[indice+2][1])/(2*(datos[indice+1][0] - datos[indice][0]));
}

double Regresiva3Puntos(double **datos, int indice)
{
    return (datos[indice-2][1] - 4*datos[indice-1][1] + 3*datos[indice][1])/(2*(datos[indice][0] - datos[indice-1][0]));
}

double Centrada3Puntos(double **datos, int indice)
{
    return (datos[indice+1][1] - datos[indice-1][1])/(2*(datos[indice][0] - datos[indice-1][0]));
}

void derivacion3Puntos()
{
    double **datos = crearMatriz(n+1 , 2);
    ingresoDatosDerivacionManual(datos);
    std::cout << "X\tf(x)\tf'(x)\n";
    for (int i = 0 ; i < n ; i++)
    {
        if (i > 0 && i < n-1)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Centrada3Puntos(datos , i);
        }

        else if (i == 0)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Progresiva3Puntos(datos , i);
        }

        else
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Regresiva3Puntos(datos , i);
        }

        std::cout << '\n';
    }
}