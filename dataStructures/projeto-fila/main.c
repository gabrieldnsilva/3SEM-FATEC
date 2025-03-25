#include <stdio.h>
#include "FilaSimples.h"
#include "senha.h"

// Constantes
enum
{
    OP_NAO_SELECIONADA = 0,
    OP_GERAR_SENHA,
    OP_ATENDER,
    OP_SAIR
};

// Protótipos
int menu();

int main(void)
{
    int opcao = OP_NAO_SELECIONADA;
    Senha senha;
    int tipoEscolhido;
    int prioritario;

    srand(time(NULL));

    while (opcao != OP_SAIR)
    {
        opcao = menu();
        switch (opcao)
        {
        case OP_GERAR_SENHA:

            printf("Escolha o tipo de atendimento:\n");
            printf("1 - Clínico Geral (%s)\n", TIPO_CLINICO_GERAL);
            printf("2 - Pediatria (%s)\n", TIPO_PEDIATRIA);
            printf("3 - Preferencial (%s)\n", TIPO_PREFERENCIAL);
            scanf("%d", &tipoEscolhido);

            printf("É prioritário? (1 - Sim, 0 - Não): ");
            scanf("%d", &prioritario);

            if (tipoEscolhido >= 1 && tipoEscolhido <= NUM_TIPOS)
            {
                senha = gerarSenha(contadores[tipoEscolhido - 1].tipo, prioritario);
                if (!fsAdicionar(senha))
                {
                    printf("Fila cheia!\n");
                }
                else
                {
                    printf("Senha gerada: ");
                    imprimirSenha(senha);
                    fsImprimir();
                }
            }
            else
            {
                printf("Tipo de atendimento inválido!\n");
            }
            break;
        case OP_ATENDER:
            if (fsRetirar(&senha))
            {
                printf("Chamando senha: ");
                imprimirSenha(senha);
            }
            else
            {
                printf("Fila vazia!\n");
            }

            fsImprimir();

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
    printf("==== SISTEMA DE SENHAS - CLÍNICA MÉDICA ====\n");
    printf("%d - Retirar Senha\n", OP_GERAR_SENHA);
    printf("%d - Atender\n", OP_ATENDER);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite a sua opcao: ");
    scanf("%d", &op);
    return op;
}
