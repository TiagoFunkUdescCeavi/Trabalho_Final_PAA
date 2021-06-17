#ifndef PUBLICO_H
#define PUBLICO_H

typedef Atividade A;

A criar_atividade( int id, int inicio, int termino );
void ordenar( A * atividades, int tamanho );
void print_atividade( A a );

#endif