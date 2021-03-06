#include "Escalonador_tarefas_Privado.h"
#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0

pAuditorio criar_auditorio(int maxTamanho) {
  pAuditorio auditorio = (pAuditorio)malloc(sizeof(Auditorio));
  Atividade* atividades = criar_atividades(maxTamanho);
  auditorio->atividades = atividades;
  auditorio->maxTamanho = maxTamanho;

  return auditorio;
}

Atividade* criar_atividades(int maxTamanho) {
  return malloc(sizeof(Atividade) * maxTamanho);
}

int upsert_atividade(pAuditorio pAuditorio, int pos, int inicio, int termino) {
  if (pos >= pAuditorio->maxTamanho) {
    return FALSE;
  }

  Atividade atividade = pAuditorio->atividades[pos];
  atividade.id = pos;
  atividade.inicio = inicio;
  atividade.termino = termino;
  atividade.reservado = FALSE;

  pAuditorio->atividades[pos] = atividade;

  return TRUE;
}

void print_auditorio(pAuditorio pAuditorio) {
  printf("Tamanho maximo auditório: %d\n", pAuditorio->maxTamanho);
  for (int i = 0; i < pAuditorio->maxTamanho; i++) {
    Atividade atividade = pAuditorio->atividades[i];
    if (atividade.id >= 0) {
      print_atividade(atividade);
    }
  }
}

void print_atividade(Atividade a) {
  printf("Id: %d,\tInicio: %d,\tTermino: %d,\tReservado: %s\n", a.id, a.inicio, a.termino, a.reservado?"Sim":"Não");
}

int resolver(pAuditorio pAuditorio) {
  if (!pAuditorio) {
    return FALSE;
  }

  ordenar(pAuditorio->atividades, pAuditorio->maxTamanho);
  int count = 0;

  Atividade atual = pAuditorio->atividades[0];
  atual.reservado = TRUE;
  pAuditorio->atividades[0] = atual;
  count++;

  for (int i = 1; i < pAuditorio->maxTamanho; i++) {
    if (pAuditorio->atividades[i].inicio < atual.termino) {
      continue;
    }

    atual = pAuditorio->atividades[i];
    atual.reservado = TRUE;
    pAuditorio->atividades[count] = atual;
    count++;
  }

  return TRUE;
}

int destruir_auditorio(pAuditorio pAuditorio) {
  if (pAuditorio == NULL) {
    return TRUE;
  }

  free(pAuditorio->atividades);
  free(pAuditorio);
  return TRUE;
}

void ordenar(Atividade* atividades, int tamanho) {
  merge_sort(atividades, 0, tamanho - 1);
}

void merge(Atividade* v, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  // Atividade vl[n1];
  Atividade* vl = malloc(sizeof(Atividade) * n1);
  Atividade* vr = malloc(sizeof(Atividade) * n2);
  // Atividade vr[n2];

  for (i = 0; i < n1; i++) {
    vl[i] = v[l + i];
  }
  for (j = 0; j < n2; j++) {
    vr[j] = v[m + j + 1];
  }

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (vl[i].termino <= vr[j].termino) {
      v[k] = vl[i];
      i++;
    } else {
      v[k] = vr[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    v[k] = vl[i];
    i++;
    k++;
  }

  while (j < n2) {
    v[k] = vr[j];
    j++;
    k++;
  }

  free(vl);
  free(vr);
}

void merge_sort(Atividade* v, int i, int f) {
  if (i < f) {
    int m = i + (f - i) / 2;
    merge_sort(v, i, m);
    merge_sort(v, m + 1, f);
    merge(v, i, m, f);
  }
}