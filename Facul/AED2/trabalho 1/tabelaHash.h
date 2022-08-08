/*
* Autor : Augusto dos Santos Gomes Vaz
* Programa : cabeçalho da implementação de uma tabela de espalhamento
*/

#ifndef TABELA_HASH_H
#define TABELA_HASH_H

/* REGISTROS */

//registro que representa cada palavra e seu valor
typedef struct word{
    char * wordString;
    int value;
    int ativo;
}word;

//registro que representa a tabela avl e seu tamanho
typedef struct table{
    word * vetor;
    int tamanho;
    int primo;
}table;


/* FUNÇÕES */

//devolve um tamanho sugerido para a tabela com base na quantidade de elementos que serão guardados nela
int tamanhoTabela(int n_elementos);

//cria uma palavra a partir de uma string e seu valor
word criaPalavra(char palavra[], int valor);

//cria uma tabela hash com o tamanho especificado
table * criaTabela(int tamanho);

//printa todas as palavras do vetor de palavras
int printaTabela(table * tabela);

//trata as colisões
int trata_colisao(table * tabela, char * string, int hash);

//indica se achou a palavra na tabela
int buscaTabela(table * tabela, char * string, int * valor);

//insere elementos na tabela
int insereTabela(table * tabela, char * string, int valor);

//remove uma string da tabela
int removeTabela(table * tabela, char * string);

//desaloca o vetor da tabela e a tabela
int deletaTabela(table * tabela);
#endif /*TABELA_HASH_H*/