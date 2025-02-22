//
// Created by nava on 11/02/25.
//
#include "Pilha.h"

// Variáveis
int pilha[TAMANHO];
int posicao = 0;

// Funções

void inicializarPilha(Pilha *pilha)
{
    pilha->topo = -1;
}

bool pilhaVazia(Pilha *pilha)
{
    return pilha->topo == -1;
}

bool pilhaCheia(Pilha *pilha)
{
    return pilha->topo == TAMANHO - 1;
}

bool push(Pilha *pilha, char elemento)
{
    if (pilhaCheia(pilha))
    {
        return false;
    }
    pilha->elementos[++pilha->topo] = elemento;
    return true;
}

bool pop(Pilha *pilha, char *elemento)
{

    if (pilhaVazia(pilha))
    {
        return false;
    }
    *elemento = pilha->elementos[pilha->topo--];
    return true;
}
