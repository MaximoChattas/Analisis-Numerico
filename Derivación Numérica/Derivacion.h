//
// Created by Maximo Chattas on 28/09/2022.
//

#ifndef MÉTODOS_DERIVACION_H
#define MÉTODOS_DERIVACION_H

#define Puntos 8
#define h 0.1

void ingresoDatosDerivacion (double** datos);
double Progresiva2Puntos(double** datos , int indice);
double Regresiva2Puntos(double** datos , int indice);
double Centrada2Puntos(double** datos , int indice);
void derivacion2Puntos(double** datos);

#endif //MÉTODOS_DERIVACION_H
