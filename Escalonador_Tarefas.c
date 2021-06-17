#include "Escalonador_tarefas_Privado.h"

#include "stdio.h"
#include "stdlib.h"

void print_atividade( A a ){
    printf( "Id: %d, Inicio: %d, Termino: %d\n", a->id, a->inicio, a->termino );
}

A criar_atividade( int id, int inicio, int termino ){
    A a = (A) malloc( sizeof( A ) );
    a->id = id;
    a->inicio = inicio;
    a->termino = termino;
    return a;
}

Solucao resolver( A* atividades, int tamanho ){
    Solucao s;
    s.tamanho = 0;

    if( tamanho < 0 || atividades == NULL ) return s;
    
    ordenar( atividades, tamanho );
    s.atividades = (A*) malloc( sizeof( A ) * tamanho );

    A atual = atividades[ 0 ];
    s.atividades[ 0 ] = atual;
    s.tamanho++;
    for (int i = 1; i < tamanho; i++){
        if( atividades[ i ]->inicio >= atual->termino ){
            atual = atividades[ i ];
            s.atividades[ s.tamanho ] = atual;
            s.tamanho++;
        }
    }
    return s;
}

void ordenar( A * atividades, int tamanho ){
    merge_sort( atividades, 0, tamanho-1 );
}

void merge( A * v, int l, int m, int r ){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    A vl[ n1 ];
    A vr[ n2 ];

    for( i = 0; i < n1; i++ ){
        vl[ i ] = v[ l+i ];
    }
    for( j = 0; j < n2; j++ ){
        vr[ j ] = v[ m+j+1 ];
    }

    i = 0;
    j = 0;
    k = l;
    while( i < n1 && j < n2 ){
        if( vl[ i ]->termino <= vr[ j ]->termino ){
            v[ k ] = vl[ i ];
            i++;
        }else{
            v[ k ] = vr[ j ];
            j++;
        }
        k++;
    }

    while( i < n1 ){
        v[ k ] = vl[ i ];
        i++;
        k++;
    }

    while( j < n2 ){
        v[ k ] = vr[ j ];
        j++;
        k++;
    }
}

void merge_sort( A * v, int i, int f ){
    if( i < f ){
        int m = i+(f-i)/2;
        merge_sort( v, i, m );
        merge_sort( v, m+1, f );
        merge( v, i, m, f );
    }
}