// #include <omp.h>
#include <time.h>

#include "stdio.h"
#include "stdlib.h"


#include "Escalonador_Tarefas_Publico.h"

int* getRand(int maxValue) {
  int r1 = rand() % maxValue;
  int r2 = rand() % maxValue;

  int min = r1;
  int max = r2;
  if (r2 < min) {
    min = r2;
    max = r1;
  }

  if (min == max) {
    if (min == maxValue) {
      min--;
    } else {
      max++;
    }
  }

  int* vector = malloc(sizeof(int) * 2);
  vector[0] = min;
  vector[1] = max;

  return vector;
}

void upsert_random(pAuditorio pAuditorio, int id, int max) {
  int* vector = getRand(max);
  upsert_atividade(pAuditorio, id, vector[0], vector[1]);
  free(vector);
}

void run_resolver(int print, int size) {
  time_t t;
  /* Intializes random number generator */
  srand((unsigned)time(&t));

  pAuditorio pAuditorio = criar_auditorio(size);

  for (int i = 0; i < size; i++) {
    upsert_random(pAuditorio, i, 23);
  }

  if (print > 0)
    print_auditorio(pAuditorio);

  clock_t begin = clock();
  resolver(pAuditorio);
  clock_t end = clock();
  double time_spent = ((double)(end - begin) / (double) CLOCKS_PER_SEC);
  printf("%d;%lf", size, time_spent);

  if (print > 0)
    print_auditorio(pAuditorio);

  destruir_auditorio(pAuditorio);
}

void run_auditorio(int size) {
  run_resolver(0, size);
}

int main(int argc, char** agrv) {
  if (argc <= 1) {
    run_resolver(1, 12);
    return 0;
  }

  if (argc != 2) {
    printf("Wrong number of params, it was expected to be 1 parameters or none");
    return 1;
  }


  int size = atoi(agrv[1]);
  run_auditorio(size);

  return 0;
}