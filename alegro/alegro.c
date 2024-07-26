#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "automato.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LARGURA_TELA 512
#define ALTURA_TELA 512

int main (int argc, char const *argv[])
{
    Automato automato;
    
    LeituraReticulado(&automato);
    //int aux = automato.geracao;
    
    //*Incializações do allegro
    al_init();
    al_init_font_addon();
    al_init_primitives_addon();

    //*definições da janela
    ALLEGRO_DISPLAY * display = al_create_display(LARGURA_TELA,ALTURA_TELA);
    al_set_window_position(display, 200, 200);

    //*Declarações necessárias
    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 3.0);

    //*Código necessario para poder fechar a janela no "x"
    ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    //*loop principal
    while(true){
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
            break;

        al_clear_to_color(al_map_rgb(0,0,0));

        //*Desenha o reticulado
        if(event.type == ALLEGRO_EVENT_TIMER)
        {
            if(automato.geracao == 0)
            {
                break;
            }

            int aux = automato.geracao;
            automato.geracao = 1;
            evoluirReticulado(&automato);
            automato.geracao = aux - 1;

            for (int i = 0; i < automato.tamanho; i++)
            {
                for (int j = 0; j < automato.tamanho; j++)
                {
                    if (automato.reticulado[i][j] == 1)
                    {
                        al_draw_filled_rectangle(i * LARGURA_TELA/automato.tamanho, j * ALTURA_TELA/automato.tamanho, (i+1) * LARGURA_TELA/automato.tamanho, (j+1) * ALTURA_TELA/automato.tamanho, al_map_rgb(255,0,255));
                    }
                }
            }
        }
        al_flip_display();
    }

    //*Desalocaentos
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}