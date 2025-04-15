#ifndef INTERFACE_H
#define INTERFACE_H

#include "lista.h"

// Funções auxiliares para entrada
void limparBuffer();
void lerString(char *str, int tamanho);

// Funções de "controller"
void adicionarRegistro(Lista *lista);
void excluirRegistro(Lista *lista);
void alterarRegistro(Lista *lista);
void imprimirRegistro(Lista *lista);

#endif // INTERFACE_H