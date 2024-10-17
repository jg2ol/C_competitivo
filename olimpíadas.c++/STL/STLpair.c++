#include <bits/stdc++.h>
using namespace std;

// pair --> tupla com dois elementos

int main() {
    // estrutura de declaração: pair <tipo1, tipo2> nome;
    pair <int, int> par1; // cria um par de dois valores inteiros
    
    // acessando elementos
    // .first e .second são as chamadas para elementos de um pair
    par1.first = 2;
    par1.second = 5;
    cout << "Primeiro elemento de par1: " << par1.first << endl;
    cout << "Segundo elemento de par1: " << par1.second << endl << endl;
    // par1 = {2, 5}

    // vetores + pairs ...
    vector<pair <string, double>> vetor;
    vetor.push_back({"Joao", 5});
    vetor.push_back({"Maria", 7.5});
    vetor.push_back({"Jose", 9});
    for (int x = 0; x  < 3; x++) {cout << "Aluno: " << vetor[x].first << "; Nota: " << vetor[x].second << endl;}
    cout << endl;

    // podemos comparar diretamente dois ou mais pair's
    // primeiro o código compara os primeiros elementos e depois, em caso de empate,
    // compara os segundos elementos de cada pair;
    // com isto, podemos ordenar um vetor de pair's com o sort()
    pair <int, int> par2;
    par2.first = 2;
    par2.second = 3;
    if (par1 > par2) {cout << "O par1 e maior que o par2." << endl;}
    else {cout << "O par2 é maior ou igual ao par1." << endl;}
}