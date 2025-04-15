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

void imprimirPessoa(Pessoa pesssoa)
{
    printf("Nome: %d\n", pesssoa.nome);
    printf("Endereço: %d\n", pesssoa.endereco);
    printf("CPF: %d\n", pesssoa.cpf);
    printf("Telefone: %d\n", pesssoa.telefone);
    printf("Email: %d\n", pesssoa.email);
    printf("------------------------\n");
}