/*
* Programa : thread1.c
* Objetivo : Estudo da criação de threads em linux em C
* Autor : Augusto dos Santos Gomes Vaz
* Data : 06/07/2022
*
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//funcao aleatoria so pra testar
void * funcaoInutil(){
	int * inteiro = (int*)malloc(sizeof(int));
	*inteiro = 1410;
	return inteiro;
}	


int main(){
	void * numero;
	pthread_t t1;
	pthread_create(&t1, NULL, funcaoInutil(), NULL);
	pthread_join(t1, &numero);

	printf("o valor de resultado da thread e %p",(int*)numero);


	return 0;
}
