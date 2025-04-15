#ifdef LISTA_H
#define LISTA_H

typedef struct
{
    char nome[100];
    char endereco[200];
    char cpf[12]; // 11 dígitos + '\0'
    char telefone[20];
    char email[100];
} Pessoa;

typedef struct Node
{
    Pessoa pessoa;
    struct Node *proximo;
} Node;

typedef struct
{
    Node *inicio;
    int tamanho;
} Lista;