#include "stdio.h"
#include "stdlib.h"

#define SIZE 12

#include "Escalonador_Tarefas_Publico.h"

int main() {
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

  print_auditorio(pAuditorio);
  resolver(pAuditorio);
  print_auditorio(pAuditorio);

  destruir_auditorio(pAuditorio);

  return 0;
}