''' 
Autor : Augusto dos Santos
Programa : teste de escrita textos em arquivos binários
Data : 22/06/2022
'''

''' Textos '''
#abertura do arquivo
arquivo = open("arquivoTextosBinario.dat", "rb")

#leitura do conteudo
texto_binario = arquivo.read(12)

#conversao para texto normal
texto = texto_binario.decode("utf-8")

#output dos textos
print(f"texto em binario : {texto_binario}")
print(f"texto convertido {texto}")

''' Números '''
#leitura do numero em binario
numero_binario = arquivo.read(4)

#conversao para numeros decimais
numero = int.from_bytes(numero_binario, "big")

#output dos numeros
print(f"numero em binario{numero_binario}")
print(f"numero normal {numero}")


#fechamento do arquivo
arquivo.close()