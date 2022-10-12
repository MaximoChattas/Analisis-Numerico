//
// Created by Maximo Chattas on 09/09/2022.
//

#include <iostream>
#include <cmath>
#include "SistEcuaciones.h"
#include "../funcionesMatriz.h"

#define DIMENSION 3
#define TOLERANCIA pow(10 , -4)

void ingresoDatosSistEcuaciones(double** A , double* B)
{
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        std::cout << "Ecuacion " << i+1 << '\n';
        for (int j = 0 ; j < DIMENSION ; j++)
        {
            std::cout << "Coeficiente " << j+1 << ' ';
            std::cin >> A[i][j];
        }

        std::cout << "T Independiente " << i+1 << ' ';
        std::cin >> B[i];
    }
}

void mostrarEcuaciones(double** A , double* B)
{
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        for (int j = 0 ; j < DIMENSION ; j++)
        {
            std::cout << "+ " << A[i][j] << " x" << j+1 << ' ';
        }

        std::cout << " = " << B[i] << '\n';
    }
}

void verifCero(double** A , double* B)
{
    bool verificador;
    int contador = 0;
    do
    {
        verificador = true;
        for (int i = 0 ; i < DIMENSION ; i++) //Verificar 0 en Diag. Principal
        {
            if (A[i][i] == 0)
            {
                contador++;
                verificador = false;
                if (i + 1 < DIMENSION) //Verificar si la fila siguiente esta dentro de rango
                {
                    for (int j = 0 ; j < DIMENSION ; j++)
                    {
                        double aux = A[i][j];
                        A[i][j] = A[i+1][j];
                        A[i+1][j] = aux;
                    }
                    double aux = B[i];
                    B[i] = B[i+1];
                    B[i+1] = aux;
                }

                else if (i - 1 < DIMENSION)
                {
                    for (int j = 0 ; j < DIMENSION ; j++)
                    {
                        double aux = A[i][j];
                        A[i][j] = A[i-1][j];
                        A[i-1][j] = aux;
                    }
                    double aux = B[i];
                    B[i] = B[i-1];
                    B[i-1] = aux;
                }

                else
                {
                    throw std::invalid_argument("La matriz no puede ser triangularizada\n");
                }
            }
        }

        if (contador > DIMENSION)
        {
            throw std::invalid_argument("La matriz no puede ser triangularizada\n");
        }
    } while (!verificador);
}

void triangularLlenar(double **A , double **L) //Metodo LU
{
    for (int i = 1 ; i < DIMENSION ; i++)
    {
        for (int j = i ; j < DIMENSION ; j++)
        {
            double modificador = A[j][i-1]/A[i-1][i-1];

            for (int k = 0 ; k < DIMENSION ; k++)
            {
                A[j][k] = A[j][k] - modificador*A[i-1][k];
            }

            L[j][i-1] = modificador; //Llenado de modificadores en matriz L
        }
    }
}

void triangular(double** A , double* B)
{
    verifCero(A , B);
    for (int i = 1 ; i < DIMENSION ; i++)
    {
        for (int j = i ; j < DIMENSION ; j++)
        {
            double modificador = A[j][i-1]/A[i-1][i-1];

            for (int k = 0 ; k < DIMENSION ; k++)
            {
                A[j][k] = A[j][k] - modificador*A[i-1][k];
            }
            B[j] = B[j] - modificador*B[i-1];
        }
    }
}

void sustitucionAtras(double **A, const double *B, double *x)
{
    for (int i = DIMENSION-1 ; i >= 0 ; i--)
    {
        x[i] = B[i];
        for (int j = i+1 ; j < DIMENSION ; j++)
        {
            x[i] -= A[i][j]*x[j];
        }

        x[i] /= A[i][i];
    }
}

void sustitucionAdelante(double **A, const double *B, double *x)
{
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        x[i] = B[i];
        for (int j = 0 ; j < i ; j++)
        {
            x[i] -= A[i][j]*x[j];
        }

        x[i] /= A[i][i];
    }
}

void eliminacionGaussiana()
{
    //Matrices para Sistemas de Ecuaciones
    double** A = crearMatriz(DIMENSION , DIMENSION);
    double* B = crearArray(DIMENSION);
    double* x = crearArray(DIMENSION);

    ingresoDatosSistEcuaciones(A , B);
    triangular(A , B);

    sustitucionAtras(A , B , x);

    //Mostrar Resultados
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        std::cout << "X" << i+1 << "= " << x[i] << '\n';
    }
}

void gaussSeidel()
{
    //Matrices para Sistemas de Ecuaciones
    double** A = crearMatriz(DIMENSION , DIMENSION);
    double* B = crearArray(DIMENSION);
    double* x = crearArray(DIMENSION);

    ingresoDatosSistEcuaciones(A , B);

    double ERROR[DIMENSION];
    bool verificador = false;

    verifCero(A , B);


    //Inicializar en 0 las variables
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        x[i] = 0;
        ERROR[i] = 0;
    }

    //Encabezado de Tabla
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        std::cout << "x" << i+1 << "\t\tE" << i+1 << "\t\t";
    }
    std::cout << '\n';

    while (!verificador)
    {
        //Mostrar Datos
        for (int i = 0 ; i < DIMENSION ; i++)
        {
            std::cout << x[i] << '\t' << ERROR[i] << '\t';
        }
        std::cout << '\n';

        for (int i = 0 ; i < DIMENSION ; i++)
        {
            ERROR[i] = x[i];

            //Calculo de nuevo valor de xi
            x[i] = B[i];

            for (int j = 0 ; j < DIMENSION ; j++)
            {
                if (j != i)
                {
                    x[i] -= A[i][j]*x[j];
                }
            }
            x[i] /= A[i][i];

            //Nuevo Error
            ERROR[i] = abs(x[i] - ERROR[i]);
        }

        verificador = true;
        for (int i = 0 ; i < DIMENSION ; i++)
        {
            if (ERROR[i] >= TOLERANCIA)
            {
                verificador = false;
            }
        }

    }
}

void LU()
{
    //Matrices para Sistemas de Ecuaciones
    double** A = crearMatriz(DIMENSION , DIMENSION);
    double* B = crearArray(DIMENSION);
    double* x = crearArray(DIMENSION);
    ingresoDatosSistEcuaciones(A , B);

    double **L = crearMatriz(DIMENSION , DIMENSION);
    double **U = crearMatriz(DIMENSION , DIMENSION);
    double *y = crearArray(DIMENSION);

    verifCero(A , B);

    //Llenado Matriz L (Diagonal Principal y Triangulo superior) y Copia de Matriz A verificada en Matriz U
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        for (int j = 0 ; j < DIMENSION ; j++)
        {
            if (j>i)
            {
                L[i][j] = 0;
            }
            else if (j==i)
            {
                L[i][j] = 1;
            }

            U[i][j] = A[i][j];
        }
    }

    //Matriz U es Matriz A triangulada
    //Llenado de modificadores en matriz L
    triangularLlenar(U, L);

    //Mostrar Matriz L
    std::cout << "MATRIZ L:\n";
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        for (int j = 0 ; j < DIMENSION ; j++)
        {
            std::cout << L[i][j] << '\t';
        }
        std::cout << '\n';
    }

    //Mostrar Matriz U
    std::cout << "\n\nMATRIZ U:\n";
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        for (int j = 0 ; j < DIMENSION ; j++)
        {
            std::cout << U[i][j] << '\t';
        }
        std::cout << '\n';
    }

    sustitucionAdelante(L , B , y);

    std::cout << "\n\n";

    //Mostrar Vector Y
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        std::cout << "y" << i+1 << " = " << y[i] << '\n';
    }

    sustitucionAtras(U , y , x);

    std::cout << "\n\n";

    //Mostrar Vector X
    for (int i = 0 ; i < DIMENSION ; i++)
    {
        std::cout << "x" << i+1 << " = " << x[i] << '\n';
    }
}
