#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "lista.h"

enum
{
    ADICIONAR = 1,
    EXCLUIR,
    ALTERAR,
    IMPRIMIR_POR_CPF,
    IMPRIMIR_TODOS,
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
        printf("%d - Excluir\n", EXCLUIR);
        printf("%d - Alterar\n", ALTERAR);
        printf("%d - Imprimir por CPF\n", IMPRIMIR_POR_CPF);
        printf("%d - Imprimir Todos\n", IMPRIMIR_TODOS);
        // printf("%d - Ordenar\n", ORDENAR);
        printf("%d - Sair\n", SAIR);
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case ADICIONAR:
            adicionarRegistro(lista);
            break;
        case EXCLUIR:
            excluirRegistro(lista);
            break;
        case ALTERAR:
            alterarRegistro(lista);
            break;

        case IMPRIMIR_POR_CPF:
            imprimirRegistro(lista);
            break;
        case IMPRIMIR_TODOS:
            printf("\n=== Lista de Pessoas ===\n");
            imprimirTodos(lista);
            break;
        // case ORDENAR:
        case SAIR:
            printf("\nSaindo...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    } while (opcao != SAIR);

    destruirLista(lista);
    printf("\nSistema encerrado.");
    return 0;
}
