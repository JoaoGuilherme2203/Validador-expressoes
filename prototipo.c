#include<stdio.h>
#include<locale.h>
#include<string.h>

#define TAM 20
#define TIPO char

void criarP( int *topo ){
    *topo = -1;
}

int cheiaP( int topo ){
    return (topo == TAM-1) ? 1 : 0;
}

int vaziaP( int topo ){
    return (topo == -1) ? 1 : 0;
}

int inserirP(int *topo, TIPO pilha[], TIPO valor ){
    if( !cheiaP(*topo) ){
        (*topo)++;
        pilha[*topo] = valor;
        return 1;
    }
    else
        return 0;
}

int retirarP( int *topo, TIPO pilha[], TIPO *valor ){
    if( !vaziaP(*topo) ){
        *valor = pilha[*topo];
        (*topo)--;
        return 1;
    }
    else
        return 0;
}

void criarF( int *inicio, int *fim ){
    *inicio = 0;
    *fim = -1;
}

int cheiaF( int fim ){
    return (fim == TAM-1) ? 1 : 0;
}

int vaziaF( int inicio, int fim ){
    return ( inicio > fim ) ? 1 : 0;
}

int inserirF(int *fim, TIPO fila[], TIPO valor ){
    if( !cheiaF(*fim) ){
        (*fim)++;
        fila[*fim] = valor;
        return 1;
    }
    else
        return 0;
}

int retirarF( int *inicio, int fim, TIPO fila[], TIPO *valor ){
    if( !vaziaF(*inicio, fim) ){
        *valor = fila[*inicio];
        (*inicio)++;
        return 1;
    }
    else
        return 0;
}

int retirarPValor( int *topo, TIPO pilha[], TIPO *valor ){                                                                                  // retorna o valor da pilha;
    if( !vaziaP(*topo) ){
        *valor = pilha[*topo];
        (*topo)--;
        return *valor;
    }
    else
        return 0;
}

int checagemDelimitadores( int *topo, TIPO pilha[], TIPO *valor ){
    char a, b, c, d, e, f, g;

    a = retirarPValor( topo, pilha, valor );
    if( a == '}' ){
        b = retirarPValor( topo, pilha, valor );
        if( b == ']' ){
            c = retirarPValor( topo, pilha, valor );
            if( c == ')' ){
                d = retirarPValor( topo, pilha, valor );
                if( d == '(' ){
                    e = retirarPValor( topo, pilha, valor );
                    if( e == '[' ){
                        f = retirarPValor( topo, pilha, valor );
                        if( f == '{' ){
                            g = retirarPValor( topo, pilha, valor );
                            if( g == '{' || g == '}' || g == '[' || g == ']' || g == '(' || g == ')' ) return 0;
                            else return 1;
                        }else return 0;
                    }else return 0;
                }else return 0;
            }else return 0;
        }else return 0;
    }
    if( a == ']' ){
        b = retirarPValor( topo, pilha, valor );
        if( b == ')' ){
            c = retirarPValor( topo, pilha, valor );
            if( c == '(' ){
                d = retirarPValor( topo, pilha, valor );
                if( d == '[' ){
                    e = retirarPValor( topo, pilha, valor );
                    if( e == '{' || e == '}' || e == '[' || e == ']' || e == '(' || e == ')' ) return 0;
                    else return 1;
                }else return 0;
            }else return 0;
        }else return 0;
    }
    if( a == ')' ){
        b = retirarPValor( topo, pilha, valor );
        if( b == '(' ){
            c = retirarPValor( topo, pilha, valor );
            if( c == '{' || c == '}' || c == '[' || c == ']' || c == '(' || c == ')' ) return 0;
            else return 1;
        }else return 0;
    }if( a == 0 ) return 1;
    else return 0;
}

int main(){
    setlocale( LC_ALL, "portuguese" );

    int inicio1, fim1;                                                                                                                      // inicio e fim da fila 1;
    int topo1;                                                                                                                              // topo da pila 1;
    int i;                                                                                                                                  // variável de controle;
    char aux1;                                                                                                                              // variável auxiliar;
    char aux2;
    char fila1[TAM];                                                                                                                        // fila 1;
    char pilha1[TAM];                                                                                                                       // pilha 1;
    char expressao[TAM];                                                                                                                     // expressão a ser lida do usuário;

    printf( "Disciplina: Estrutura de dados I\n" );
    printf( "TRABALHO 01\n" );
    printf( "Professor: Marcos César Carrard\n" );
    printf( "Aluno: João Guilherme Dos Santos Dorini e Eduardo Chimello\n\n\n" );

    printf( "A expressão deve respeitar:\n\t-os delimitadores \"{[()]}\"\n\t-não deve conter espaço\n" );
    printf( "\nInsira uma expressão matemática para a validação ser feita: " );                                                               // leitura de dados;
    scanf( "%s", expressao );

    criarF( &inicio1, &fim1 );                                                                                                              // criação da fila;
    criarP( &topo1 );                                                                                                                       // criação da pilha;

    for( i=0; i<strlen(expressao); i++ ){                                                                                                   // laço para correr pela expressão
        switch( expressao[i] ){                                                                                                             // switch para caso encontre "( ) [] {}", colocar na pilha;
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}':
                inserirP( &topo1, pilha1, expressao[i] );
                break;
            default:
                inserirF( &fim1, fila1, expressao[i] );
                break;
        }
    }

    if( checagemDelimitadores( &topo1, pilha1, &aux1 ) ){
        printf( "\nA expressão \"%s\" é válida\n", expressao );
    }else printf( "\nA expressão \"%s\" é inválida\n", expressao );

    return 0;
}
