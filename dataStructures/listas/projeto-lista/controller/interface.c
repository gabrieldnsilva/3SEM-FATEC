#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void lerString(char *buffer, int tamanho)
{
    fgets(buffer, tamanho, stdin);
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }
}

void adicionarRegistro(Lista *lista)
{
    Pessoa novaPessoa;

    printf("CPF (apenas números): ");
    lerString(novaPessoa.cpf, sizeof(novaPessoa.cpf));

    // Fazer a validação do CPF aqui

    printf("Nome: ");
    lerString(novaPessoa.nome, sizeof(novaPessoa.nome));

    printf("Endereço: ");
    lerString(novaPessoa.endereco, sizeof(novaPessoa.endereco));

    printf("Telefone: ");
    lerString(novaPessoa.telefone, sizeof(novaPessoa.telefone));

    printf("Email: ");
    lerString(novaPessoa.email, sizeof(novaPessoa.email));

    if (adicionarPessoa(lista, novaPessoa)) // Interage com a função de adicionar de listas.h
    {
        printf("Pessoa adicionada com sucesso!\n");
    }
    else
    {
        printf("Erro ao adicionar pessoa!\n");
    }
}

void excluirRegistro(Lista *lista)
{
    char cpf[12];

    printf("CPF a ser excluído (apenas números): ");
    lerString(cpf, sizeof(cpf));

    if (excluirPessoa(lista, cpf)) // Interage com a função de excluir importada de lista.h
    {
        printf("Pessoa excluída com sucesso!\n");
    }
    else
    {
        printf("Erro ao excluir pessoa!\n");
    }
}

void alterarRegistro(Lista *lista)
{
    // Implementar aqui
}

void imprimirRegistro(Lista *lista)
{
    // Implementar aqui
}
