/*
Autor : Augusto dos Santos
Programa : leitura e escrita de arquivos em c
*/
#include<stdio.h>

int main(){
    //declaração das variaveis locais
    int variavel_escrita = 12345;
    int variavel_leitura;

    //declaracao e abertura do arquivo para leitura
    FILE * arquivo;
    arquivo = fopen("arquivoC.dat", "w");

    //escrita do arquivo
    fwrite(&variavel_escrita, sizeof(int), 1, arquivo);

    //fechamento do arquivo para abertura em leitura
    fclose(arquivo);
    arquivo = fopen("arquivoC.dat", "r");

    //leitura dos dados
    fread(&variavel_leitura, sizeof(int), 1, arquivo);

    //output dos dados lidos
    printf("A variavel lida foi %d\n", variavel_leitura);

    //fechamento do arquivo
    fclose(arquivo);

    return 0;
}