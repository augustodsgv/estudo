'''
Autor : Augusto dos Santos Gomes Vaz
Programa : Estudo de vetores em python
'''
#teste das funcoes "pop()" e "append()"
vetor1 = [10, 15, 45, 90, 110]
vetor2 = []

print(vetor1)
print(vetor2)

vetor2.append(vetor1.pop())

print(vetor1)
print(vetor2)

#teste da funcao "len()"
print(f"O tamanho do vetor 1 e : {len(vetor1)}")
print(f"O tamanho do vetor 2 e : {len(vetor2)}")