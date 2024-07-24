#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    int escolha = 0, continua = 1;
    char nomeArquivo[256];

    while (continua == 1)
    {
        
        printf(
            "Voce deseja ter uma interface gráfica (A biblioteca allegro deve estar instalada) \n\t"
            "(1): Sim eu quero ter interface grafica\n\t"
            "(2): Nao, nao quero ter interface grafica\n \t"
            "(3): Como instalo a biblioteca allegro?\n \t"
            "(0) Sair\n"
        );
        
        scanf("%d", &escolha);

        if (escolha == 1)
        {
            printf("Agora insira o nome do arquivo de entrada (O arquivo DEVE estar dentro da pasta \"testes\")\n");
            scanf("%s", nomeArquivo);


            char comando[300] = "alegro/./exe testes/";
            strcat(comando, nomeArquivo);

            printf("Compilando...\n");
            system("cd alegro && make");

            printf("Inciando...\n");

            system("clear");
            system(comando);

            continua = 0;
        }
        else if (escolha == 2)
        {
            printf("Agora insira o nome do arquivo de entrada (O arquivo DEVE estar dentro da pasta \"testes\")\n");
            scanf("%s", nomeArquivo);


            char comando[300] = "tp/./exe testes/"; 
            strcat(comando, nomeArquivo);

            printf("Compilando...\n");
            system("cd tp && make");

            printf("Inciando...\n");

            system("clear");
            system(comando);

            continua = 0;
        }
        else if (escolha == 3)
        {
            printf(
                "Insira o comando especificado de acordo com seu sistema operacional no terminal e rode o programa novamente \n\t"
                "Ubuntu, debian, Linux Mint e similares: \" sudo apt install liballegro5.2 liballegro5-dev \"\n\t"
                "Fedora e similares: \" sudo dnf install allegro5 allegro5-devel \"\n \t"
                "Arch linux, Manjaro e similares: \" sudo pacman -S allegro \"\n \t"
                "Winsows: baixe o instalador no site oficial da allegro e siga as instrucoes de instalacao \n"
            );
            continua = 0;
        }
        else if (escolha == 0)
        {
            continua = 0;
        }
        else
        {
            printf("Opcao invalida, tente novamente!!!\n");
        }

    }

    return 0;
}
