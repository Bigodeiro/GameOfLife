#include "automato.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//*Pronta
int** alocarReticulado(int x)
{
    int** reticulado = (int**) malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++)
    {
        reticulado[i] = (int*) malloc(x * sizeof(int));
    }
    return reticulado;
}


//*Pronta
void desalocarReticulado (int** reticulado, int x)
{
    for (int i = 0; i < x; i++)
    {
        free(reticulado[i]);
    }
    free(reticulado);
}


//*Pronta
void LeituraReticulado (Automato* automato, char* nomeArquivo)
{
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fscanf(arquivo, "%d %d", &automato->tamanho, &automato->geracao);
    automato->reticulado = alocarReticulado(automato->tamanho);


    for (int i = 0; i < automato->tamanho; i++)
    {
        for (int j = 0; j < automato->tamanho; j++)
        {
            fscanf(arquivo, "%d", &automato->reticulado[i][j]);
        }
    }
    fclose(arquivo);
}


//*Pronta
void imprimeReticulado(Automato* automato)
{
    for (int i = 0; i < automato->tamanho; i++)
    {
        for (int j = 0; j < automato->tamanho; j++)
        {
            printf("%d ", automato->reticulado[i][j]);
        }
        
        printf("\n");
    }
}


//*Pronta
int vizinhosVivos(Automato* automato, int x, int y)
{
    int vizinhos = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i >= 0 && i < automato->tamanho && j >= 0 && j < automato->tamanho)
            {
                if (automato->reticulado[i][j] == 1)
                {
                    vizinhos++;
                }
            }
        }
    }
    if (automato->reticulado[x][y] == 1)
    {
        vizinhos--;
    }
    return vizinhos;
}

//!Não pronta
void evoluirReticulado(Automato* automato)
{
    return;
}