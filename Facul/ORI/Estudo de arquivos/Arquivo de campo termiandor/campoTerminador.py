''' 
Autor : Augusto dos Santos
Programa : implementação de um modelo de arquivo com campo com terminador
Data : 23/06/2022
'''

''' Escrita '''
#abertura do arquivo para escrita
arquivo = open("arquivoTerminador.txt", "w")


#criacao do texto a ser escrito
texto_escrever = "texto para ser escrito no arquivo"

#escrita do texto no arquivo
arquivo.write(texto_escrever)

#adicionando o terminador
arquivo.write("\\f")

#fechamento do arquivo para escrita
arquivo.close()


''' Leitura '''
#abertura do arquivo para leitura
arquivo = open("arquivoTerminador.txt", "r")

#o terminador será o bit "\f"
texto = ""
fim_do_arquivo = False

while not fim_do_arquivo:
    #leitura de um byte
    byte = arquivo.read(1)

    #caso seja um caractere especial, começa com \
    if byte == '\\':
        byte = arquivo.read(1) #leitura do próximo byte, para definir seu significado

        if byte == 'f': #caso em que o \f ocorre, indicando o fim do arquivo
            fim_do_arquivo = True

        elif byte == '\\': #uso do byte de enchimento: usar \ antes da \n ignora sua funcao especial
            texto += byte

    else: #caso não seja um caractere especial
        texto += byte

#output da leitura
print(texto)

#fechamento do arquivo
arquivo.close()

