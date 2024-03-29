//
// Created by Maximo Chattas on 07/11/2022.
//

#include "../Funciones Matriz/funcionesMatriz.h"
#include "EcuacionesDiferenciales.h"
#include <iostream>
#include <cmath>

double f(double x , double y)
{
    return cos(x + y);
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

    double **datos = crearMatriz(cantPuntos , 3);

    //Condiciones iniciales
    datos[0][0] = x0;
    datos[0][1] = y0;
    datos[0][2] = y0;

    for (int i = 0 ; i < cantPuntos-1 ; i++)
    {
        double ypredictora , pendienteInicial , pendienteFinal , pendiente;
        datos[i+1][0] = datos[i][0]+h;

        ypredictora = datos[i][2] + f(datos[i][0] , datos[i][2])*h;
        pendienteInicial = f(datos[i][0] , datos[i][2]);
        pendienteFinal = f(datos[i+1][0] , ypredictora);

        pendiente = (pendienteFinal + pendienteInicial)/2;

        datos[i][1] = ypredictora;
        datos[i+1][2] = datos[i][2] + pendiente*h;
    }

    datos[cantPuntos-1][1] = datos[cantPuntos-1][2] + f(datos[cantPuntos-1][0] , datos[cantPuntos-1][2])*h;

    std::cout << "\n\n";
    std::cout << "x\t\ty pred\ty\n";
    mostrarMatriz(datos , cantPuntos , 3);
}

void rungeKutta2()
{
    std::cout << "Metodo Runge-Kutta 2do Orden\n\n";
    double x0 , y0 , h;

    x0 = 0;
    y0 = M_PI;
    h = 0.1;
    std::cout << "x0 = " << x0 << '\n';
//    std::cin >> x0;
    std::cout << "y(" << x0 << ") = " << y0 << '\n';
//    std::cin >> y0;
    std::cout << "h = " << h << '\n';
//    std::cin >> h;

    double **datos = crearMatriz(cantPuntos , 4);

    //Condiciones iniciales
    datos[0][0] = x0;
    datos[0][1] = y0;

    for (int i = 0 ; i < cantPuntos-1 ; i++)
    {
        double K1 , K2 , pendiente;
        datos[i+1][0] = datos[i][0]+h;

        K1 = f(datos[i][0] , datos[i][1]);
        K2 = f(datos[i+1][0] , datos[i][1] + h*K1);

        pendiente = K1/2 + K2/2;
        datos[i+1][1] = datos[i][1] + pendiente*h;
        datos[i][2] = K1;
        datos[i][3] = K2;
    }

    //K1 y K2 finales
    datos[cantPuntos-1][2] = f(datos[cantPuntos-1][0] , datos[cantPuntos-1][1]);
    datos[cantPuntos-1][3] = f(datos[cantPuntos-1][0] + h , datos[cantPuntos-1][1] + h*datos[cantPuntos-1][2]);

    std::cout << "\n\n";
    std::cout << "x\t\ty\t\t\tK1\t\tK2\n";
    mostrarMatriz(datos , cantPuntos , 4);
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

    double **datos = crearMatriz(cantPuntos , 6);

    //Condiciones iniciales
    datos[0][0] = x0;
    datos[0][1] = y0;

    for (int i = 0 ; i < cantPuntos-1 ; i++)
    {
        double K1 , K2 , K3 , K4 , pendiente;
        datos[i+1][0] = datos[i][0]+h;

        K1 = f(datos[i][0] , datos[i][1]);
        K2 = f(datos[i][0] + h/2 , datos[i][1] + h*K1/2);
        K3 = f(datos[i][0] + h/2 , datos[i][1] + h*K2/2);
        K4 = f(datos[i+1][0] , datos[i][1] + h*K3);

        pendiente = (K1 + 2*K2 + 2*K3 + K4)/6;
        datos[i+1][1] = datos[i][1] + pendiente*h;
        datos[i][2] = K1;
        datos[i][3] = K2;
        datos[i][4] = K3;
        datos[i][5] = K4;
    }

    datos[cantPuntos-1][2] = f(datos[cantPuntos-1][0] , datos[cantPuntos-1][1]);
    datos[cantPuntos-1][3] = f(datos[cantPuntos-1][0] + h/2 , datos[cantPuntos-1][1] + h*datos[cantPuntos-1][2]/2);
    datos[cantPuntos-1][4] = f(datos[cantPuntos-1][0] + h/2 , datos[cantPuntos-1][1] + h*datos[cantPuntos-1][3]/2);
    datos[cantPuntos-1][5] = f(datos[cantPuntos-1][0] + h , datos[cantPuntos-1][1] + h*datos[cantPuntos-1][4]);

    std::cout << "\n\n";
    std::cout << "x\t\ty\t\tK1\t\tK2\t\tK3\t\tK4\n";
    mostrarMatriz(datos , cantPuntos , 6);
}
