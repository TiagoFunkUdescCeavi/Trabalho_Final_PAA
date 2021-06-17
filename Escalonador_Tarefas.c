#include "Escalonador_tarefas_Privado.h"

#include "stdio.h"

void print_atividade( A a ){
    printf( "Id: %d, Inicio: %d, Termino: %d\n", a->id, a->inicio, a->termino );
}

A criar_atividade( int id, int inicio, int termino ){
    A a;
    a->id = id;
    a->inicio = inicio;
    a->termino = termino;
    return a;
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

    // free( vl );
    // free( vr );
}

void merge_sort( A * v, int i, int f ){
    if( i < f ){
        int m = i+(f-i)/2;
        merge_sort( v, i, m );
        merge_sort( v, m+1, f );
        merge( v, i, m, f );
    }
}