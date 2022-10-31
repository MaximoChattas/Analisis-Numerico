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

void ingresoDatosDerivacionAutomatico(double **datos)
{
    float xi , xf;
    std::cout << "X inicial: ";
    std::cin >> xi;

    std::cout << "X final: ";
    std::cin >> xf;

    int i = 0;
    do {
        datos[i][0] = xi;
        datos[i][1] = f0(xi);

        xi += h;
        i++;

    }while(i < n);
}

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
    double **datos = crearMatriz(n , 2);
    ingresoDatosDerivacionAutomatico(datos);
    std::cout << "X\tf(x)\tf'(x)\n";
    for (int i = 0 ; i < n ; i++)
    {
        if (i > 0 && i < n-1)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Centrada3Puntos(datos , i) << "\t Centrada";
        }

        else if (i == 0)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Progresiva3Puntos(datos , i) << "\t Progresiva";
        }

        else
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Regresiva3Puntos(datos , i) << "\t Regresiva";
        }

        std::cout << '\n';
    }
}

double Progresiva5Puntos(double **datos, int indice)
{
    return (-25*datos[indice][1] + 48*datos[indice+1][1] - 36*datos[indice+2][1] + 16*datos[indice+3][1] -
    3*datos[indice+4][1])/(12*(datos[indice+1][0]-datos[indice][0]));
}

double Regresiva5Puntos(double **datos, int indice) {
    return (3*datos[indice-4][1] - 16*datos[indice-3][1] + 36*datos[indice-2][1] - 48*datos[indice-1][1] +
    25*datos[indice][1])/(12*(datos[indice][0]-datos[indice-1][0]));
}

double Centrada5Puntos(double **datos, int indice) {
    return (datos[indice-2][1] - 8*datos[indice-1][1] + 8*datos[indice+1][1] - datos[indice+2][1])/
            (12*(datos[indice+1][0]-datos[indice][0]));
}

void derivacion5Puntos()
{
    double **datos = crearMatriz(n , 2);
    ingresoDatosDerivacionAutomatico(datos);
    std::cout << "X\t\tf(x)\tf'(x)\n";
    for (int i = 0 ; i < n ; i++)
    {
        if (i > 1 && i < n-2)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Centrada5Puntos(datos , i) << "\t Centrada";
        }

        else if (i <= 1)
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Progresiva5Puntos(datos , i) << "\t Progresiva";
        }

        else
        {
            std::cout << datos[i][0] << '\t' << datos[i][1] << '\t' << Regresiva5Puntos(datos , i) << "\t Regresiva";
        }

        std::cout << '\n';
    }
}
