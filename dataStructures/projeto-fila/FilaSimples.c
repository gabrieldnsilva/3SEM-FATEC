//
// Created by nava on 11/03/25.
//
#include "FilaSimples.h"

// Variáveis
int fsFila[FSTAMANHO];
int fsInicio = 0;
int fsFim = 0;

// Funções
bool fsEstaVazia() {
    return fsInicio == fsFim;
    // if (fsInicio == fsFim) {
    //     return true;
    // } else {
    //     return false;
    // }
}

bool fsEstaCheia() {
    return fsFim == FSTAMANHO;
}

bool fsAdicionar(int valor) {
    if (fsEstaCheia()) {
        return false;
    }
    fsFila[fsFim] = valor;
    fsFim++;
    return true;
}

bool fsRetirar(int *valor) {
    if (fsEstaVazia()) {
        return false;
    }
    *valor = fsFila[fsInicio];
    fsInicio++;
    return true;
}
