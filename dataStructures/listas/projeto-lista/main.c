#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

enum
{
    ADICIONAR = 1,
    // EXCLUIR,
    // ALTERAR,
    // IMPRIMIR_POR_CPF,
    // IMPRIMIR_TODOS,
    // ORDENAR,
    SAIR
};

int main()
{
    Lista *lista = criarLista();
    int opcao;

    do
    {
        printf("\n===== SISTEMA DE CADASTRO =====\n");
        printf("%d - Adicionar\n", ADICIONAR);
        // printf("2 - Excluir\n");
        // printf("3 - Alterar\n");
        // printf("4 - Imprimir por CPF\n");
        // printf("5 - Imprimir Todos\n");
        // printf("6 - Ordenar\n");
        printf("%d - Sair\n", SAIR);
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case ADICIONAR:
            break;
        // case EXCLUIR:
        // case ALTERAR:
        // case IMPRIMIR_POR_CPF:
        // case IMPRIMIR_TODOS:
        // case ORDENAR:
        case SAIR:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    } while (opcao != SAIR);

    return 0;
}
