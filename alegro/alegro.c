#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LARGURA_TELA 512
#define ALTURA_TELA 512

typedef struct automato
{
    int tamanho;
    int** reticulado;
    
    int geracao;

}Automato;

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
    if (automato->geracao == 0)
    {
        return;
    }


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

    copiarReticulado(automato, reticuladoAux);
    automato->geracao--;

    desalocarReticulado(reticuladoAux, automato->tamanho);

    evoluirReticulado(automato);
}

void evoluirReticulado1vez(Automato* automato)
{
    if (automato->geracao == 0)
    {
        return;
    }


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

    copiarReticulado(automato, reticuladoAux);
    automato->geracao--;

}

int main (int argc, char const *argv[])
{
    if (argc < 2) {
        printf("Por favor lembre-se de inserir o nome do arquivo de entrada\n");
        return 1;
    }

    Automato automato;
    
    LeituraReticulado(&automato);
    int aux = automato.geracao;
    
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
            evoluirReticulado1vez(&automato);
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