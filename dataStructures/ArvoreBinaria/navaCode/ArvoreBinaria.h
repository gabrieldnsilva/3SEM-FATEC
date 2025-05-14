//
// Created by nava on 13/05/25.
//

#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <stdio.h>
#include <stdlib.h>

// Estruturas
struct no
{
    struct no *esquerda;
    int dado;
    struct no *direita;
};

// Variáveis
extern struct no *inicio;

// Protótipos
struct no *novoNo(int dado);
void adicionar(struct no *quem, struct no *aonde);
struct no *buscar(int valor, struct no *raiz);
void preOrdem(struct no *raiz);
void emOrdem(struct no *raiz);
void posOrdem(struct no *raiz);
struct no *minimo(struct no *raiz);
struct no *remover(int valor, struct no *raiz);
void finalizar(struct no *aonde);

// Funções adicionais para análise da árvore
int altura(struct no *raiz);
int contarNos(struct no *raiz);
int ehBST(struct no *raiz, int min, int max);
void imprimirArvore(struct no *raiz, int nivel);

#endif // ARVOREBINARIA_H
