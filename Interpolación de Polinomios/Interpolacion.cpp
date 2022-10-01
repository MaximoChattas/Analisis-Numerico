//
// Created by Maximo Chattas on 21/09/2022.
//

#include <iostream>
#include <cmath>
#include "Interpolacion.h"
#include "../funcionesMatriz.h"

#define Puntos 4

void ingresoDatosAjusteCurvas(double **datos)
{
    for (int i = 0 ; i < Puntos ; i++)
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

double a0(double** datos)
{
    return datos[Puntos][1]/Puntos - a1(datos) * datos[Puntos][0]/Puntos;

}

double a1(double** datos)
{
    return ((Puntos*datos[Puntos][3] - datos[Puntos][0]*datos[Puntos][1])/(Puntos*datos[Puntos][2] - pow(datos[Puntos][0] , 2)));
}

void modeloLineal()
{
    double** datos = crearMatriz(Puntos+1 , 4);
    ingresoDatosAjusteCurvas(datos);

    //Poner en 0 Fila final de sumatoria
    for(int i = 0 ; i < 4 ; i++)
    {
        datos[Puntos][i] = 0;
    }

    for (int i = 0 ; i < Puntos ; i++)
    {
        datos[i][2] = pow(datos[i][0] , 2); //Columna X^2
        datos[i][3] = datos[i][0] * datos[i][1]; //Columna X*Y

        //Fila Sumatoria
        datos[Puntos][0] += datos[i][0];
        datos[Puntos][1] += datos[i][1];
        datos[Puntos][2] += datos[i][2];
        datos[Puntos][3] += datos[i][3];
    }

    std::cout << "\n\n";
    std::cout << "x\t\ty\t\tx^2\t\txy\n";
    mostrarMatriz(datos , Puntos+1 , 4);

    std::cout << "\n\n" << "y = " << a1(datos) << "x + " << a0(datos);
}

void modeloExponencial()
{
    double** datos = crearMatriz(Puntos+1 , 4);
    ingresoDatosAjusteCurvas(datos);

    //Poner en 0 Fila final de sumatoria
    for(int i = 0 ; i < 4 ; i++)
    {
        datos[Puntos][i] = 0;
    }

    for (int i = 0 ; i < Puntos ; i++)
    {
        datos[i][1] = log(datos[i][1]);
        datos[i][2] = pow(datos[i][0] , 2);
        datos[i][3] = datos[i][0] * datos[i][1];

        //Fila Sumatoria
        datos[Puntos][0] += datos[i][0];
        datos[Puntos][1] += datos[i][1];
        datos[Puntos][2] += datos[i][2];
        datos[Puntos][3] += datos[i][3];
    }

    double A0 = a0(datos);
    double A1 = a1(datos);

    std::cout << "\n\n";
    std::cout << "x\t\ty\t\tx^2\t\txy\n";
    mostrarMatriz(datos , Puntos+1 , 4);

    std::cout << "\n\n";
    std::cout << "a0 = " << A0 << '\n';
    std::cout << "a1 = " << A1 << '\n';
    std::cout << '\n';
    std::cout << "y = " << exp(A0) << "e^" << A1 << "x\n";
}

void modeloPotencial()
{
    double** datos = crearMatriz(Puntos+1 , 4);
    ingresoDatosAjusteCurvas(datos);

    //Poner en 0 Fila sumatoria
    for(int i = 0 ; i < 4 ; i++)
    {
        datos[Puntos][i] = 0;
    }

    for (int i = 0 ; i < Puntos ; i++)
    {
        datos[i][0] = log10(datos[i][0]);
        datos[i][1] = log10(datos[i][1]);
        datos[i][2] = pow(datos[i][0] , 2);
        datos[i][3] = datos[i][0] * datos[i][1];

        //Fila Sumatoria
        datos[Puntos][0] += datos[i][0];
        datos[Puntos][1] += datos[i][1];
        datos[Puntos][2] += datos[i][2];
        datos[Puntos][3] += datos[i][3];
    }

    double A0 = a0(datos);
    double A1 = a1(datos);


    std::cout << "\n\n";
    std::cout << "x\t\ty\t\tx^2\t\txy\n";
    mostrarMatriz(datos , Puntos+1 , 4);

    std::cout << "\n\n";
    std::cout << "a0 = " << A0 << '\n';
    std::cout << "a1 = " << A1 << '\n';
    std::cout << '\n';
    std::cout << "y = " << pow(10 , A0) << "x^" << A1 << "\n";
}

void modeloCrecimiento()
{
    double** datos = crearMatriz(Puntos+1 , 4);
    ingresoDatosAjusteCurvas(datos);

    //Poner en 0 Fila sumatoria
    for(int i = 0 ; i < 4 ; i++)
    {
        datos[Puntos][i] = 0;
    }

    for (int i = 0 ; i < Puntos ; i++)
    {
        datos[i][0] = 1/datos[i][0];
        datos[i][1] = 1/datos[i][1];
        datos[i][2] = pow(datos[i][0] , 2);
        datos[i][3] = datos[i][0] * datos[i][1];

        //Fila Sumatoria
        datos[Puntos][0] += datos[i][0];
        datos[Puntos][1] += datos[i][1];
        datos[Puntos][2] += datos[i][2];
        datos[Puntos][3] += datos[i][3];
    }

    double A0 = a0(datos);
    double A1 = a1(datos);

    std::cout << "\n\n";
    std::cout << "x\t\ty\t\tx^2\t\txy\n";
    mostrarMatriz(datos , Puntos+1 , 4);

    std::cout << "\n\n";
    std::cout << "a0 = " << A0 << '\n';
    std::cout << "a1 = " << A1 << '\n';
    std::cout << '\n';
    std::cout << "y = " << 1/A0 << "*x/(" << A1/A0 << " + x)\n";
}

void polinomioNewton()
{
    double **datos = crearMatriz(Puntos , 2);
    double **diferencias = crearMatriz(Puntos-1 , Puntos-1);
    ingresoDatosAjusteCurvas(datos);

    for (int j = 0 ; j < Puntos-1 ; j++)
    {
        for (int i = 0 ; i < Puntos-1-j ; i++)
        {
            if(j>0) //Primera columna toma datos f(x)
            {
                diferencias[i][j] = (diferencias[i+1][j-1] - diferencias[i][j-1])/(datos[i+j+1][0] - datos[i][0]);
            }

            else
            {
                diferencias[i][j] = (datos[i+1][1]-datos[i][1])/(datos[i+1][0] - datos[i][0]);
            }
        }
    }

    std::cout << "X\t\tY\n";
    mostrarMatriz(datos , Puntos , 2);
    std::cout << "\n\nDiferencias:\n";
    mostrarMatriz(diferencias , Puntos-1 , Puntos-1);

    std::cout << "f(x) = " << datos[0][1];

    for(int i = 0 ; i < Puntos-1 ; i++)
    {
        std::cout << " + ";
        std::cout << diferencias[0][i];
        for (int j = 0 ; j < i+1 ; j++)
        {
            std::cout << "(x - " << datos[j][0] << ")";
        }
    }
}

void polinomioLagrange()
{
    double **datos = crearMatriz(Puntos , 2);
    ingresoDatosAjusteCurvas(datos);

    mostrarMatriz(datos , Puntos , 2);
    std::cout << "\n\n";

    for(int i = 0 ; i < Puntos ; i++)
    {
        double denominador = 1;
        for (int j = 0 ; j < Puntos ; j++)
        {
            if (j != i)
            {
                denominador *= (datos[i][0] - datos[j][0]);
                std::cout << "(x - " << datos[j][0] << ")";
            }
        }
        std::cout << '(' << datos[i][1]/denominador << ')';

        if (i != Puntos-1)
        {
            std::cout << " + ";
        }
    }
}

void trazadoraCubica()
{
    double* x = crearArray(Puntos);
    double* y = crearArray(Puntos);
    double* h = crearArray(Puntos-1);
    double* a = crearArray(Puntos-1);
    double* l = crearArray(Puntos);
    double* m = crearArray(Puntos-1);
    double* z = crearArray(Puntos);
    double* c = crearArray(Puntos);
    double* b = crearArray(Puntos);
    double* d = crearArray(Puntos);

    a[0] = 0;


    for (int i = 0 ; i < Puntos ; i++)
    {
        std::cout << "x" << i << ' ';
        std::cin >> x[i];

        std::cout << "y" << i << ' ';
        std::cin >> y[i];
    }

    //Paso 1: Vector h(Paso de intervalo)
    for (int i = 0 ; i < Puntos-1 ; i++)
    {
        h[i] = x[i + 1] - x[i];
    }

    //Paso 2: vector a
    for (int i = 1 ; i < Puntos-1 ; i++)
    {
        a[i] = 3/h[i]*(y[i+1] - y[i]) - 3/h[i-1]*(y[i] - y[i-1]);
    }

    //Paso 3:
    l[0] = 1;
    m[0] = 0;
    z[0] = 0;

    //Paso 4:
    for(int i = 1 ; i < Puntos-1 ; i++)
    {
        l[i] = 2*(x[i+1] - x[i-1]) - h[i-1]*m[i-1];
        m[i] = h[i]/l[i];
        z[i] = (a[i] - h[i-1]*z[i-1])/l[i];
    }

    //Paso 5:
    l[Puntos-1] = 1;
    z[Puntos-1] = 0;
    c[Puntos-1] = 0;

    //Paso 6:
    for(int i = Puntos-2 ; i >= 0 ; i--)
    {
        c[i] = z[i] - m[i]*c[i+1];
        b[i] = (a[i+1] - a[i])/h[i] - (h[i]*(c[i+1] + 2*c[i]))/3;
        d[i] = (c[i+1]-c[i])/(3*h[i]);
    }

}
