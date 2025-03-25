//
// Created by nava on 11/03/25.
//

#ifndef FILASIMPLES_H
#define FILASIMPLES_H

#include <stdbool.h>
#include "senha.h"

// Constantes
enum
{
    FSTAMANHO = 5
};

// Variáveis
extern Senha fsFila[FSTAMANHO]; // Struct Senha
extern int fsInicio;
extern int fsFim;

// Protótipos
bool fsEstaVazia();
bool fsEstaCheia();
bool fsAdicionar(Senha senha);
bool fsRetirar(Senha *senha);
void fsImprimir();

#endif // FILASIMPLES_H
