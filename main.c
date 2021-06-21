// #include <omp.h>
#include <time.h>
#include "stdio.h"
#include "stdlib.h"

#define SIZE 12

#include "Escalonador_Tarefas_Publico.h"

void run_resolver(int print) {
  pAuditorio pAuditorio = criar_auditorio(SIZE);
  upsert_atividade(pAuditorio, 0, 2, 8);
  upsert_atividade(pAuditorio, 1, 1, 5);
  upsert_atividade(pAuditorio, 2, 8, 11);
  upsert_atividade(pAuditorio, 3, 5, 7);
  upsert_atividade(pAuditorio, 4, 1, 4);
  upsert_atividade(pAuditorio, 5, 6, 10);
  upsert_atividade(pAuditorio, 6, 12, 14);
  upsert_atividade(pAuditorio, 7, 0, 6);
  upsert_atividade(pAuditorio, 8, 8, 12);
  upsert_atividade(pAuditorio, 9, 5, 9);
  upsert_atividade(pAuditorio, 10, 2, 13);
  upsert_atividade(pAuditorio, 11, 3, 8);

  if (print > 0)
    print_auditorio(pAuditorio);
  resolver(pAuditorio);
  if (print > 0)
    print_auditorio(pAuditorio);

  destruir_auditorio(pAuditorio);
}

void run_auditorio(int execution, int times) {
  clock_t begin = clock();

  for (int i = 0; i < times; i++) {
    run_resolver(0);
  }

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("%d;%d;%f", execution, times, end - time_spent);
}

int main(int argc, char** agrv) {
  if (argc <= 1) {
    run_resolver(1);
    return 0;
  }

  if (argc != 3) {
    printf("Wrong number of params, it was expected to be 2 parameters or none");
    return 1;
  }

  int execution = atoi(agrv[1]);
  int limit = atoi(agrv[2]);

  run_auditorio(execution, limit);

  return 0;
}