#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
    {
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

/*void destruirLista(Lista *lista)
{
    if (lista == NULL)
        return;

    Node *atual = lista->inicio;
    while (atual != NULL)
    {
        Node *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(lista);
} */

int estaVazia(Lista *lista)
{
    return (lista == NULL || lista->inicio == NULL);
}

int adicionarPessoa(Lista *lista, Pessoa pessoa) // Sem verificação de CPF
{
    if (lista == NULL)
        return 0;

    Node *novoNode = (Node *)malloc(sizeof(Node));
    if (novoNode == NULL)
        return 0;

    novoNode->pessoa = pessoa;
    novoNode->proximo = lista->inicio;
    lista->inicio = novoNode;
    lista->tamanho++;

    return 1;
}

Pessoa *buscarPessoa(Lista *lista, const char *cpf)
{
    if (estaVazia(lista))
        return NULL;

    Node *atual = lista->inicio;

    while (atual != NULL)
    {
        if (strcmp(atual->pessoa.cpf, cpf) == 0)
        {
            return &(atual->pessoa);
        }
        atual = atual->proximo;
    }

    return NULL; // CPF não encontrado
}

void imprimirPessoa(Pessoa pesssoa)
{
    printf("Nome: %s\n", pesssoa.nome);
    printf("Endereço: %s\n", pesssoa.endereco);
    printf("CPF: %s\n", pesssoa.cpf);
    printf("Telefone: %s\n", pesssoa.telefone);
    printf("Email: %s\n", pesssoa.email);
    printf("------------------------\n");
}