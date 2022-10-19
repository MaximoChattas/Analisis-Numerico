//
// Created by Maximo Chattas on 23/08/2022.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Raíces/Raiz.h"
#include "Sistemas de Ecuaciones/SistEcuaciones.h"
#include "Interpolación de Polinomios/Interpolacion.h"
#include "Derivación Numérica/Derivacion.h"

/*Encontrar raices de funciones:
 * Modificar f , g , df
 */

int main()
{
    std::cout << std::fixed << std::setprecision(4);


    derivacion3Puntos();

//    scan(0 , 10);
//    newtonRaphson(9.4);
//    secante(9 , 10);


    return 0;
}