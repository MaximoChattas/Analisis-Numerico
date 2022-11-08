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
#include "Integración Numérica/Integracion.h"
#include "Ecuaciones Diferenciales/EcuacionesDiferenciales.h"

/*Encontrar raices de funciones:
 * Modificar f , g , df
 */

int main()
{
    std::cout << std::fixed << std::setprecision(4);

    rungeKutta2();
    return 0;
}