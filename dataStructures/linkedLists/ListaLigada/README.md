# Lista Duplamente Ligada em C

Este projeto implementa uma lista duplamente ligada em C, com operações de inserção ordenada, remoção e navegação.

## Estrutura da Lista Duplamente Ligada

Uma lista duplamente ligada é uma estrutura de dados que contém nós onde cada nó mantém:

-   Um valor de dados (`dado`)
-   Um ponteiro para o próximo nó (`proximo`)
-   Um ponteiro para o nó anterior (`anterior`)

## Características principais

-   **Inserção ordenada**: Os elementos são inseridos mantendo a ordem crescente dos valores
-   **Navegação bidirecional**: Pode percorrer a lista nos dois sentidos (para frente e para trás)
-   **Remoção de elementos**: Suporta remoção no início, meio ou fim da lista

## Funções implementadas

-   **inicializar()**: Inicializa a lista como vazia
-   **adicionar(int dado)**: Adiciona um elemento na lista, mantendo a ordem crescente
-   **excluir(int dado)**: Remove um elemento específico da lista
-   **listar()**: Exibe todos os elementos da lista na ordem
-   **verificarIntegridade()**: Verifica se todos os ponteiros estão corretamente ligados
-   **finalizar()**: Libera toda a memória alocada para a lista

## Como testar a implementação

A implementação pode ser testada das seguintes formas:

### 1. Testes básicos de operações

-   **Inserção**: Adicionar vários elementos e verificar se estão ordenados
-   **Remoção**: Remover elementos do início, meio e fim da lista
-   **Lista vazia**: Operações em lista vazia devem ser tratadas adequadamente

### 2. Verificação de integridade

A função `verificarIntegridade()` percorre a lista em ambas as direções, verificando:

-   Se os ponteiros `proximo` e `anterior` de nós adjacentes apontam um para o outro
-   Se a lista pode ser percorrida do início ao fim e do fim ao início sem inconsistências

### 3. Casos de borda para testar

-   Lista vazia
-   Lista com um único elemento
-   Remoção do último elemento
-   Inserção em lista vazia
-   Inserção no início da lista
-   Inserção no final da lista
-   Inserção no meio da lista

### 4. Verificação de vazamento de memória

-   Verificar se toda memória alocada é devidamente liberada na função `finalizar()`
-   Utilizar ferramentas como Valgrind para detecção de vazamentos

## Como depurar a aplicação

1. Compile o projeto em modo debug usando CMake:

    ```
    mkdir -p cmake-build-debug
    cd cmake-build-debug
    cmake ..
    cmake --build .
    ```

2. Execute com o depurador:

    - No VSCode: Use F5 ou clique no botão de depuração após configurar o arquivo launch.json
    - Linha de comando: `gdb ./cmake-build-debug/ListaLigada`

3. Pontos de depuração úteis:
    - Funções de adição (adicionarNoInicio, adicionarNoMeio, adicionarNoFinal)
    - Funções de exclusão (excluirNoInicio, excluirNoMeio, excluirNoFinal)
    - Função verificarIntegridade

## Limitações e possíveis melhorias

1. **Tratamento de erros**: Melhorar o tratamento de erros e validações
2. **Testes unitários**: Adicionar testes unitários automatizados
3. **Generalização**: Tornar a lista genérica para qualquer tipo de dados
4. **Encapsulamento**: Melhorar o encapsulamento da implementação
