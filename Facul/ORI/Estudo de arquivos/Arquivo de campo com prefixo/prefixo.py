'''
Autor : Augusto dos Santos Gomes Vaz
Programa : implementaçao de um modelo de arquivo usando prefixo com o tamanho do arquivo
Data : 23/06/2022
'''

''' Leitura '''
#abertura do arquivo para leitura
arquivo = open("arquivoPrefixo.txt", "r")

''' Primeira leitura '''
#leitura do prefixo
prefixo = int(arquivo.read(2)) #o prefixo será de 2 bits
print(f"ha {prefixo} caracteres")

#leitura do conteudo
texto_leitura = arquivo.read(prefixo + 1)#leitura do +1 para pular o \n

print(texto_leitura)

''' Segunda leitura '''
#leitura do prefixo
prefixo = int(arquivo.read(2)) #o prefixo será de 2 bits
print(f"ha {prefixo} caracteres")

#leitura do conteudo
texto_leitura = arquivo.read(prefixo + 1)#leitura do +1 para pular o \n

print(texto_leitura)

#fechamento do arquivo para leitura
arquivo.close()