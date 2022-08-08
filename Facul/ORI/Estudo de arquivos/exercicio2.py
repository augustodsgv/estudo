'''
Autor : Augusto dos Santos
Programa : 1. Crie um programa para criar um arquivo binário com 20 valores inteiros. Escolha o comprimento de bytes a seu gosto. 
Data : 22/06/2022
'''

#Criação do arquivo
arquivo = open("arquivoEx2.dat", "wb")

#Criação do array com os numeros
numeros, numeros_binarios = [], []

for i in range(20):
    numero = int(input(f"Digite o {i + 1} numero a ser escrito no arquivo: "))
    numeros.append(numero)

#conversao dos numero para binario
for numero in numeros:
    numeros_binarios.append(numero.to_bytes(4, "big"))

#escrita dos numeros no arquivo
for numero in numeros_binarios:
    arquivo.write(numero)

#fechamento do arquivo e abertura para leitura
arquivo.close()
arquivo = open("arquivoEx2.dat", "rb")

#leitura dos numeros
for i in range(20):
    numero_bytes =  int.from_bytes(arquivo.read(4), "big")
    print(f"Leitura dos numero {i} : {numero_bytes}")    