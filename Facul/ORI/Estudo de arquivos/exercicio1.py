'''
Autor : Augusto dos Santos
Programa : busca as linhas do arquivo de texto até que ache a palavra 'lenghtened'
Data : 20/06/2022
'''

#abrindo o arquivo
arquivo = open("arquivoEx1.txt", "r")

#algoritmo de busca
palavra = ""
while not "lengthened" in palavra:
    palavra = arquivo.readline()
    
print(palavra)

#fechando o arquivo
arquivo.close()