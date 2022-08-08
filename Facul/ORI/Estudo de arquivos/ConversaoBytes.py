'''
Autor : Augusto dos Santos
Programa : teste de conversao para  bytes em arquivos
Data  21/06/2022
'''

'''CONVERSÃO PARA BYTES'''
'''textos'''
#texto normal
texto = "Hello world"

#convertendo texto
textoEmBytes = bytes(texto, "utf-8")

#output do texto em bytes
print(f"Convertendo [{texto}] para bytes : [{textoEmBytes}]")

'''números'''
#numero em decimal
numero = 1410

#convertendo numero para binario
numeroEmBytes = numero.to_bytes(5, "big")

#output
print(f"Convertendo [{numero}] para bytes : [{numeroEmBytes}]")


'''DECODIFICAÇÃO'''
#texto
texto = textoEmBytes.decode("utf-8")
print(f"convertendo de bytes [{textoEmBytes}] para [{texto}]")

#numeros
numero = int.from_bytes(numeroEmBytes, "big")
print(f"convertendo de bytes [{numeroEmBytes}] para [{numero}]")
