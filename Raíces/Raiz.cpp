//
// Created by Maximo Chattas on 23/08/2022.
//

#include <iostream>
#include <cmath>
#include "Raiz.h"

#define Tolerancia pow(10 , -3)

double f(double x)
{
    //INSERTAR SINGULARIDADES DE FUNCION
    if(false)
    {
        throw std::invalid_argument("ERROR\n");
    }
    //INSERTAR FUNCIÓN AQUÍ
    return -23.33 + 79.35 * x - 88.09 * pow(x,2) + 41.6 * pow(x,3) - 8.68 * pow(x,4) + 0.658 * pow(x , 5);
}

double g(double x)
{
//    INSERTAR FUNCION g(x) AQUÍ (Punto Fijo)
    return sqrt((1.75*x + 2.627)/0.874);
}

double df(double x)
{
//    INSERTAR DERIVADA DE f(x) AQUÍ
    return -1.748 * x + 1.75;
}

void scan (double a , double b)
{
    int particiones = 10;

    std::cout << "x\t\tf(x)\n";

    for (int i = 0 ; i <= particiones ; i++)
    {
        double x = a+i*(b-a)/(particiones);
        std::cout << x << '\t' << f(x) << '\n';
    }
}

double biseccion(double a, double b)
{
    std::cout << "Metodo Biseccion\n\n";

    double auxA = a;
    double auxB = b;
    double c = (auxA+auxB)/2;
    double prev;

    std::cout << "A\t\tC\t\tB\t\tf(A)\tf(B)\tf(C)\t|E|\n";

    for (int i = 0 ; i < 100 ; i++) //Maxima cantidad de iteraciones
    {
        //Calculo de Error
        prev = c;
        c = (auxA+auxB)/2;
        double error = abs(c - prev);

        std::cout << auxA << '\t' << c << '\t' << auxB << '\t' << f(auxA) << '\t' << f(auxB) << '\t'
                  << f(c) << '\t' << error << '\n';

        //Achicar el intervalo
        if (f(auxA)*f(c) < 0)
        {
            auxB = c;
        }
        else if (f(auxB)*f(c) < 0)
        {
            auxA = c;
        }
        else
        {
            throw std::invalid_argument("No hay raices reales en el intervalo seleccionado\n");
        }

        if (f(c) == 0 || (i > 0 && error < Tolerancia))
        {
            return c;
        }
    }

    throw std::invalid_argument("Error de Convergencia");
}

double puntoFijo(double xi)
{
    std::cout << "Metodo Punto Fijo\n\n";

    std::cout << "xi\t\tg(xi)\t|E|\n";

    double error = 0;

    for (int i = 0 ; i < 100 ; i++)
    {
        double prev = xi;
        xi = g(xi);

        std::cout << prev << '\t' << xi << '\t' << error << '\n';

        error = abs(xi - prev);

        if (f(xi) == 0 || (i > 0 && error < Tolerancia))
        {
            std::cout << xi << "\t\t\t" << error << '\n';
            return xi;
        }
    }

    throw std::invalid_argument("Error de Convergencia");
}

double newtonRaphson(double xi) {

    std::cout << "Metodo Newton Raphson\n\n";

    std::cout << "xi\t\tf(xi)\t|E|\n";

    double error = 0;

    for (int i = 0 ; i < 100 ; i++)
    {
        std::cout << xi << '\t' << f(xi) << '\t' << error << '\n';

        double prev = xi;
        xi = xi - f(xi)/df(xi);
        error = abs(prev - xi);

        if (f(xi) == 0 || (i > 0 && error < Tolerancia))
        {
            std::cout << xi << "\t\t\t" << error << '\n';
            return xi;
        }
    }

    throw std::invalid_argument("Error de Convergencia");
}

double secante(double x0, double x1)
{
    std::cout << "Metodo Secante\n\n";

    std::cout << "xi\t\tf(xi)\t|E|\n";

    double error = 0;

    std::cout << x0 << '\t' << f(x0) << '\t' << error << '\n';

    for (int i = 0 ; i < 100 ; i++)
    {
        std::cout << x1 << '\t' << f(x1) << '\t' << error << '\n';

        double aux = x1;
        x1 = x1 - (f(x1)*(x0 - x1))/(f(x0) - f(x1));
        x0 = aux;
        error = abs(x0 - x1);

        if (f(x1) == 0 || (i > 0 && error < Tolerancia))
        {
            std::cout << x1 << "\t\t\t" << error << '\n';
            return x1;
        }
    }

    throw std::invalid_argument("Error de Convergencia");
}

