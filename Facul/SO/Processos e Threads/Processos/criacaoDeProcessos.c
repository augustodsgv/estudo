/*
Autor : Augusto dos Santos
Programa : programa que cria processos no terminal linux
*/
//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>




int main(){

    pid_t ret = fork();
    int nProcessos = 1;

    if (ret == 0){
        printf("processo filho");
        exit(0);
    }

    printf("Criando novos processos!\n");

    while(ret != 0){
        nProcessos++;
        ret = fork();
        if(ret == -1){
            perror("Erro ao criar novos processos ");
            break;
        }
    }

    if(ret != 0){
        printf("%d processos foram criados\n", nProcessos);
    }
    return 0;
}

