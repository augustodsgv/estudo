'''
Autor: Augusto dos Santos Gomes Vaz
Programa : jogo da velha proposta para os alunos das aulas de programação ministradas pelo pet
'''

from operator import truediv

def main():
    matriz = [["-", "-", "-"], ["-", "-", "-"], ["-", "-", "-"]]
    fim = False
    rodada = 0
    while(not fim and rodada < 9):
        rodada += 1
        printaMatriz(matriz)
        fazJogada(matriz, defineTurno(rodada))
        fim = fimDoJogo(matriz)
    printaMatriz(matriz)
    print("Fim de jogo!")
    if(fimDoJogo(matriz)):
        print(f"{defineTurno(rodada)} e o campeao")
    else:
          print("Velha!")


#verifica se o jogo chegou ao fim
def fimDoJogo(matriz):
    #verificando as linhas
    for i in range (3):
        if matriz[i][0] == matriz[i][1] == matriz[i][2] != "-":
            matriz[i][0] = matriz[i][1] = matriz[i][2] = "%"
            return True
    
    #verificando colunas
    for i in range (3):
        if matriz[0][i] == matriz[1][i] == matriz[2][i] != "-":
            matriz[0][i] == matriz[1][i] == matriz[2][i] != "%"
            return True

    #verificando diagonal principal
    if matriz[0][0] == matriz[1][1] == matriz[2][2] != "-":
        matriz[0][0] = matriz[1][1] = matriz[2][2] = "%"
        return True

    #verificando diagona secundária
    if matriz[0][2] == matriz [1][1] == matriz[2][0] != "-":
        matriz[0][2] = matriz [1][1] = matriz[2][0] = "%"
        return True

    #caso contrário
    return False

#define se é turno do X ou do O
def defineTurno(rodada):
    #turnos ímpares são do X, turnos pares são da O
    if rodada % 2 == 1:
        return "X"
    else:
        return "O"

#funcao que le o input do usuario e faz a joga, se for valido
def fazJogada(matriz, turno):
    jogadaValida = False
    #leitura da jogada
    while (not jogadaValida):
        xJogada = int(input("Digite a linha da sua jogada : ")) -1
        yJogada = int(input("Digite a coluna da sua jogada : ")) -1
        if xJogada < 3 and xJogada >= 0 and yJogada < 3 and yJogada >= 0:
            if matriz[xJogada][yJogada] == "-":
                matriz[xJogada][yJogada] = turno
                jogadaValida = True

            else:
                print("jogada invalida")
        else:
            print("jogada invalida!")

#funcao que desenha o jogo da velha na tela
def printaMatriz(matriz):
    for i in range(3):
        for j in range(3):
            print(f" {matriz[i][j]} ", end="")
        print()


        
#inicio do jogo
main()
