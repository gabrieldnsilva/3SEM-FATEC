#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
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
    limparBuffer(); // Funciona como um "flush" no buffer

    if (buscarPessoa(lista, novaPessoa.cpf) != NULL) // Interage com a função de buscar importada de lista.h
    {
        printf("CPF já cadastrado!\n");
        return;
    }

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
    char cpf[12];
    char buffer[200];

    printf("CPF a ser alterado: ");
    lerString(cpf, sizeof(cpf));

    Pessoa *pessoaExistente = buscarPessoa(lista, cpf);

    if (pessoaExistente == NULL)
    {
        printf("CPF não cadastrado!\n");
        return;
    }

    Pessoa pessoaAtualizada = *pessoaExistente;

    printf("Nome atual: %s\n", pessoaExistente->nome);
    printf("Novo nome ([ENTER] para manter): ");
    lerString(buffer, sizeof(buffer));
    if (strlen(buffer) > 0)
    {
        strcpy(pessoaAtualizada.nome, buffer);
    }

    printf("Endereço atual: %s\n", pessoaExistente->endereco);
    printf("Novo endereço ([ENTER] para manter): ");
    lerString(buffer, sizeof(buffer));
    if (strlen(buffer) > 0)
    {
        strcpy(pessoaAtualizada.endereco, buffer);
    }

    printf("Telefone atual: %s\n", pessoaExistente->telefone);
    printf("Novo telefone ([ENTER] para manter): ");
    lerString(buffer, sizeof(buffer));
    if (strlen(buffer) > 0)
    {
        strcpy(pessoaAtualizada.telefone, buffer);
    }

    printf("Email atual: %s\n", pessoaExistente->email);
    printf("Novo email ([ENTER] para manter): ");
    lerString(buffer, sizeof(buffer));
    if (strlen(buffer) > 0)
    {
        strcpy(pessoaAtualizada.email, buffer);
    }

    if (alterarPessoa(lista, cpf, pessoaAtualizada)) // Interage com a função de alterar importada de lista.h
    {
        printf("Registro alterado com sucesso!\n");
    }
    else
    {
        printf("Erro ao alterar registro!\n");
    }
}

void imprimirRegistro(Lista *lista)
{
    char cpf[12];

    printf("CPF da pessoa a ser impressa: ");
    lerString(cpf, 12);

    Pessoa *pessoa = buscarPessoa(lista, cpf);

    if (pessoa == NULL)
    {
        printf("CPF não cadastrado!\n");
        return;
    }

    printf("\nDados da pessoa:\n");
    imprimirPessoa(*pessoa);
}
