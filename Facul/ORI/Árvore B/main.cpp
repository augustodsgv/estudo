/*
* Programa : main.cpp
* Objetivo : teste da implementação da arvore B
* Autor : Augusto dos Santos Gomes Vaz
* Data : 08/08/08
*/


#include "node.h"
#include "busca_binaria.h"
#include <iostream>
using namespace std;
//using namespace busca_binaria;
int
main()
{
    int vetor[] = {1, 3, 5, 7, 9, 11};

   //* 
    node :: node <int> novo_no (100);
    cout << "criou " << endl;

    novo_no.insere_vetor(1);
    novo_no.insere_vetor(3);
    novo_no.insere_vetor(5);
    novo_no.insere_vetor(7);
    novo_no.insere_vetor(9);
    novo_no.insere_vetor(11);

    novo_no.printa_tabela();
    
    novo_no.remove_vetor(11);
    novo_no.printa_tabela();


    novo_no.remove_vetor(5);
    novo_no.printa_tabela();
    
    novo_no.remove_vetor(9);
    novo_no.printa_tabela();
    novo_no.remove_vetor(3);
    novo_no.printa_tabela();
    novo_no.remove_vetor(1);
    novo_no.printa_tabela();
    novo_no.remove_vetor(7);
    novo_no.printa_tabela();
    
    //*/
    return 0;
}