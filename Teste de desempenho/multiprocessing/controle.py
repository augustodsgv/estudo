'''
Autor : Augusto dos Santos Gomes Vaz
Programa : controle para o teste da biblioteca multiprocessing para executar programas em paralelo
'''
import time
from funcaoFibonacci import *

inicio = time.perf_counter()

for i in range(50):
    fibonacci(i)

fim = time.perf_counter()

print(f"Terminado em {round(fim - inicio, 4)} segundos")
