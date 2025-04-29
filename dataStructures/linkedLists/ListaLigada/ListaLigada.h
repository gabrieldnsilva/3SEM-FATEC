//
// Created by nava on 22/04/25.
//

#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include <stdio.h>
#include <stdlib.h>

// Estrutura
struct no
{
    int dado;
    struct no *proximo;
    struct no *anterior;
};

// Variáveis
extern struct no *inicio;
extern struct no *novo;
extern struct no *proximo;
extern struct no *anterior;
extern struct no *aux;

// Protótipos
void inicializar();
void finalizar(struct no *quem);
struct no *novoNo(int dado);
void adicionar(int dado);
void adicionarNoInicio();
void adicionarNoFinal();
void adicionarNoMeio();
void excluir(int dado);
void excluirNoInicio();
void excluirNoFinal();
void excluirNoMeio();
void verificarIntegridade(); // Nova função

void paraInicio();
void paraOProximo();
void paraOAnterior();
struct no *noAtual();

#endif // LISTALIGADA_H
