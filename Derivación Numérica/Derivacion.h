//
// Created by Maximo Chattas on 28/09/2022.
//

#ifndef MÉTODOS_DERIVACION_H
#define MÉTODOS_DERIVACION_H

#define n 8
#define h 0.1

double f0(double x);

void ingresoDatosDerivacionManual(double **datos);

void ingresoDatosDerivacionAutomatico(double **datos);

double Progresiva2Puntos(double **datos, int indice);

double Regresiva2Puntos(double **datos, int indice);

double Centrada2Puntos(double **datos, int indice);

void derivacion2Puntos();

double Progresiva3Puntos(double **datos, int indice);

double Regresiva3Puntos(double **datos, int indice);

double Centrada3Puntos(double **datos, int indice);

void derivacion3Puntos();


#endif //MÉTODOS_DERIVACION_H
