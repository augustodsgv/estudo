''' 
Autor : Augusto dos Santos
Programa : teste de escrita de textos em arquivos binários
Data : 22/06/2022
'''

''' Textos '''
#criacao do arquivo
arquivo = open("arquivoTextosBinario.dat", "wb")


#escrita do texto a ser convertido
texto = "hello world\n"

#conversão em binário
texto_binario = bytes(texto, "utf-8")


#output dos textos
print(f"texto normal {texto}")
print(f"texto em binario : {texto_binario}")

#escrita do texto em binário no arquivo
arquivo.write(texto_binario)

''' Números '''
#declaracao do numero a ser convertido
numero = 1410

#conversão para bytes
numero_binario = numero.to_bytes(4, "big")

#output dos numeros
print(f"numero normal {numero}")
print(f"numero em binario {numero_binario}")

#escrita no arquivo
arquivo.write(numero_binario)




#fechamento do arquivo
arquivo.close()