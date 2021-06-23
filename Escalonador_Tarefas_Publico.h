#ifndef PUBLICO_H
#define PUBLICO_H

typedef struct Auditorio* pAuditorio;

pAuditorio criar_auditorio(int maxSize);
int upsert_atividade(pAuditorio pAuditorio, int pos, int inicio, int termino);
int resolver(pAuditorio pAuditorio);
void print_auditorio(pAuditorio pAuditorio);
int destruir_auditorio(pAuditorio pAuditorio);

#endif