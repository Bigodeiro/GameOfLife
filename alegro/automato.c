#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "automato.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int** alocarReticulado(int x)
{
    int** reticulado = (int**) malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++)
    {
        reticulado[i] = (int*) malloc(x * sizeof(int));
    }
    return reticulado;
}


void desalocarReticulado (int** reticulado, int x)
{
    for (int i = 0; i < x; i++)
    {
        free(reticulado[i]);
    }
    free(reticulado);
}


void LeituraReticulado(Automato* automato)
{
    scanf("%d", &automato->tamanho);
    scanf("%d", &automato->geracao);

    automato->reticulado = alocarReticulado(automato->tamanho);

    for (int i = 0; i < automato->tamanho; i++)
    {
        for (int j = 0; j < automato->tamanho; j++)
        {
            scanf("%d", &automato->reticulado[i][j]);
        }
    }
}


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

//TODO: Comentar
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
        vizinhos--;//!<-
    }
    return vizinhos;
}


void copiarReticulado(Automato* automato, int** reticuladoAux)
{
    for (int i = 0; i < automato->tamanho; i++)
    {
        for (int j = 0; j < automato->tamanho; j++)
        {
            automato->reticulado[i][j] = reticuladoAux[i][j];
        }
    }
}


void evoluirReticulado(Automato* automato)
{
    //! Caso Base
    if (automato->geracao == 0)
    {
        return;
    }

    //!Caso geral
    int** reticuladoAux = alocarReticulado(automato->tamanho);
    for (int i = 0; i < automato->tamanho; i++)
    {
        for (int j = 0; j < automato->tamanho; j++)
        {
            int vizinhos = vizinhosVivos(automato, i, j);
            if (automato->reticulado[i][j] == 1)
            {
                if (vizinhos < 2 || vizinhos > 3)
                {
                    reticuladoAux[i][j] = 0;
                }
                else
                {
                    reticuladoAux[i][j] = 1;
                }
            }
            else
            {
                if (vizinhos == 3)
                {
                    reticuladoAux[i][j] = 1;
                }
                else
                {
                    reticuladoAux[i][j] = 0;
                }
            }
        }
    }

    //!Processamento auxiliar
    copiarReticulado(automato, reticuladoAux);
    automato->geracao--;
    desalocarReticulado(reticuladoAux, automato->tamanho);

    //!Chamada recursiva
    evoluirReticulado(automato);
}

