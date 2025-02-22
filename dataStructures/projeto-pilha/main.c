#include <stdio.h>
#include <string.h>
#include "Pilha.h"

// Constantes
enum
{
    OP_NAO_SELCIONADA = 0,
    OP_VERIFICAR_BALANCEAMENTO,
    OP_SAIR
};

// Protótipos
int menu();
bool verificarBalanceamento(char *expressao);

int main(void)
{
    int opcao = OP_NAO_SELCIONADA;
    int numero = 0;
    char expressao[100];

    while (opcao != OP_SAIR)
    {
        opcao = menu();
        switch (opcao)
        {
        case OP_VERIFICAR_BALANCEAMENTO:
            printf("Digite a expressao: ");
            scanf("%s", expressao);
            if (verificarBalanceamento(expressao))
            {
                printf("Expressao balanceada\n");
            }
            else
            {
                printf("Expressao nao balanceada\n");
            }
            break;
        case OP_SAIR:
            break;
        default:
            printf("Opcao invalida\n");
        }
    }
    return 0;
}

int menu()
{
    int op = 0;
    printf("Menu:\n");
    printf("%d - Verificar balanceamento\n", OP_VERIFICAR_BALANCEAMENTO);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);
    return op;
}

bool verificarBalanceamento(char *expressao)
{
    Pilha pilha;
    inicializarPilha(&pilha);

    for (int i = 0; i < strlen(expressao); i++)
    {
        if (expressao[i] == '(')
        {
            if (!push(&pilha, '('))
            {
                return false;
            }
        }
        else if (expressao[i] == ')')
        {
            char topo;
            if (!pop(&pilha, &topo))
            {
                return false;
            }
        }
    }

    return pilhaVazia(&pilha);
}
