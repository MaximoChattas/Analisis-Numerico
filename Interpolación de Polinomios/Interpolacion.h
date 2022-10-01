//
// Created by Maximo Chattas on 21/09/2022.
//

#ifndef MÉTODOS_INTERPOLACION_H
#define MÉTODOS_INTERPOLACION_H

void ingresoDatosAjusteCurvas(double **datos);

double a0(double **datos);

double a1(double **datos);

void modeloLineal();

void modeloExponencial();

void modeloPotencial();

void modeloCrecimiento();

void polinomioNewton();

void polinomioLagrange();

void trazadoraCubica();

#endif //MÉTODOS_INTERPOLACION_H
