#include "automato.h"
#include <stdio.h>

//! Estruturar o main
int main(int argc, char const *argv[])
{

    Automato automato;

    LeituraReticulado(&automato, "entrada.txt");


    

    printf("matriz:\n");
    imprimeReticulado(&automato);

    printf("vizinhos proximos da celular do meio: %d\n", vizinhosVivos(&automato, 1, 1));

    desalocarReticulado(automato.reticulado, automato.tamanho);

    return 0;
}
