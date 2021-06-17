#ifndef PUBLICO_H
#define PUBLICO_H

typedef struct Atividade* A;

typedef struct Solucao{
    int tamanho;
    A * atividades;
} Solucao;

A criar_atividade( int id, int inicio, int termino );
Solucao resolver( A* atividades, int tamanho );
void print_atividade( A a );

#endif