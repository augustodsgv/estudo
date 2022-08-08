'''
Autor : Augusto dos Santos Gomes Vaz
Programa : teste do uso de arquivos em python
Data : 20/06/2022
'''
#Abertura do arquivo
arquivo = open("C:\\Users\\ipadp\\OneDrive\\Área de Trabalho\\arquivo.txt", "r")

#Leitura do arquivo
#print(arquivo.read())
print(arquivo.readline())
print(arquivo.readline())

#Fechamento do arquivo
arquivo.close()

