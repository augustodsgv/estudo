'''
Autor : Augusto dos Santos Gomes Vaz
Programa : Estudo de iteradores em python
'''

class hora:
    def __iter__(self):
        self.a = 1
        return self
    def __next__(self):
        x = self.a
        self.a += 1
        return x


#classe princiapal
classe = hora()
iterador = iter(classe)


print(next(iterador))
print(next(iterador))
print(next(iterador))
print(next(iterador))
print(next(iterador))
