#ifndef PRIVADO_H
#define PRIVADO_H

#include "Escalonador_Tarefas_Publico.h"

struct __atividade{
    int id;
    int inicio;
    int termino;
};

void ordenar( Atividade * atividades, int tamanho );

void merge( Atividade * v, int l, int m, int r );
void merge_sort( Atividade * v, int i, int f );

#endif