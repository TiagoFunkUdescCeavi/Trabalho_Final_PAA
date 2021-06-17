#ifndef PRIVADO_H
#define PRIVADO_H

#include "Escalonador_Tarefas_Publico.h"

struct Atividade{
    int id;
    int inicio;
    int termino;
};

void ordenar( A * atividades, int tamanho );

void merge( A * v, int l, int m, int r );
void merge_sort( A * v, int i, int f );

#endif