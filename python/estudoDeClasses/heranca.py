'''
Autor : Augusto dos Santos Gomes Vaz
Programa : Estudo de herança em python
'''

#classe pai
class pessoa:
    def __init__(self, nome, cpf, nacionalidade):
        pessoa.nome = nome
        pessoa.cpf = cpf
        pessoa.nacionalidade = nacionalidade
    
    def printaPessoa(self):
        print(f"Nome: ", pessoa.nome)
        print(f"CPF: ", pessoa.cpf)
        print(f"Nacionalidade: ", pessoa.nacionalidade)

#classe filho
class aluno(pessoa):
    def __init__(self, nome, cpf, nacionalidade, RA, curso):
        super().__init__(nome, cpf, nacionalidade)
        aluno.RA = RA
        aluno.curso = curso

    def printaAluno(self):
        super().printaPessoa()
        print(f"RA: {aluno.RA}")
        print(f"Curso: {aluno.curso}")

#programa princial
p1 = pessoa("Augusto", 0000, "Brasil")
p1.printaPessoa()
print()
a1 = aluno("Augusto", 0000, "Brasil", 80000, "Ciencia da computacao")
a1.printaAluno()

''' 
Portanto a sintaxe de herança é

#classe pai
class pai:
    ...
#classe filho
class filho(pai):
    ...

o construtor do pai é sobrescrito pelo do filho, caso esse seja criado
o comando "super()" permite que o filho acesse métodos do pai
no caso do construtor, pode ser usado o comando super(). para usar o metodo init do pai

'''