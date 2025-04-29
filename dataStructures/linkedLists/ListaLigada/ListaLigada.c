//
// Created by nava on 22/04/25.
//
#include "ListaLigada.h"

// variáveis
struct no *inicio = NULL;
struct no *novo = NULL;
struct no *anterior = NULL;
struct no *proximo = NULL;
struct no *aux = NULL;
struct no *cursor = NULL;

// funções
void inicializar()
{
    inicio = NULL;
    cursor = NULL;
}

void finalizar(struct no *quem)
{
    if (inicio == NULL)
    {
        return;
    }
    if (quem->proximo != NULL)
    {
        finalizar(quem->proximo);
    }
    printf("Excluindo %d...\n", quem->dado);
    free(quem);
}

struct no *novoNo(int dado)
{
    struct no *p = malloc(sizeof(struct no));
    if (!p)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }

    p->dado = dado;
    p->proximo = NULL;
    p->anterior = NULL;

    return p;
}

void adicionar(int dado)
{
    novo = novoNo(dado);

    if (inicio == NULL)
    {
        inicio = novo;
    }
    else
    {
        if (novo->dado < inicio->dado)
        {
            adicionarNoInicio();
        }
        else
        {
            aux = inicio;
            anterior = inicio;
            while (aux->dado < novo->dado &&
                   aux->proximo != NULL)
            {
                anterior = aux;
                aux = aux->proximo;
            }
            if (novo->dado > aux->dado)
            {
                adicionarNoFinal();
            }
            else
            {
                adicionarNoMeio();
            }
        }
    }
}

void adicionarNoInicio()
{
    novo->proximo = inicio;
    if (inicio != NULL)
    {
        inicio->anterior = novo;
    }

    novo->anterior = NULL;
    inicio = novo;
}

void adicionarNoFinal()
{
    aux->proximo = novo;
    novo->anterior = aux;
    novo->proximo = NULL;
}

void adicionarNoMeio()
{
    novo->proximo = aux;
    anterior->proximo = novo;
    aux->anterior = novo;
    anterior->proximo = novo;
}

void excluir(int dado)
{
    if (inicio == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        if (dado == inicio->dado)
        {
            excluirNoInicio();
        }
        else
        {
            aux = inicio;
            anterior = inicio;
            while (aux->dado != dado &&
                   aux->proximo != NULL)
            {
                anterior = aux;
                aux = aux->proximo;
            }
            if (aux->dado == dado)
            {
                if (aux->proximo == NULL)
                {
                    excluirNoFinal();
                }
                else
                {
                    excluirNoMeio();
                }
            }
            else
            {
                printf("Nao encontrado!\n");
            }
        }
    }
}

void excluirNoInicio()
{
    if (inicio->proximo == NULL)
    {
        free(inicio);
        inicio = NULL;
    }
    else
    {
        aux = inicio;
        inicio = inicio->proximo;
        inicio->anterior = NULL;
        free(aux);
    }
}

void excluirNoFinal()
{
    anterior->proximo = NULL;
    free(aux);
}

void excluirNoMeio()
{
    anterior->proximo = aux->proximo;
    if (aux->proximo != NULL)
    {
        aux->proximo->anterior = anterior;
    }
    free(aux);
}

void paraInicio()
{
    cursor = inicio;
}

void paraOAnterior()
{
    if (cursor != NULL && cursor->anterior != NULL)
    {
        cursor = cursor->anterior;
    }
}

void paraOProximo()
{
    if (cursor != NULL)
    {
        cursor = cursor->proximo;
    }
}

struct no *noAtual()
{
    return cursor;
}
