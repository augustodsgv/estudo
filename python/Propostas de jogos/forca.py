'''
Autor: Augusto dos Santos Gomes Vaz
Programa : jogo da forca proposto para os alunos das aulas de programação ministradas pelo pet
'''

#funcao que compila tudo e inicia o jogo
def iniciaJogo(vetorDePalavras):
    fase = 0
    while fase < len(vetorDePalavras):
        print(f"*FASE {fase + 1}*")
        erros = 0
        palavra = vetorDePalavras[fase]
        vetorDeLetras = []
        for _ in palavra:
            vetorDeLetras.append("_")

        while(not achouAPalavra(palavra, vetorDeLetras) and erros < 6):
            printaForca(erros)
            printaLetras(vetorDeLetras)
            if not verificaLetra(palavra, vetorDeLetras, leJogada()):
                erros += 1
        if(achouAPalavra(palavra, vetorDeLetras)):
            print()
            printaLetras(vetorDeLetras)
            print(f"Parabens, voce conseguiu concluir com {erros} erros!")
            fase += 1
        else:
            print()
            print(f"Forca!")
            printaForca(erros)
        input("Pressione qualquer tecla para continuar")
        print()
    print("Parabens, voce concluiu todas as fases!")

#funcao que desenha a forca na tela
def printaForca(nErros):
    cabeca = ["|", "|    ( )", "|    ( )", "|    ( )", "|    ( )", "|    ( )", "|    ( )"]
    torax = ["|", "|", "|     |", "|    /|", "|    /|\ ", "|    /|\ ", "|    /|\ "]
    pernas = ["|", "|", "|", "|", "|", "|    / ", "|    / \ "]

    print(" _____")
    print("|     |")
    print(cabeca[nErros])
    print(torax[nErros])
    print(pernas[nErros])
    print("|", end=" ")

#funcao que verifica se a letra esta presente na palavra
def verificaLetra(palavra, vetorLetras, letra):
    existeLetra = False
    for i in range(len(palavra)):
        if palavra[i] == letra:
            vetorLetras[i] = letra
            existeLetra = True

    return existeLetra

#funcao que desenha as letras ou tracos na tela
def printaLetras(vetorLetras):
    for i in vetorLetras:
        print(i, end = " ")
    print()

#le a jogada do usuario
def leJogada():
    jogadaInvalida = True
    while (jogadaInvalida):
        letra = input("Digite uma letra: ")
        jogadaInvalida = letra.isdigit()
    return letra.upper()
    
#indica se a palavra foi achada
def achouAPalavra(palavra, vetorDeLetras):
    for i in range(len(palavra)):
        if palavra[i] != vetorDeLetras[i]:
            return False
    return True


#programa principal
palavrasDoJogo = ["PORCO", "PESSEGO", "LAVANDERIA", "ESTOJO", "BOLSA", "COMPUTADOR", "AVESTRUZ", "AXOLOTE"]
iniciaJogo(palavrasDoJogo)

