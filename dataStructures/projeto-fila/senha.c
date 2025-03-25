#include "senha.h"

// Funções
Senha gerarSenha(const char *tipo, int prioritaria)
{
    Senha novaSenha;
    int i;

    strncpy(novaSenha.tipo, tipo, 2);
    novaSenha.tipo[2] = '\0';

    novaSenha.prioridade = prioritaria ? 'P' : 'N';

    for (int i = 0; i < NUM_TIPOS; i++)
    {
        if (strcmp(contadores[i].tipo, tipo) == 0)
        {
            contadores[i].contador++;
            novaSenha.numero = contadores[i].contador;
            break;
        }
    }

    novaSenha.timestamp = time(NULL);

    return novaSenha;
}

void imprimirSenha(Senha s)
{
    printf("Senha: %s-%c-%03d\n", s.tipo, s.prioridade, s.numero);
}

const char *tipoAleatorio()
{
    int index = rand() % NUM_TIPOS;
    return contadores[index].tipo;
}

int prioridadeAleatoria()
{
    return (rand() % 4) == 0;
}