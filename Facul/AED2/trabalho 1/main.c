/*
* Programa : main.c
* objetivo : le os textos passados para leitura e atribui uma pontuação de acordo com as palavras usadas
* Autor : Augusto dos Santos Gomes Vaz
* RA : 800268
* Data : 06/08/2022
*/

/* Bibliotecas */
#include "tabelaHash.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PALAVRA_TAM 15

int main()
{
    /* Declarações locais */
    int N, M;                   //N : numero de palavras, M : numero de textos
    int * pontuacao;              //guarda a pontuação de cada texto
    char string_Leitura[PALAVRA_TAM];    //guarda as palavras lidas do texto
    int valor_leitura;          //guarda o valor da palavra achada
    table * tabela;             //tabela hash
    char ** array_ptr;          //vetor que armazena as palavras a serem lidas MUDAR ISSO


    /* Leitura dos parâmetros de leitura */
    scanf("%d %d", &N, &M);

    tabela = criaTabela(N);
    array_ptr = (char**)malloc(N * sizeof(char*));
    pontuacao = (int*)malloc(M * sizeof(int));
    /* Leitura das palavras */
    for(int i = 0; i < N; i++){
        array_ptr[i] = (char*) malloc (PALAVRA_TAM * sizeof(char));
        int valor;
        scanf("%s %d", array_ptr[i], &valor);
        //printf("hash : %d\n", hashFunc(array_ptr[i], tabela->tamanho, tabela->primo));
        insereTabela(tabela, array_ptr[i], valor);
    }

    /* Leitura dos textos */
    for(int i = 0; i < M; i++)      //repete a quantidade de textos que houver
    {
        pontuacao[i] = 10;             //começa em 10 pois serão descontados 10 pontos na leitura do ponto final
        do
        {
            scanf("%s", string_Leitura);
            if(buscaTabela(tabela, string_Leitura, &valor_leitura))
                pontuacao[i] += valor_leitura;

            else
                pontuacao[i] -= 10;
        
        }while(strcmp(string_Leitura, "."));
    }


    for(int i = 0; i < M; i++)
        printf("%d\n", pontuacao[i]);
    

    /* Desalocando o vetor e a tabela */
    for(int i = 0; i < N; i++)
    {
    free(array_ptr[i]);
    }

    free(pontuacao);
    free(array_ptr);
    deletaTabela(tabela);


    system("pause");
    return 0;
}