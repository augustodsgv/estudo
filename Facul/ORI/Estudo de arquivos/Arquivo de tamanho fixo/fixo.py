'''
Autor : Augusto dos Santos Gomes Vaz
Programa : implementaçao de um modelo de arquivo de tamanho fixo
Data : 23/06/2022
'''

''' Leitura '''
#abertura do arquivo para leitura
arquivo = open("arquivoFixo.txt", "r")

#o tamanho do campo é 10
''' Primeira leitura '''
texto = arquivo.read(10)
print(texto)

''' Segunda leitura '''
texto = arquivo.read(10)
print(texto)

''' Terceira leitura'''
texto = arquivo.read(10)
print(texto)

#fechamento do arquivo para leitura
arquivo.close()

