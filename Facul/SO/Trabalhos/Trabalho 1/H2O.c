/*
* Programa : H2O
* Objetivo : trabalho da matéria de "Sistemas Operacionais"
* Link original no Google Colab : https://colab.research.google.com/drive/106M2_Hd_sMXcnQCUzttNX-nzjPuFm2kv
* Autores : Augusto dos Santos Gomes Vaz
            Gabriel Lourenço de Paula Graton
            Rafael Naoki Arakaki Uyeta
            Vitor Matheus da Silva
* Data : 18/07/2022
*/

//Bibliotecas
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/membarrier.h>
#include <sys/syscall.h>

//Declarações globais
sem_t smutex,filaOxi,filaHidro;
pthread_barrier_t barreira;

//Contadores
int oxigenio=0,hidrogenio=0;

pthread_t oxyThread, oxyThread2,hydroThread1,hydroThread2, hydroThread3, hydroThread4;

//Função que verifica se há três átomos para formar a água
int bond()
{
    static int i=0;
    i++;
    if((i%3)==0){
      printf("Molecula numero %d criada. \n \n", i/3);
    }
        
    sleep(2);
    return 0;
}

//Função que gerencia as threads de oxigênio
void* oxyFn(void* arg)
{
    while(1)
    {
        sem_wait(&smutex);              // Utiliza o mutex para utilizar recursos 
        oxigenio+=1;

        if(hidrogenio>=2)
        {
            sem_post(&filaHidro);        // Libera um espaço na fila da Hidrogenios
            sem_post(&filaHidro);        // Libera um espaço na fila da Hidrogenios
            hidrogenio-=2;
            sem_post(&filaOxi);          // Libera um espaço na fila da Oxigenios
            oxigenio-=1;
        }
        else                              // Se não tiver Hidrogenios suficientes, irá liberar o mutex para a 
            sem_post(&smutex);            //criação de novos Hidrogenios ou Oxigenios, até obter a razão 2:1
        
        sem_wait(&filaOxi);               // Adiciona um Oxigenio na fila dos Oxigenios
        printf("Criou Oxigenio\n");
        bond();                           // Tenta criar a Molecula de H2O

        printf("Oxigenio entrou na Barreira \n");
        pthread_barrier_wait(&barreira);  // Espera a criação de novos Hidrogenios
        printf("Oxigenio saiu da barreira \n");
        sem_post(&smutex);                // Libera o Mutex após sair da barreira
    }
}

//Função que gerencia as threads de hidrogênio
void* hydroFn(void* arg)
{
    while(1)
    {
        sem_wait(&smutex);  
        hidrogenio+=1;

        if(hidrogenio>=2 && oxigenio>=1)
        {
            sem_post(&filaHidro);    //Libera um espaço na fila da Hidrogenios
            sem_post(&filaHidro);
            hidrogenio -= 2;
            sem_post(&filaOxi);      //Libera um espaço na fila da Oxigenios
            oxigenio-=1;
        }
        else
            sem_post(&smutex);
        sem_wait(&filaHidro);        // Adiciona um Hidrogenio na fila dos Hidrogenios
        printf("Criou Hidrogenio \n");
        bond();                       // Tenta criar a Molecula de H2O

        printf("Hidro entrando na barreira \n");
        sleep(5);
        pthread_barrier_wait(&barreira); 
        printf("Hidro saindo na barreira \n");
                                      
                                      // Perceber que não possui o sem_post para o mutex, 
                                     // como explicado pelo livro "Little Book of Semaphores",
                                    // não há nenhuma regra que diz que uma thread necessita ter
                                   // a trava de um mutex para soltá-lo.

                                     // A thread final, ou seja, que forma a molécula de água, tem
                                    // que barrar a criação de novas threads até a formação completa
                                   // do H2O.
      }
}


//Função principal
int main()
{
    if(sem_init(&smutex,0,1)==-1)                    // Inicialização do Mutex
        perror("erro inicializando semaforo\n");
    if(sem_init(&filaOxi,0,0)==-1)                   // Inicialização da Fila Oxigenio
        perror("erro inicializando semaforo\n");
    if(sem_init(&filaHidro,0,0)==-1)                 // Inicialização da Fila Hidrogenio
        perror("erro inicializando semaforo\n");
    if(pthread_barrier_init(&barreira, 0, 3) == -1)  // Inicialização da barreira
        perror("erro inicializando barreira\n");
    
    pthread_create(&oxyThread,0,oxyFn, NULL);
    pthread_create(&hydroThread1,0,hydroFn, NULL);
    pthread_create(&hydroThread2,0,hydroFn, NULL);
    
    /*
    pthread_create(&hydroThread3,0,hydroFn, NULL);
    pthread_create(&oxyThread2,0,oxyFn, NULL);
    pthread_create(&hydroThread4,0,hydroFn, NULL);
    //*/

    for(;;);


    /*               // Liberar os semaforos e barreiras ao final da execução
    free(&smutex);    //porém nesse exemplo a execução é infinita.
    free(&filaOxi);
    free(&filaHidro);
    free(&barreira);
    //*/
}
