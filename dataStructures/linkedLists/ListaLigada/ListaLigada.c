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
    novo->anterior = anterior; // Fixed: set the anterior pointer correctly
    anterior->proximo = novo;
    aux->anterior = novo;
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

// Nova função para testar a dupla ligação (em ambas as direções)
void verificarIntegridade()
{
    if (inicio == NULL)
    {
        printf("Lista vazia - íntegra por definição.\n");
        return;
    }

    // Verifica se a ligação para frente funciona
    printf("Verificando integridade (frente->trás): ");
    struct no *atual = inicio;
    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        if (atual->proximo != NULL && atual->proximo->anterior != atual)
        {
            printf("\nERRO: Ponteiro 'anterior' inconsistente no nó %d!\n", atual->proximo->dado);
            return;
        }
        atual = atual->proximo;
    }
    printf("OK!\n");

    // Verifica se a ligação para trás funciona
    printf("Verificando integridade (trás->frente): ");
    atual = inicio;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        if (atual->anterior != NULL && atual->anterior->proximo != atual)
        {
            printf("\nERRO: Ponteiro 'proximo' inconsistente no nó %d!\n", atual->anterior->dado);
            return;
        }
        atual = atual->anterior;
    }
    printf("OK!\n");
}
