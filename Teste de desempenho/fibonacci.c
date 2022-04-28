#include <stdio.h>
#include <time.h>
#include <unistd.h>

double fiboRecursiva(int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    return fiboRecursiva(n - 1) + fiboRecursiva(n - 2);
}

double fiboIterativa(int n){
    double vetor[n];
    for (int i = 0; i < n; i++){
        if (i == 0 || i == 1){
            vetor[i] = 1;
        }else{
            vetor[i] = vetor[i - 1] + vetor[i - 2];    
        }
    }
    return vetor[n-1];
}




int main(){
    int n;
    printf("Digite o valor de fibo: ");
    scanf("%d", &n);


    clock_t begin = time(NULL);
    printf("fibo = %lf\n", fiboRecursiva(n));


    clock_t end = time(NULL);

    printf("Tempo gasto: %d", end - begin);
    

    return 0;
}