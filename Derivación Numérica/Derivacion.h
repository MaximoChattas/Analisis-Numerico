//
// Created by Maximo Chattas on 28/09/2022.
//

#ifndef MÉTODOS_DERIVACION_H
#define MÉTODOS_DERIVACION_H

#define h 0.1

double f0(double x);

void ingresoDatosDerivacionAutomatico(double **datos);

double Progresiva2Puntos(double **datos, int indice);

double Regresiva2Puntos(double **datos, int indice);

double Centrada2Puntos(double **datos, int indice);

void derivacion2Puntos();

double Progresiva3Puntos(double **datos, int indice);

double Regresiva3Puntos(double **datos, int indice);

double Centrada3Puntos(double **datos, int indice);

void derivacion3Puntos();

double Progresiva5Puntos(double **datos, int indice);

double Regresiva5Puntos(double **datos, int indice);

double Centrada5Puntos(double **datos, int indice);

void derivacion5Puntos();


#endif //MÉTODOS_DERIVACION_H
