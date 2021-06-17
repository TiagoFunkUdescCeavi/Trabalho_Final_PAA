#ifndef PUBLICO_H
#define PUBLICO_H

typedef struct __atividade* Atividade;

typedef struct Solucao{
    int tamanho;
    Atividade * atividades;
} Solucao;

Atividade criar_atividade( int id, int inicio, int termino );
Solucao resolver( Atividade* atividades, int tamanho );
void print_atividade( Atividade a );

#endif