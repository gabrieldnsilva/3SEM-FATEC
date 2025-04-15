#ifndef LISTA_H
#define LISTA_H

typedef struct
{
    char nome[100];
    char endereco[200];
    char cpf[12]; // 11 + /0
    char telefone[20];
    char email[100];
} Pessoa;

typedef struct Node
{
    Pessoa pessoa;
    struct Node *proximo;
} Node;

typedef struct
{
    Node *inicio;
    int tamanho;
} Lista;

// Protótipos das funções para manipulação da LISTA
Lista *criarLista();
void destruirLista(Lista *lista);
int estaVazia(Lista *lista);
int tamanhoLista(Lista *lista);

// Protítipos das funções para manipulação dos dados
int adicionarPessoa(Lista *lista, Pessoa pessoa);
int excluirPessoa(Lista *lista, const char *cpf);
int alterarPessoa(Lista *lista, const char *cpf, Pessoa novaPessoa);
Pessoa *buscarPessoa(Lista *lista, const char *cpf);
void imprimirPessoa(Pessoa pessoa);
void imprimirTodos(Lista *lista);
void ordenarPessoasPorNome(Lista *lista);

#endif // LISTA_H