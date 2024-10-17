#include <bits/stdc++.h>
using namespace std;

// sobre a Standard Template Library (STL)...
// vetor dinâmico --> funciona como uma lista em Python

int main() {
    // estrutura da declaração: vector <tipo> nome;
    vector <int> vetor1;

    // .push_back(valor) === .append(valor) --> adiciona um elemento no final do vetor
    // O(1)
    vetor1.push_back(1);
    vetor1.push_back(2);
    vetor1.push_back(7);
    vetor1.push_back(3);
    vetor1.push_back(6);
    vetor1.push_back(9);
    vetor1.push_back(0);

    // .pop_back() === .pop() --> remove o último elemento do vetor
    // O(1)
    vetor1.pop_back();
    vetor1.pop_back();

    // .begin() e .end() --> retorna, respectivamente, um ponteiro para o começo e fim de um vetor

    // .back(), acessar o último elemento de um vector
    cout << "O ultimo elemento de vetor1 e " << vetor1.back() << endl;

    // .erase(*i) === .pop(i) --> remove um elemento de índice específico
    // O(n)
    // devemos utilizar o ponteiro do primeiro elemento do vetor + a distância entre os dois elementos
    // estrutura: nome.erase(nome.begin() + i) --> apaga o elemento de índice i
    vetor1.erase(vetor1.begin() + 3);
    vetor1.erase(vetor1.begin() + 1, vetor1.begin() + 2); // apaga os elementos das posições 1 e 2

    // .clear() --> apaga todos os elementos do vetor
    // O(n)
    vector <int> vetor2;
    for (int x = 0; x < 4; x++) {vetor2.push_back(x);}
    vetor2.clear();

    // (int)vetor.size() === len(vetor) --> retorna a quantidade de elementos de um vetor
    // O(1)
    // vetor.size() retorna um tipo diferente de inteiro, portanto, para fazer
    // comparações entre inteiro e .size() usamos o (int) para o computador transformá-lo para inteiro
    cout << "O vetor1 possui " << vetor1.size() << " elementos." << endl;

    // .resize(n) --> expande o vetor para n posições
    // O(n)
    vetor1.resize(8); // coloca 'zeros' no final do vetor até que fique com 8 posições
    vetor1.resize(12, -3); // adiciona -3 até que o vetor1 fique com 12 posições
    
    for (int x = 0;  x < (int)vetor1.size(); x++) {cout << vetor1[x] << " ";}
    cout << endl;

    // organizando um vector com sort()
    // O(nlog n)
    sort(vetor1.begin(), vetor1.end());

    for (int x = 0;  x < (int)vetor1.size(); x++) {cout << vetor1[x] << " ";}
}