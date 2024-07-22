#include "automato.h"

int main(int argc, char const *argv[])
{

    Automato automato;

    automato.tamanho = 3;
    automato.geracao = 0;
    automato.reticulado = alocarReticulado(automato.tamanho);

    for (int i = 0; i < automato.tamanho; i++)
    {
        for (int j = 0; j < automato.tamanho; j++)
        {
            automato.reticulado[i][j] = 1;
        }
    }

    printf("%d", vizinhosVivos(&automato, 1, 1));

    imprimeReticulado(&automato);


    desalocarReticulado(automato.reticulado, automato.tamanho);

    return 0;
}
