//
// Created by Maximo Chattas on 01/11/2022.
//

#include <iostream>
#include "Integracion.h"
#include "../funcionesMatriz.h"

double trapecios()
{
    double integral = 0;
    double** datos = crearMatriz(n , 2);
    ingresoDatos(datos , n);
    mostrarMatriz(datos , n , 2);

    for (int i = 1 ; i < n-1 ; i++)
    {
        integral += 2*datos[i][1];
    }
    integral += datos[0][1];
    integral += datos[n-1][1];

    integral*=((datos[n-1][0] - datos[0][0]))/(2*(n-1));

    std::cout << "IT = " << integral << '\n';
    return integral;
}
