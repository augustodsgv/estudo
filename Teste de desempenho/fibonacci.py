import time

def fibonacci(n):
    if n == 0:
        return 1
    if n == 1:
        return 1
    return fibonacci(n-1) + fibonacci(n - 2)

#programa
n = int(input("Digite o valor de fibo: "))
inicio = time.time()
print(fibonacci(n))
fim = time.time()
print(f"Tempo gasto: {fim - inicio}")

    