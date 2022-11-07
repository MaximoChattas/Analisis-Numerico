//
// Created by Maximo Chattas on 21/09/2022.
//

#include <iostream>
#include <cmath>
#include "Interpolacion.h"
#include "../funcionesMatriz.h"

double a0(double** datos)
{
    return datos[cantPuntos][1]/cantPuntos - a1(datos) * datos[cantPuntos][0]/cantPuntos;
}

double a1(double** datos)
{
    return ((cantPuntos*datos[cantPuntos][3] - datos[cantPuntos][0]*datos[cantPuntos][1])/(cantPuntos*datos[cantPuntos][2] - pow(datos[cantPuntos][0] , 2)));
}

void modeloLineal()
{
    double** datos = crearMatriz(cantPuntos+1 , 4);
    ingresoDatos(datos);

    //Poner en 0 Fila final de sumatoria
    for(int i = 0 ; i < 4 ; i++)
    {
        datos[cantPuntos][i] = 0;
    }

    for (int i = 0 ; i < cantPuntos ; i++)
    {
        datos[i][2] = pow(datos[i][0] , 2); //Columna X^2
        datos[i][3] = datos[i][0] * datos[i][1]; //Columna X*Y

        //Fila Sumatoria
        datos[cantPuntos][0] += datos[i][0];
        datos[cantPuntos][1] += datos[i][1];
        datos[cantPuntos][2] += datos[i][2];
        datos[cantPuntos][3] += datos[i][3];
    }

    std::cout << "\n\n";
    std::cout << "x\t\ty\t\tx^2\t\txy\n";
    mostrarMatriz(datos , cantPuntos+1 , 4);

    std::cout << "\n\n" << "y = " << a1(datos) << "x + " << a0(datos);
}

void modeloExponencial()
{
    double** datos = crearMatriz(cantPuntos+1 , 4);
    ingresoDatos(datos);

    //Poner en 0 Fila final de sumatoria
    for(int i = 0 ; i < 4 ; i++)
    {
        datos[cantPuntos][i] = 0;
    }

    for (int i = 0 ; i < cantPuntos ; i++)
    {
        datos[i][1] = log(datos[i][1]);
        datos[i][2] = pow(datos[i][0] , 2);
        datos[i][3] = datos[i][0] * datos[i][1];

        //Fila Sumatoria
        datos[cantPuntos][0] += datos[i][0];
        datos[cantPuntos][1] += datos[i][1];
        datos[cantPuntos][2] += datos[i][2];
        datos[cantPuntos][3] += datos[i][3];
    }

    double A0 = a0(datos);
    double A1 = a1(datos);

    std::cout << "\n\n";
    std::cout << "x\t\ty\t\tx^2\t\txy\n";
    mostrarMatriz(datos , cantPuntos+1 , 4);

    std::cout << "\n\n";
    std::cout << "a0 = " << A0 << '\n';
    std::cout << "a1 = " << A1 << '\n';
    std::cout << '\n';
    std::cout << "y = " << exp(A0) << "e^" << A1 << "x\n";
}

void modeloPotencial()
{
    double** datos = crearMatriz(cantPuntos+1 , 4);
    ingresoDatos(datos);

    //Poner en 0 Fila sumatoria
    for(int i = 0 ; i < 4 ; i++)
    {
        datos[cantPuntos][i] = 0;
    }

    for (int i = 0 ; i < cantPuntos ; i++)
    {
        datos[i][0] = log10(datos[i][0]);
        datos[i][1] = log10(datos[i][1]);
        datos[i][2] = pow(datos[i][0] , 2);
        datos[i][3] = datos[i][0] * datos[i][1];

        //Fila Sumatoria
        datos[cantPuntos][0] += datos[i][0];
        datos[cantPuntos][1] += datos[i][1];
        datos[cantPuntos][2] += datos[i][2];
        datos[cantPuntos][3] += datos[i][3];
    }

    double A0 = a0(datos);
    double A1 = a1(datos);


    std::cout << "\n\n";
    std::cout << "x\t\ty\t\tx^2\t\txy\n";
    mostrarMatriz(datos , cantPuntos+1 , 4);

    std::cout << "\n\n";
    std::cout << "a0 = " << A0 << '\n';
    std::cout << "a1 = " << A1 << '\n';
    std::cout << '\n';
    std::cout << "y = " << pow(10 , A0) << "x^" << A1 << "\n";
}

void modeloCrecimiento()
{
    double** datos = crearMatriz(cantPuntos+1 , 4);
    ingresoDatos(datos);

    //Poner en 0 Fila sumatoria
    for(int i = 0 ; i < 4 ; i++)
    {
        datos[cantPuntos][i] = 0;
    }

    for (int i = 0 ; i < cantPuntos ; i++)
    {
        datos[i][0] = 1/datos[i][0];
        datos[i][1] = 1/datos[i][1];
        datos[i][2] = pow(datos[i][0] , 2);
        datos[i][3] = datos[i][0] * datos[i][1];

        //Fila Sumatoria
        datos[cantPuntos][0] += datos[i][0];
        datos[cantPuntos][1] += datos[i][1];
        datos[cantPuntos][2] += datos[i][2];
        datos[cantPuntos][3] += datos[i][3];
    }

    double A0 = a0(datos);
    double A1 = a1(datos);

    std::cout << "\n\n";
    std::cout << "x\t\ty\t\tx^2\t\txy\n";
    mostrarMatriz(datos , cantPuntos+1 , 4);

    std::cout << "\n\n";
    std::cout << "a0 = " << A0 << '\n';
    std::cout << "a1 = " << A1 << '\n';
    std::cout << '\n';
    std::cout << "y = " << 1/A0 << "*x/(" << A1/A0 << " + x)\n";
}

void polinomioNewton()
{
    double **datos = crearMatriz(cantPuntos , 2);
    double **diferencias = crearMatriz(cantPuntos-1 , cantPuntos-1);
    ingresoDatos(datos);

    for (int j = 0 ; j < cantPuntos-1 ; j++)
    {
        for (int i = 0 ; i < cantPuntos-1-j ; i++)
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
    mostrarMatriz(datos , cantPuntos , 2);
    std::cout << "\n\nDiferencias:\n";
    mostrarMatriz(diferencias , cantPuntos-1 , cantPuntos-1);

    std::cout << "f(x) = " << datos[0][1];

    for(int i = 0 ; i < cantPuntos-1 ; i++)
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
    double **datos = crearMatriz(cantPuntos , 2);
    ingresoDatos(datos);

    mostrarMatriz(datos , cantPuntos , 2);
    std::cout << "\n\n";

    for(int i = 0 ; i < cantPuntos ; i++)
    {
        double denominador = 1;
        for (int j = 0 ; j < cantPuntos ; j++)
        {
            if (j != i)
            {
                denominador *= (datos[i][0] - datos[j][0]);
                std::cout << "(x - " << datos[j][0] << ")";
            }
        }
        std::cout << '(' << datos[i][1]/denominador << ')';

        if (i != cantPuntos-1)
        {
            std::cout << " + ";
        }
    }
}

void trazadoraCubicaNatural()
{
    double **datos = crearMatriz(cantPuntos , 2);
    double* h = crearArray(cantPuntos-1);
    double* a = crearArray(cantPuntos-1);
    double* l = crearArray(cantPuntos);
    double* m = crearArray(cantPuntos-1);
    double* z = crearArray(cantPuntos);
    double* c = crearArray(cantPuntos);
    double* b = crearArray(cantPuntos);
    double* d = crearArray(cantPuntos);


    ingresoDatos(datos);

    std::cout << "\nPaso 1:\n";
    for (int i = 0 ; i < cantPuntos-1 ; i++)
    {
        h[i] = datos[i + 1][0] - datos[i][0];
        std::cout << "h[" << i << "] = " << h[i] << '\n';
    }

    std::cout << "\nPaso 2:\n";
    for (int i = 1 ; i < cantPuntos-1 ; i++)
    {
        a[i] = 3/h[i]*(datos[i+1][1] - datos[i][1]) - 3/h[i-1]*(datos[i][1] - datos[i-1][1]);
        std::cout << "a[" << i << "] = " << a[i] << '\n';
    }

    std::cout << "\nPaso 3:\n";
    l[0] = 1;
    std::cout << "l[" << 0 << "] = " << l[0] << '\n';

    m[0] = 0;
    std::cout << "m[" << 0 << "] = " << m[0] << '\n';

    z[0] = 0;
    std::cout << "z[" << 0 << "] = " << z[0] << '\n';

    std::cout << "\nPaso 4:\n";
    for(int i = 1 ; i < cantPuntos-1 ; i++)
    {
        l[i] = 2*(datos[i+1][0] - datos[i-1][0]) - h[i-1]*m[i-1];
        std::cout << "l[" << i << "] = " << l[i] << '\n';

        m[i] = h[i]/l[i];
        std::cout << "m[" << i << "] = " << m[i] << '\n';

        z[i] = (a[i] - h[i-1]*z[i-1])/l[i];
        std::cout << "z[" << i << "] = " << z[i] << '\n';
    }

    std::cout << "\nPaso 5:\n";
    l[cantPuntos-1] = 1;
    std::cout << "l[" << cantPuntos-1 << "] = " << l[cantPuntos-1] << '\n';

    z[cantPuntos-1] = 0;
    std::cout << "z[" << cantPuntos-1 << "] = " << z[cantPuntos-1] << '\n';

    c[cantPuntos-1] = 0;
    std::cout << "c[" << cantPuntos-1 << "] = " << c[cantPuntos-1] << '\n';

    std::cout << "\nPaso 6:\n";
    for(int i = cantPuntos-2 ; i >= 0 ; i--)
    {
        c[i] = z[i] - m[i]*c[i+1];
        std::cout << "c[" << i << "] = " << c[i] << '\n';

        b[i] = (datos[i+1][1] - datos[i][1])/h[i] - (h[i]*(c[i+1] + 2*c[i]))/3;
        std::cout << "b[" << i << "] = " << b[i] << '\n';

        d[i] = (c[i+1]-c[i])/(3*h[i]);
        std::cout << "d[" << i << "] = " << d[i] << '\n';
    }

    std::cout << "\n\n";

    //Paso 7:
    for (int i = 0 ; i < cantPuntos-1 ; i++)
    {
        std::cout << "S" << i << "(x) = " << datos[i][1] << " + " << b[i] << "(x - " << datos[i][0] << ") + " <<
        c[i] << "(x - " << datos[i][0] << ")^2 + " << d[i] << "(x - " << datos[i][0] << ")^3\n";
    }
}

void trazadoraCubicaCondicionada()
{
    double **datos = crearMatriz(cantPuntos , 2);
    double* h = crearArray(cantPuntos-1);
    double* a = crearArray(cantPuntos);
    double* l = crearArray(cantPuntos);
    double* m = crearArray(cantPuntos-1);
    double* z = crearArray(cantPuntos);
    double* c = crearArray(cantPuntos);
    double* b = crearArray(cantPuntos);
    double* d = crearArray(cantPuntos);
    double fp0 , fpn;

    ingresoDatos(datos);

    std::cout << "Ingrese el valor de la primera derivada en X0\n";
    std::cin >> fp0;

    std::cout << "Ingrese el valor de la primera derivada en Xn\n";
    std::cin >> fpn;

    std::cout << "\nPaso 1:\n";
    for (int i = 0 ; i < cantPuntos-1 ; i++)
    {
        h[i] = datos[i + 1][0] - datos[i][0];
        std::cout << "h[" << i << "] = " << h[i] << '\n';
    }

    std::cout << "\nPaso 2:\n";
    a[0] = 3/h[0]*(datos[1][1] - datos[0][1]) - 3*fp0;
    std::cout << "a[" << 0 << "] = " << a[0] << '\n';

    a[cantPuntos-1] = 3*fpn - 3*(datos[cantPuntos-1][1] - datos[cantPuntos-2][1])/h[cantPuntos-2];
    std::cout << "a[" << cantPuntos-1 << "] = " << a[cantPuntos-1] << '\n';

    std::cout << "\nPaso 3:\n";
    for (int i = 1 ; i < cantPuntos-1 ; i++)
    {
        a[i] = 3/h[i]*(datos[i+1][1] - datos[i][1]) - 3/h[i-1]*(datos[i][1] - datos[i-1][1]);
        std::cout << "a[" << i << "] = " << a[i] << '\n';
    }

    std::cout << "\nPaso 4:\n";
    l[0] = 2*h[0];
    std::cout << "l[" << 0 << "] = " << l[0] << '\n';

    m[0] = 0.5;
    std::cout << "m[" << 0 << "] = " << m[0] << '\n';

    z[0] = a[0]/l[0];
    std::cout << "z[" << 0 << "] = " << z[0] << '\n';

    std::cout << "\nPaso 5:\n";
    for(int i = 1 ; i < cantPuntos-1 ; i++)
    {
        l[i] = 2*(datos[i+1][0] - datos[i-1][0]) - h[i-1]*m[i-1];
        std::cout << "l[" << i << "] = " << l[i] << '\n';

        m[i] = h[i]/l[i];
        std::cout << "m[" << i << "] = " << m[i] << '\n';

        z[i] = (a[i] - h[i-1]*z[i-1])/l[i];
        std::cout << "z[" << i << "] = " << z[i] << '\n';
    }

    std::cout << "\nPaso 6:\n";
    l[cantPuntos-1] = h[cantPuntos-2]*(2 - m[cantPuntos-2]);
    std::cout << "l[" << cantPuntos-1 << "] = " << l[cantPuntos-1] << '\n';

    z[cantPuntos-1] = (a[cantPuntos-1] - h[cantPuntos-2]*z[cantPuntos-2])/l[cantPuntos-1];
    std::cout << "z[" << cantPuntos-1 << "] = " << a[cantPuntos-1] << '\n';

    c[cantPuntos-1] = z[cantPuntos-1];
    std::cout << "c[" << cantPuntos-1 << "] = " << c[cantPuntos-1] << '\n';

    std::cout << "\nPaso 7:\n";
    for(int i = cantPuntos-2 ; i >= 0 ; i--)
    {
        c[i] = z[i] - m[i]*c[i+1];
        std::cout << "c[" << i << "] = " << c[i] << '\n';

        b[i] = (datos[i+1][1] - datos[i][1])/h[i] - (h[i]*(c[i+1] + 2*c[i]))/3;
        std::cout << "b[" << i << "] = " << b[i] << '\n';

        d[i] = (c[i+1]-c[i])/(3*h[i]);
        std::cout << "d[" << i << "] = " << d[i] << '\n';
    }

    std::cout << "\n\n";

    //Paso 8:
    for (int i = 0 ; i < cantPuntos-1 ; i++)
    {
        std::cout << "S" << i << "(x) = " << datos[i][1] << " + " << b[i] << "(x - " << datos[i][0] << ") + " <<
                  c[i] << "(x - " << datos[i][0] << ")^2 + " << d[i] << "(x - " << datos[i][0] << ")^3\n";
    }
}