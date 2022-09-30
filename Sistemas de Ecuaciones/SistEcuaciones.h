//
// Created by Maximo Chattas on 09/09/2022.
//

#ifndef METODOS_SISTECUACIONES_H
#define METODOS_SISTECUACIONES_H

void ingresoDatosSistEcuaciones(double **A, double *B);

void mostrarEcuaciones(double **A, double *B);

void verifCero(double **A, double *B);

void triangularLlenar(double **A , double **L);

void triangular(double **A, double *B);

void sustitucionAtras(double **A , const double *B , double *x);

void sustitucionAdelante(double **A , const double *B , double *x);

void eliminacionGaussiana();

void gaussSeidel();

void LU();

#endif //METODOS_SISTECUACIONES_H
