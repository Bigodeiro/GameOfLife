#include "automato.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

//! Estruturar o main
int main(int argc, char const *argv[])
{
    Automato automato;

    LeituraReticulado(&automato, "entrada.txt");
    int aux = automato.geracao;


    evoluirReticulado(&automato);

    printf("Resultado após %d gerações:\n", aux);
    imprimeReticulado(&automato);

    desalocarReticulado(automato.reticulado, automato.tamanho);

    return 0;
}
