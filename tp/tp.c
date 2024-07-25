#include "automato.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

//! Estruturar o main
int main()
{
    Automato automato;

    LeituraReticulado(&automato);

    evoluirReticulado(&automato);

    imprimeReticulado(&automato);

    desalocarReticulado(automato.reticulado, automato.tamanho);

    return 0;
}