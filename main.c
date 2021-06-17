#include "stdlib.h"
#include "stdio.h"

#define SIZE 11

#include "Escalonador_Tarefas_Publico.h"


int main( int argc, char ** argv ){

    Atividade atividades[ SIZE ];
    atividades[ 0 ] = criar_atividade( 1, 3, 5 );
    atividades[ 1 ] = criar_atividade( 2, 8, 11 );
    atividades[ 2 ] = criar_atividade( 3, 5, 7 );
    atividades[ 3 ] = criar_atividade( 4, 1, 4 );
    atividades[ 4 ] = criar_atividade( 5, 6, 10 );
    atividades[ 5 ] = criar_atividade( 6, 12, 14 );
    atividades[ 6 ] = criar_atividade( 7, 0, 6 );
    atividades[ 7 ] = criar_atividade( 8, 8, 12 );
    atividades[ 8 ] = criar_atividade( 9, 5, 9 );
    atividades[ 9 ] = criar_atividade( 10, 2, 13 );
    atividades[ 10 ] = criar_atividade( 11, 3, 8 );

    Solucao s = resolver( atividades, SIZE );

    for( int i = 0; i < s.tamanho; i++ ){
        print_atividade( s.atividades[ i ] );
    }
    
    return 0;
    
}