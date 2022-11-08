//
// Created by Maximo Chattas on 07/11/2022.
//

#include "../Funciones Matriz/funcionesMatriz.h"
#include "EcuacionesDiferenciales.h"
#include <iostream>
#include <cmath>

double f(double x , double y)
{
    return exp(0.8 * x) - 0.5*y;
}

void euler()
{
    double x0 , y0 , h;

    std::cout << "x0 = ";
    std::cin >> x0;
    std::cout << "y(" << x0 << ") = ";
    std::cin >> y0;
    std::cout << "h = ";
    std::cin >> h;

    double **datos = crearMatriz(cantPuntos , 2);

    //Condiciones iniciales
    datos[0][0] = x0;
    datos[0][1] = y0;

    for (int i = 1 ; i < cantPuntos ; i++)
    {
        datos[i][0] = datos[i-1][0]+h;
        datos[i][1] = datos[i-1][1] + f(datos[i-1][0] , datos[i-1][1])*h;
    }

    std::cout << "\n\n";
    std::cout << "x\t\ty\n";
    mostrarMatriz(datos , cantPuntos , 2);
}

void heun()
{
    double x0 , y0 , h;

    std::cout << "x0 = ";
    std::cin >> x0;
    std::cout << "y(" << x0 << ") = ";
    std::cin >> y0;
    std::cout << "h = ";
    std::cin >> h;

    double **datos = crearMatriz(cantPuntos , 2);

    //Condiciones iniciales
    datos[0][0] = x0;
    datos[0][1] = y0;

    for (int i = 1 ; i < cantPuntos ; i++)
    {
        double ypredictora , pendienteInicial , pendienteFinal , pendiente;
        datos[i][0] = datos[i-1][0]+h;

        ypredictora = datos[i-1][1] + f(datos[i-1][0] , datos[i-1][1])*h;
        pendienteFinal = f(datos[i][0] , ypredictora);
        pendienteInicial = f(datos[i-1][0] , datos[i-1][1]);

        pendiente = (pendienteFinal + pendienteInicial)/2;

        datos[i][1] = datos[i-1][1] + pendiente*h;
    }

    std::cout << "\n\n";
    std::cout << "x\t\ty\n";
    mostrarMatriz(datos , cantPuntos , 2);
}

void rungeKutta2()
{
    double x0 , y0 , h;

    std::cout << "x0 = ";
    std::cin >> x0;
    std::cout << "y(" << x0 << ") = ";
    std::cin >> y0;
    std::cout << "h = ";
    std::cin >> h;

    double **datos = crearMatriz(cantPuntos , 2);

    //Condiciones iniciales
    datos[0][0] = x0;
    datos[0][1] = y0;

    for (int i = 1 ; i < cantPuntos ; i++)
    {
        double K1 , K2 , pendiente;
        datos[i][0] = datos[i-1][0]+h;

        K1 = f(datos[i-1][0] , datos[i-1][1]);
        K2 = f(datos[i][0] , datos[i-1][1] + h*K1);

        pendiente = K1/2 + K2/2;
        datos[i][1] = datos[i-1][1] + pendiente*h;
    }

    std::cout << "\n\n";
    std::cout << "x\t\ty\n";
    mostrarMatriz(datos , cantPuntos , 2);
}

void rungeKutta3()
{
    double x0 , y0 , h;

    std::cout << "x0 = ";
    std::cin >> x0;
    std::cout << "y(" << x0 << ") = ";
    std::cin >> y0;
    std::cout << "h = ";
    std::cin >> h;

    double **datos = crearMatriz(cantPuntos , 2);

    //Condiciones iniciales
    datos[0][0] = x0;
    datos[0][1] = y0;

    for (int i = 1 ; i < cantPuntos ; i++)
    {
        double K1 , K2 , K3 , pendiente;
        datos[i][0] = datos[i-1][0]+h;

        K1 = f(datos[i-1][0] , datos[i-1][1]);
        K2 = f(datos[i-1][0] + h/2 , datos[i-1][1] + h*K1/2);
        K3 = f(datos[i][0] , datos[i-1][1] - h*K1 + 2*h*K2);

        pendiente = (K1 + 4*K2 + K3)/6;
        datos[i][1] = datos[i-1][1] + pendiente*h;
    }

    std::cout << "\n\n";
    std::cout << "x\t\ty\n";
    mostrarMatriz(datos , cantPuntos , 2);
}

void rungeKutta4()
{
    double x0 , y0 , h;

    std::cout << "x0 = ";
    std::cin >> x0;
    std::cout << "y(" << x0 << ") = ";
    std::cin >> y0;
    std::cout << "h = ";
    std::cin >> h;

    double **datos = crearMatriz(cantPuntos , 2);

    //Condiciones iniciales
    datos[0][0] = x0;
    datos[0][1] = y0;

    for (int i = 1 ; i < cantPuntos ; i++)
    {
        double K1 , K2 , K3 , K4 , pendiente;
        datos[i][0] = datos[i-1][0]+h;

        K1 = f(datos[i-1][0] , datos[i-1][1]);
        K2 = f(datos[i-1][0] + h/2 , datos[i-1][1] + h*K1/2);
        K3 = f(datos[i-1][0] + h/2 , datos[i-1][1] + h*K2/2);
        K4 = f(datos[i][0] , datos[i-1][1] + h*K3);

        pendiente = (K1 + 2*K2 + 2*K3 + K4)/6;
        datos[i][1] = datos[i-1][1] + pendiente*h;
    }

    std::cout << "\n\n";
    std::cout << "x\t\ty\n";
    mostrarMatriz(datos , cantPuntos , 2);
}
