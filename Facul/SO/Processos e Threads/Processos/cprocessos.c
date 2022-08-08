/*
* Programa : cprocessos.c
* Objetivo : Programa para estudo da criação de processos em c
* Autor : Augusto dos Santos Gomes Vaz
* Data : 29/06/2022
*
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

int main(){
    int contador = 0;
    pid_t retorno = 0;

    do{
        retorno = fork();
        if (retorno == 0){
            sleep(10);
            exit(0);
        }else if (retorno > 0){
            contador++;
        }
    }while (retorno != -1);
    

    printf("processos : %d", contador);

    return 0;
}