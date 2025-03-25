//
// Created by nava on 11/03/25.
//

#ifndef FILASIMPLES_H
#define FILASIMPLES_H

#include <stdbool.h>

// Constantes
enum {
    FSTAMANHO = 5
};

// Variáveis
extern int fsFila[FSTAMANHO];
extern int fsInicio;
extern int fsFim;

// Protótipos
bool fsEstaVazia();
bool fsEstaCheia();
bool fsAdicionar(int valor);
bool fsRetirar(int *valor);

#endif //FILASIMPLES_H
