'''
Autor : Augusto dos Santos Gomes Vaz
Programa : criacao de um jogo "torre de hanoi" para estudo de classes
'''

#classe torre

class torreDeHanoi:
    def __init__(self, nDiscos):
        torreDeHanoi.nDiscos = nDiscos
        #vetor com as torres
        torreDeHanoi.torres = [[], [], []]
        
        for i in range(nDiscos, 0, -1):
            torreDeHanoi.torres[0].append(i)


    #passa o ultimo elemento da torre doadora pra torre receptora
    def passaDisco(self, doadora, receptora):
        if torreDeHanoi.torres[doadora] == []:
            return False

        if(doadora == receptora):
            return False

        if torreDeHanoi.torres[receptora] != []:
            if torreDeHanoi.torres[doadora][len(torreDeHanoi.torres[doadora]) -1] > torreDeHanoi.torres[receptora][len(torreDeHanoi.torres[receptora]) -1]:
                return False
        
        torreDeHanoi.torres[receptora].append(torreDeHanoi.torres[doadora].pop())
        return True

    def concluido(self):
        if torreDeHanoi.torres[0] == []:
            if len(torreDeHanoi.torres[2]) == torreDeHanoi.nDiscos:

                return True
        return False

    def printaTorres(self):
        #printando o topo
        for j in range(2):
            if j > 0:
                preenchimento = "| |"
            else:
                preenchimento = "_ "

            for i in range(3):
                for k in range(11 - j):
                    print(" ", end="")
                print(preenchimento, end="")
                for k in range(10):
                    print(" ", end="")
            print()

        #printando pinos e os discos, se for o caso
        for i in range(torreDeHanoi.nDiscos, -1, -1):#percorre a altura
            if(i < 1):
                preenchimento = "_"
            else:
                preenchimento = " "

            for j in range(3):#percorre as torres
                #caso esteja printando acima da parte que tem discos, somente printa a torre
                if(i >= len(torreDeHanoi.torres[j])):
                    for k in range(10):
                        print(preenchimento, end = "")
                    print("| |", end = "")
                    for k in range(10):
                        print(preenchimento, end = "")
                #caso haja um disco
                else:
                    for k in range(10 - torreDeHanoi.torres[j][i]):
                        print(preenchimento, end = "")
                    print("|", end = "")
                    for k in range(torreDeHanoi.torres[j][i] * 2 + 1):
                        print("/", end = "")
                    print("|", end = "")
                    for k in range(10 - torreDeHanoi.torres[j][i]):
                        print(preenchimento, end = "")
            print()

    def iniciaJogo(self):
        rodada = 1
        while(not torreDeHanoi.concluido(self)):
            print(f"Rodada {rodada}!")
            torreDeHanoi.printaTorres(self)
            doadora = int(input("Digite a torre doadora: "))
            receptora = int(input("Digite a torre receptora: "))
            if(not torreDeHanoi.passaDisco(self, doadora -1, receptora - 1)):
                print("Jogada invalida!")
            else:
                rodada += 1
        print("Fim de jogo!")
        print(f"Foram necessarios {rodada -1} passos!")


#inicio do jogo
repete = True
while repete:
    nDiscos = int(input("Com quantos discos voce quer jogar? "))
    jogo = torreDeHanoi(nDiscos)
    jogo.iniciaJogo()
    del jogo
    print("Deseja jogar novamente?")
    resposta = input("Digite S ou N: ")
    if(resposta != 'S'):
        repete = False