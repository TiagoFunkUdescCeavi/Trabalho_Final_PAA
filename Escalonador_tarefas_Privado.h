#ifndef PRIVADO_H
#define PRIVADO_H

#include "Escalonador_Tarefas_Publico.h"

typedef struct Atividade {
  int id;
  int inicio;
  int termino;
  int reservado;
} Atividade;

typedef struct Auditorio {
  int maxTamanho;
  Atividade* atividades;
} Auditorio;

void ordenar(Atividade* atividades, int tamanho);
void merge(Atividade* atividades, int l, int m, int r);
void merge_sort(Atividade* atividades, int i, int f);
void print_atividade(Atividade a);
Atividade* criar_atividades(int maxTamanho);

#endif