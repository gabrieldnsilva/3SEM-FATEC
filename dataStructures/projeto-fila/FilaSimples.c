//
// Created by nava on 11/03/25.
// Edited by Gabriel on 25/03/2025
//

#include <stdio.h>
#include "FilaSimples.h"
#include "senha.h"

// Variáveis
Senha fsFila[FSTAMANHO]; // Change to Senha type
int fsInicio = 0;
int fsFim = 0;

// Funções
bool fsEstaVazia()
{
    return fsInicio == fsFim;
    // if (fsInicio == fsFim) {
    //     return true;
    // } else {
    //     return false;
    // }
}

bool fsEstaCheia()
{
    return fsFim == FSTAMANHO;
}

bool fsAdicionar(Senha senha)
{
    if (fsEstaCheia())
    {
        return false;
    }
    fsFila[fsFim] = senha;
    fsFim++;
    return true;
}

bool fsRetirar(Senha *senha)
{
    if (fsEstaVazia())
    {
        return false;
    }
    *senha = fsFila[fsInicio];
    fsInicio++;
    return true;
}

void fsImprimir()
{
    if (fsEstaVazia())
    {
        printf("Fila vazia!\n");
    }
    else
    {
        printf("+---+-----+\n");
        for (int i = fsInicio; i < fsFim; i++)
        {
            printf("| %1d | ", i);
            imprimirSenha(fsFila[i]); // Use imprimirSenha instead of printing int value
            printf("+---+-----+\n");
        }
    }
}
