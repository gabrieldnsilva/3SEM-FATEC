#include <stdio.h>
#include "FilaSimples.h"

// Constantes
enum
{
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_ATENDER,
    OP_SAIR
};

// Protótipos
int menu();
void fsImprimir();

int main(void)
{
    int opcao = OP_NAO_SELECIONADA;
    int numero = 0;

    while (opcao != OP_SAIR)
    {
        opcao = menu();
        switch (opcao)
        {
        case OP_ADICIONAR:
            printf("Digite um numero: ");
            scanf("%d", &numero);
            if (!fsAdicionar(numero))
            {
                printf("Fila cheia!\n");
            }
            break;
        case OP_ATENDER:
            if (fsRetirar(&numero))
            {
                printf("%d retirado da fila.\n", numero);
            }
            else
            {
                printf("Fila vazia!\n");
            }
            break;
        case OP_SAIR:
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }
    return 0;
}

int menu()
{
    int op = OP_NAO_SELECIONADA;
    printf("Menu\n");
    printf("%d - Retirar Senha\n", OP_ADICIONAR);
    printf("%d - Atender\n", OP_ATENDER);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite a sua opcao: ");
    scanf("%d", &op);
    return op;
}

void fsImprimir()
{
    if (fsEstaVazia())
    {
        printf("Fila vazia!\n");
    }
    else
    {
        printf("+---+-----+\n");
        for (int i = fsInicio; i < fsFim; i++)
        {
            printf("| %1d | %3d |\n", i, fsFila[i]);
            printf("+---+-----+\n");
        }
    }
}
