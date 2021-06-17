#ifndef PRIVADO_H
#define PRIVADO_H

#include "Escalonador_Tarefas_Publico.h"

typedef struct Atividade{
    int id;
    int inicio;
    int termino;
} Atividade;

void merge( A * v, int l, int m, int r );
void merge_sort( A * v, int i, int f );

#endif