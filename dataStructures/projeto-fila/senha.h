#ifndef SENHA_H
#define SENHA_H

#include <time.h>
#include <stdlib.h>
#include <string.h>

// Tipos de atendimento
#define TIPO_CLINICO_GERAL "CG"
#define TIPO_PEDIATRIA "PD"
#define TIPO_PREFERENCIAL "PR"
#define NUM_TIPOS 3

// Estruturas da senha
typedef struct
{
    char tipo[3];
    char prioridade;
    int numero;
    time_t timestamp;
} Senha;

// Contador para tipo de atendimento
typedef struct
{
    char tipo[3];
    int contador;
} ContadorTipo;

ContadorTipo contadores[] = {
    {TIPO_CLINICO_GERAL, 0},
    {TIPO_PEDIATRIA, 0},
    {TIPO_PREFERENCIAL, 0}};

// Protítipos
Senha gerarSenha(const char *tipo, int prioritaria);
void imprimirSenha(Senha s);
const char *tipoAleatorio();
int prioridadeAleatoria();

#endif // SENHA_H