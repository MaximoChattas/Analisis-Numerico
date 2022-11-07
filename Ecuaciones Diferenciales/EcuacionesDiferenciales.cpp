//
// Created by Maximo Chattas on 07/11/2022.
//

#include "../Funciones Matriz/funcionesMatriz.h"
#include "EcuacionesDiferenciales.h"
#include <iostream>
#include <cmath>

double f(double x , double y)
{
    return exp(0.8 * x) - 0.5 * y;
}

void euler()
{
    double x0 , y0;

    std::cout << "x0 = ";
    std::cin >> x0;
    std::cout << "y(" << x0 << ") = ";
    std::cin >> y0;

    double **datos = crearMatriz(cantPuntos , 2);

    //Condiciones iniciales
    datos[0][0] = x0;
    datos[0][1] = y0;

    for (int i = 1 ; i < cantPuntos ; i++)
    {
        datos[i][0] = datos[i-1][0]+h
        datos[i][1] = datos[i-1][1] + f(datos[i-1][0] , datos[i-1][1])*h
    }

    mostrarMatriz(datos , cantPuntos , 2);
}
