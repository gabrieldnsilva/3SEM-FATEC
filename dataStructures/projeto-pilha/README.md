# Estrutura de Dados - Projeto Pilha

## Aula 02 – Projeto Pilha

**Prof. Marcos Nava**

### Algoritmo de Balanceamento de Parênteses

Você receberá uma expressão numérica, por exemplo:

```
(2*25+(55/2))/3
```

Você deve usar uma pilha para verificar se os parênteses estão balanceados.

### Descrição do Projeto

1. Cada vez que você encontrar na string um abre parênteses, você deve guardar a informação em uma pilha de char.
2. Quando encontrar um fecha parênteses na string, você deve tirar o elemento da pilha.
3. O algoritmo termina quando toda a string estiver sido processada.

### Regras do Algoritmo

-   Se quando você estiver processando a string e tentar retirar algo da pilha e a pilha estiver vazia, a expressão não está balanceada.
-   Se ao final do processo você ainda tiver elementos na pilha, a expressão está desbalanceada.

### Exemplos

-   `(2*25+(55/2))/3` -> Balanceada
-   `2*25+(55/2))/3` -> Desbalanceada
-   `(2*25+(55/2()/3` -> Desbalanceada
-   `(2*25+55/2/3` -> Desbalanceada
-   `2*25+55/2)/3` -> Desbalanceada
