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

void destruirLista(Lista *lista)
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
}

int tamanhoLista(Lista *lista)
{
    if (lista == NULL)
        return 0;
    return lista->tamanho;
}

int estaVazia(Lista *lista)
{
    return (lista == NULL || lista->inicio == NULL);
}

int adicionarPessoa(Lista *lista, Pessoa pessoa) // Sem verificação de CPF
{
    if (lista == NULL)
        return 0;

    if (buscarPessoa(lista, pessoa.cpf) != NULL)
    {
        return 0; // CPF já existe
    }

    Node *novoNode = (Node *)malloc(sizeof(Node));
    if (novoNode == NULL)
        return 0;

    novoNode->pessoa = pessoa;
    novoNode->proximo = lista->inicio;
    lista->inicio = novoNode;
    lista->tamanho++;

    return 1;
}

int excluirPessoa(Lista *lista, const char *cpf)
{
    if (estaVazia(lista))
        return 0;

    Node *atual = lista->inicio;
    Node *anterior = NULL;

    while (atual != NULL && strcmp(atual->pessoa.cpf, cpf) != 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
        return 0; // CPF não encontrado

    if (anterior == NULL)
    {
        // Remover o primeiro nó
        lista->inicio = atual->proximo;
    }
    else
    {
        // Remover um nó do meio ou do final
        anterior->proximo = atual->proximo;
    }

    free(atual);
    lista->tamanho--;

    return 1;
}

int alterarPessoa(Lista *lista, const char *cpf, Pessoa novaPessoa)
{

    if (estaVazia(lista))
        return 0;

    Node *atual = lista->inicio;

    while (atual != NULL && strcmp(atual->pessoa.cpf, cpf) != 0)
    {
        atual = atual->proximo;
    }
    if (atual == NULL)
        return 0; // Em caso de CPF não encontrado

    strcpy(atual->pessoa.nome, novaPessoa.nome);
    strcpy(atual->pessoa.endereco, novaPessoa.endereco);
    strcpy(atual->pessoa.telefone, novaPessoa.telefone);
    strcpy(atual->pessoa.email, novaPessoa.email);

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

void imprimirTodos(Lista *lista)
{
    if (estaVazia(lista))
    {
        printf("Lista vazia!\n");
        return;
    }

    Node *atual = lista->inicio;
    int contador = 1;

    while (atual != NULL)
    {
        printf("Pessoa %d:\n", contador++);
        imprimirPessoa(atual->pessoa);
        atual = atual->proximo;
    }
}