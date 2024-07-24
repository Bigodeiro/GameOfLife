#ifndef AUTOMATO
#define AUTOMATO

typedef struct automato
{
    int tamanho;
    int** reticulado;
    
    int geracao;

}Automato;


int** alocarReticulado( int );
void desalocarReticulado( int**, int );
void LeituraReticulado( Automato*, const char* );
void imprimeReticulado( Automato* );
int vizinhosVivos( Automato*, int, int );
void evoluirReticulado( Automato* );
void copiarReticulado( Automato* , int** );
// int getCelula(Automato* automato, int x, int y, int valor );


#endif // !AUTOMATO