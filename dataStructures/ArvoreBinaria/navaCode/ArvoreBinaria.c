//
// Created by nava on 13/05/25.
//

#include "ArvoreBinaria.h"
#include <limits.h>

// Variável global para a raiz da árvore
struct no *inicio = NULL;

/**
 * Cria um novo nó com o valor fornecido
 * @param dado O valor a ser armazenado no nó
 * @return Ponteiro para o novo nó criado
 */
struct no *novoNo(int dado)
{
    // Aloca memória para o novo nó
    struct no *novo = (struct no *)malloc(sizeof(struct no));

    // Verifica se a alocação de memória foi bem-sucedida
    if (novo == NULL)
    {
        printf("Erro: Falha na alocação de memória!\n");
        exit(1);
    }

    // Inicializa os campos do nó
    novo->dado = dado;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

/**
 * Adiciona um nó na árvore binária de busca
 * @param quem Nó a ser adicionado
 * @param aonde Raiz da árvore ou subárvore onde o nó será inserido
 */
void adicionar(struct no *quem, struct no *aonde)
{
    // Se a árvore estiver vazia, o novo nó se torna a raiz
    if (inicio == NULL)
    {
        inicio = quem;
        return;
    }

    // Se o valor for menor que o nó atual, insere na subárvore esquerda
    if (quem->dado < aonde->dado)
    {
        if (aonde->esquerda == NULL)
        {
            aonde->esquerda = quem;
        }
        else
        {
            // Continua a busca na subárvore esquerda
            adicionar(quem, aonde->esquerda);
        }
    }
    // Se o valor for maior ou igual, insere na subárvore direita
    else
    {
        if (aonde->direita == NULL)
        {
            aonde->direita = quem;
        }
        else
        {
            // Continua a busca na subárvore direita
            adicionar(quem, aonde->direita);
        }
    }
}

/**
 * Busca um valor na árvore
 * @param valor Valor a ser buscado
 * @param raiz Raiz da árvore ou subárvore onde a busca será realizada
 * @return Ponteiro para o nó encontrado ou NULL se não encontrar
 */
struct no *buscar(int valor, struct no *raiz)
{
    // Caso base: árvore vazia ou valor encontrado
    if (raiz == NULL || raiz->dado == valor)
    {
        return raiz;
    }

    // Se o valor for menor, busca na subárvore esquerda
    if (valor < raiz->dado)
    {
        return buscar(valor, raiz->esquerda);
    }

    // Se o valor for maior, busca na subárvore direita
    return buscar(valor, raiz->direita);
}

/**
 * Percorre a árvore em pré-ordem (raiz, esquerda, direita)
 * @param raiz Raiz da árvore ou subárvore a ser percorrida
 */
void preOrdem(struct no *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->dado); // Visita o nó raiz
        preOrdem(raiz->esquerda);  // Percorre a subárvore esquerda
        preOrdem(raiz->direita);   // Percorre a subárvore direita
    }
}

/**
 * Percorre a árvore em ordem (esquerda, raiz, direita)
 * @param raiz Raiz da árvore ou subárvore a ser percorrida
 */
void emOrdem(struct no *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esquerda);   // Percorre a subárvore esquerda
        printf("%d ", raiz->dado); // Visita o nó raiz
        emOrdem(raiz->direita);    // Percorre a subárvore direita
    }
}

/**
 * Percorre a árvore em pós-ordem (esquerda, direita, raiz)
 * @param raiz Raiz da árvore ou subárvore a ser percorrida
 */
void posOrdem(struct no *raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->esquerda);  // Percorre a subárvore esquerda
        posOrdem(raiz->direita);   // Percorre a subárvore direita
        printf("%d ", raiz->dado); // Visita o nó raiz
    }
}

/**
 * Encontra o valor mínimo na árvore
 * @param raiz Raiz da árvore ou subárvore
 * @return Ponteiro para o nó com valor mínimo
 */
struct no *minimo(struct no *raiz)
{
    struct no *atual = raiz;

    // Navega até o nó mais à esquerda
    while (atual && atual->esquerda != NULL)
    {
        atual = atual->esquerda;
    }

    return atual;
}

/**
 * Remove um nó com o valor específico da árvore
 * @param valor Valor a ser removido
 * @param raiz Raiz da árvore ou subárvore
 * @return Nova raiz após a remoção
 */
struct no *remover(int valor, struct no *raiz)
{
    // Caso base: árvore vazia
    if (raiz == NULL)
        return raiz;

    // Busca o valor na árvore
    if (valor < raiz->dado)
    {
        raiz->esquerda = remover(valor, raiz->esquerda);
    }
    else if (valor > raiz->dado)
    {
        raiz->direita = remover(valor, raiz->direita);
    }
    // Valor encontrado, realiza a remoção
    else
    {
        // Caso 1 e 2: Sem filho ou com apenas um filho
        if (raiz->esquerda == NULL)
        {
            struct no *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            struct no *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 3: Nó com dois filhos
        // Encontra o sucessor (menor valor na subárvore direita)
        struct no *temp = minimo(raiz->direita);

        // Copia o valor do sucessor para este nó
        raiz->dado = temp->dado;

        // Remove o sucessor
        raiz->direita = remover(temp->dado, raiz->direita);
    }
    return raiz;
}

/**
 * Calcula a altura da árvore
 * @param raiz Raiz da árvore ou subárvore
 * @return Altura da árvore (0 para árvore vazia)
 */
int altura(struct no *raiz)
{
    // Caso base: árvore vazia
    if (raiz == NULL)
    {
        return 0;
    }

    // Calcula a altura das subárvores
    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    // Retorna a maior altura + 1 (para contar o nível atual)
    return (alturaEsquerda > alturaDireita) ? (alturaEsquerda + 1) : (alturaDireita + 1);
}

/**
 * Conta o número de nós na árvore
 * @param raiz Raiz da árvore ou subárvore
 * @return Número total de nós
 */
int contarNos(struct no *raiz)
{
    // Caso base: árvore vazia
    if (raiz == NULL)
    {
        return 0;
    }

    // Conta o nó atual + os nós nas subárvores
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

/**
 * Verifica se a árvore é uma BST válida
 * @param raiz Raiz da árvore ou subárvore
 * @param min Valor mínimo permitido
 * @param max Valor máximo permitido
 * @return 1 se for BST, 0 caso contrário
 */
int ehBST(struct no *raiz, int min, int max)
{
    // Árvore vazia é uma BST
    if (raiz == NULL)
    {
        return 1;
    }

    // Verifica se o valor está no intervalo permitido
    if (raiz->dado < min || raiz->dado > max)
    {
        return 0;
    }

    // Verifica recursivamente as subárvores
    // Para a subárvore esquerda, o valor máximo é o valor do nó atual - 1
    // Para a subárvore direita, o valor mínimo é o valor do nó atual
    return ehBST(raiz->esquerda, min, raiz->dado - 1) &&
           ehBST(raiz->direita, raiz->dado, max);
}

/**
 * Imprime a árvore de forma visual
 * @param raiz Raiz da árvore ou subárvore
 * @param nivel Nível atual do nó (para indentação)
 */
void imprimirArvore(struct no *raiz, int nivel)
{
    if (raiz == NULL)
        return;

    // Aumenta o nível para os filhos
    nivel += 5;

    // Visita subárvore direita primeiro (para exibir árvore horizontalmente)
    imprimirArvore(raiz->direita, nivel);

    // Imprime o nó atual com indentação de acordo com o nível
    printf("\n");
    for (int i = 5; i < nivel; i++)
    {
        printf(" ");
    }
    printf("%d\n", raiz->dado);

    // Visita subárvore esquerda
    imprimirArvore(raiz->esquerda, nivel);
}

/**
 * Libera a memória ocupada pela árvore
 * @param aonde Raiz da árvore ou subárvore a ser liberada
 */
void finalizar(struct no *aonde)
{
    if (aonde != NULL)
    {
        // Libera recursivamente as subárvores
        finalizar(aonde->esquerda);
        finalizar(aonde->direita);

        // Libera o nó atual
        free(aonde);
    }
}
