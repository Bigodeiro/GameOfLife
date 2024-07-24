#include "automato.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

//! Estruturar o main
int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("Por favor lembre-se de inserir o nome do arquivo de entrada\n");
        return 1;
    }
    
    Automato automato;

    LeituraReticulado(&automato, argv[1]);

    evoluirReticulado(&automato);

    imprimeReticulado(&automato);

    desalocarReticulado(automato.reticulado, automato.tamanho);

    return 0;
}