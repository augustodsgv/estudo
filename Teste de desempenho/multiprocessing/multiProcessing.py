'''
Autor : Augusto dos Santos Gomes Vaz
Programa : teste da biblioteca multiprocessing para executar programas em paralelo
'''
import time
import multiprocessing
from funcaoFibonacci import *

numeroFibo = 40
if __name__ == "__main__":
    processos = []

    inicio = time.perf_counter()

    for i in range(30):
        p = multiprocessing.Process(target=fibonacci, args=[i])
        p.start()
        processos.append(p)

    for i in range(30):
        processos[i].join()

    fim = time.perf_counter()

    print(f"Terminado em {round(fim - inicio, 4)} segundos")
