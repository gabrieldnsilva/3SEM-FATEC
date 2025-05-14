#include <stdio.h>
#include <limits.h>
#include "ArvoreBinaria.h"

// Constantes
enum
{
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_BUSCAR,
    OP_REMOVER,
    OP_PERCURSO_PRE_ORDEM,
    OP_PERCURSO_EM_ORDEM,
    OP_PERCURSO_POS_ORDEM,
    OP_IMPRIMIR_ARVORE,
    OP_ALTURA_ARVORE,
    OP_CONTAR_NOS,
    OP_VERIFICAR_BST,
    OP_SAIR
};

// Protótipos
int menu();
void pausar();

int main(void)
{
    int opcao = OP_NAO_SELECIONADA;
    int numero;
    struct no *resultado;

    printf("=== ÁRVORE BINÁRIA DE BUSCA - DEMONSTRAÇÃO ===\n\n");
    printf("Bem-vindo ao programa demonstrativo de árvores binárias!\n");
    printf("Este programa permite criar e manipular uma árvore binária de busca.\n\n");

    while (opcao != OP_SAIR)
    {
        opcao = menu();
        switch (opcao)
        {
        case OP_ADICIONAR:
            printf("\n== ADICIONAR NÓ ==\n");
            printf("Digite um número: ");
            scanf("%d", &numero);
            adicionar(novoNo(numero), inicio);
            printf("Número %d adicionado com sucesso!\n", numero);
            pausar();
            break;

        case OP_BUSCAR:
            printf("\n== BUSCAR VALOR ==\n");
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &numero);
            resultado = buscar(numero, inicio);
            if (resultado != NULL)
            {
                printf("Valor %d encontrado na árvore!\n", numero);
            }
            else
            {
                printf("Valor %d não encontrado na árvore.\n");
            }
            pausar();
            break;

        case OP_REMOVER:
            printf("\n== REMOVER NÓ ==\n");
            printf("Digite o valor a ser removido: ");
            scanf("%d", &numero);
            inicio = remover(numero, inicio);
            printf("Operação de remoção concluída.\n");
            pausar();
            break;

        case OP_PERCURSO_PRE_ORDEM:
            printf("\n== PERCURSO PRÉ-ORDEM ==\n");
            printf("Visitando: Raiz -> Esquerda -> Direita\n");
            printf("Resultado: ");
            if (inicio != NULL)
            {
                preOrdem(inicio);
                printf("\n");
            }
            else
            {
                printf("Árvore vazia.\n");
            }
            pausar();
            break;

        case OP_PERCURSO_EM_ORDEM:
            printf("\n== PERCURSO EM ORDEM ==\n");
            printf("Visitando: Esquerda -> Raiz -> Direita\n");
            printf("Resultado (ordenado em BST): ");
            if (inicio != NULL)
            {
                emOrdem(inicio);
                printf("\n");
            }
            else
            {
                printf("Árvore vazia.\n");
            }
            pausar();
            break;

        case OP_PERCURSO_POS_ORDEM:
            printf("\n== PERCURSO PÓS-ORDEM ==\n");
            printf("Visitando: Esquerda -> Direita -> Raiz\n");
            printf("Resultado: ");
            if (inicio != NULL)
            {
                posOrdem(inicio);
                printf("\n");
            }
            else
            {
                printf("Árvore vazia.\n");
            }
            pausar();
            break;

        case OP_IMPRIMIR_ARVORE:
            printf("\n== VISUALIZAÇÃO DA ÁRVORE ==\n");
            if (inicio != NULL)
            {
                printf("Estrutura da árvore (rotacionada 90 graus):\n");
                imprimirArvore(inicio, 0);
                printf("\n");
            }
            else
            {
                printf("Árvore vazia.\n");
            }
            pausar();
            break;

        case OP_ALTURA_ARVORE:
            printf("\n== ALTURA DA ÁRVORE ==\n");
            if (inicio != NULL)
            {
                printf("A altura da árvore é: %d\n", altura(inicio));
                printf("(Uma árvore com apenas raiz tem altura 1)\n");
            }
            else
            {
                printf("Árvore vazia (altura 0).\n");
            }
            pausar();
            break;

        case OP_CONTAR_NOS:
            printf("\n== CONTAGEM DE NÓS ==\n");
            printf("Total de nós na árvore: %d\n", contarNos(inicio));
            pausar();
            break;

        case OP_VERIFICAR_BST:
            printf("\n== VERIFICAÇÃO DE BST ==\n");
            if (inicio == NULL)
            {
                printf("Árvore vazia é considerada uma BST válida.\n");
            }
            else if (ehBST(inicio, INT_MIN, INT_MAX))
            {
                printf("A árvore é uma BST válida!\n");
            }
            else
            {
                printf("A árvore NÃO é uma BST válida.\n");
            }
            pausar();
            break;

        case OP_SAIR:
            printf("\nFinalizando o programa...\n");
            printf("Liberando memória da árvore...\n");
            break;

        default:
            printf("\nOpção inválida! Tente novamente.\n");
            pausar();
        }
    }

    finalizar(inicio);
    printf("\nPrograma finalizado. Obrigado por utilizar!\n");
    return 0;
}

int menu()
{
    int op = OP_NAO_SELECIONADA;

    printf("\n===== MENU DE OPÇÕES =====\n");
    printf("[%d] Adicionar valor\n", OP_ADICIONAR);
    printf("[%d] Buscar valor\n", OP_BUSCAR);
    printf("[%d] Remover valor\n", OP_REMOVER);
    printf("[%d] Percurso Pré-ordem\n", OP_PERCURSO_PRE_ORDEM);
    printf("[%d] Percurso Em-ordem\n", OP_PERCURSO_EM_ORDEM);
    printf("[%d] Percurso Pós-ordem\n", OP_PERCURSO_POS_ORDEM);
    printf("[%d] Visualizar árvore\n", OP_IMPRIMIR_ARVORE);
    printf("[%d] Calcular altura da árvore\n", OP_ALTURA_ARVORE);
    printf("[%d] Contar nós da árvore\n", OP_CONTAR_NOS);
    printf("[%d] Verificar se é BST\n", OP_VERIFICAR_BST);
    printf("[%d] Sair\n", OP_SAIR);
    printf("==========================\n");
    printf("Digite sua opção: ");
    scanf("%d", &op);

    return op;
}

void pausar()
{
    printf("\nPressione ENTER para continuar...");
    getchar(); // Limpar o buffer
    getchar(); // Esperar ENTER
}