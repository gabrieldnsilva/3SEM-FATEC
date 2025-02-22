//
// Created by nava on 11/02/25.
//

#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

// Constantes
enum
{
    TAMANHO = 5,
};

// Estruturas
typedef struct Pilha
{
    int topo;
    char elementos[TAMANHO];

} Pilha;

// Protótipos
void inicializarPilha(Pilha *pilha);
bool pilhaVazia(Pilha *pilha);
bool pilhaCheia(Pilha *pilha);
bool push(Pilha *pilha, char elemento);
bool pop(Pilha *pilha, char *elemento);

#endif // PILHA_H
