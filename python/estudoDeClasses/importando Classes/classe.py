'''
Autor : Augusto dos Santos Gomes Vaz
Programa : Implementação de uma classe para importa-la em outro arquivo
'''

#classe pessoa
class pessoa:
    def __init__(self, nome, genero ,idade, cpf, nacionalidade):
        pessoa.nome = nome
        pessoa.genero = genero
        pessoa.idade = idade
        pessoa.cpf = cpf
        pessoa.nacionalidade = nacionalidade
        

    #funcao de print
    def printPessoa(self):
        print(f"Nome : {pessoa.nome}")
        print(f"Genero : {pessoa.genero}")
        print(f"Idade : {pessoa.idade}")
        print(f"CPF : {pessoa.cpf}")
        print(f"Nacionalidade : {pessoa.nacionalidade}")