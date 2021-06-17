#include "stdlib.h"
#include "stdio.h"

#define SIZE 11

struct Atividade{
    int id;
    int inicio;
    int termino;
} typedef Atividade;

void print_atividade( Atividade a ){
    printf( "Id: %d, Inicio: %d, Termino: %d\n", a.id, a.inicio, a.termino );
}

Atividade criar_atividade( int id, int inicio, int termino ){
    Atividade a;
    a.id = id;
    a.inicio = inicio;
    a.termino = termino;
    return a;
}

void merge( Atividade * v, int l, int m, int r ){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    Atividade vl[ n1 ];
    Atividade vr[ n2 ];

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
        if( vl[ i ].termino <= vr[ j ].termino ){
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

void merge_sort( Atividade * v, int i, int f ){
    if( i < f ){
        int m = i+(f-i)/2;
        merge_sort( v, i, m );
        merge_sort( v, m+1, f );
        merge( v, i, m, f );
    }
}


int main( int argc, char ** argv ){

    Atividade ativs[ SIZE ];
    ativs[ 0 ] = criar_atividade( 1, 3, 5 );
    ativs[ 1 ] = criar_atividade( 2, 8, 11 );
    ativs[ 2 ] = criar_atividade( 3, 5, 7 );
    ativs[ 3 ] = criar_atividade( 4, 1, 4 );
    ativs[ 4 ] = criar_atividade( 5, 6, 10 );
    ativs[ 5 ] = criar_atividade( 6, 12, 14 );
    ativs[ 6 ] = criar_atividade( 7, 0, 6 );
    ativs[ 7 ] = criar_atividade( 8, 8, 12 );
    ativs[ 8 ] = criar_atividade( 9, 5, 9 );
    ativs[ 9 ] = criar_atividade( 10, 2, 13 );
    ativs[ 10 ] = criar_atividade( 11, 3, 8 );

    merge_sort( ativs, 0, SIZE-1 );

    for (int i = 0; i < SIZE; i++){
        print_atividade( ativs[ i ] );
    }

    printf(">>>>>>>>>>>>>>>\n");
    Atividade atual = ativs[ 0 ];
    print_atividade( atual );
    for (int i = 0; i < SIZE; i++){
        if( ativs[ i ].inicio >= atual.termino ){
            print_atividade( ativs[ i ] );
            atual = ativs[ i ];
        }
    }
    
    

    return 0;
    
}