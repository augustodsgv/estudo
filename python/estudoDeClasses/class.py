'''
Autor : Augusto dos Santos Gomes Vaz
Programa : Estudo da orientação a objeto em python
'''

class classe:
    def __init__(self, nome, idade, nacionalidade):
        classe.nome = nome
        classe.idade = idade
        classe.nacionalidade = nacionalidade
    
    #funcao de print
    def printaID(self):
        print(f"Nome : {c1.nome}")
        print(f"Idade : {c1.idade}")
        print(f"Nacionalidade : {c1.nacionalidade}")
    
    #setters
    def setNome(self, nome):
        classe.nome = nome
    
    def setIdade(self, idade):
        classe.idade = idade

    def setNacionalidade(self, nacionalidade):
        classe.nacionalidade = nacionalidade

    

    #getters
    #ainda nao precisa


#programa principal
c1 = classe("Augusto", 19, "Brasil")

c1.printaID() 

'''
Portanto a sintaxe de classes é:
class nomeClasse:
    #construtor
    def __init__(paramentros, ...,):
        ...
    
'''