#include <stdio.h>

#include "ListaLigada.h"

// Constantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_EXCLUIR,
    OP_LISTAR,
    OP_SAIR
};

// Protótipos
int menu();
void listar();

int main(void) {
    int dado;
    int opcao = OP_NAO_SELECIONADA;

    inicializar();

    while (opcao != OP_SAIR) {
        opcao = menu();
        switch (opcao) {
            case OP_ADICIONAR:
                printf("Digite um numero: ");
                scanf("%d", &dado);
                adicionar(dado);
                break;
            case OP_EXCLUIR:
                printf("Digite um numero: ");
                scanf("%d", &dado);
                excluir(dado);
                break;
            case OP_LISTAR:
                listar();
                break;
            case OP_SAIR:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    finalizar(inicio);
    return 0;
}

int menu() {
    int op = OP_NAO_SELECIONADA;
    printf("Menu\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Listar\n", OP_LISTAR);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);
    return op;
}

void listar() {
    if (inicio == NULL) {
        printf("Lista vazia!\n");
    } else {
        paraInicio();
        while (noAtual() != NULL) {
            printf("%d - ", noAtual()->dado);
            paraOProximo();
        }
        printf("\n");
    }
}
