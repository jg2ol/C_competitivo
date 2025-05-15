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

    // .empty() --> booleano que verifica se o vetor está vazio ou não
    if (!vetor2.empty()) {cout << "O vetor2 nao esta vazio." << endl;}
    else {cout << "O vetor2 esta vazio." << endl;}

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
    // tambem podemos organizar em ordem decrescente
    // .rbegin() e .rend() --> ponteiro do início e final do vetor indicando que desejamos uma ordenação inversa
    sort(vetor1.rbegin(), vetor1.rend());
    
    for (int x = 0;  x < (int)vetor1.size(); x++) {cout << vetor1[x] << " ";}
    cout << endl;
    
    // remove(p_inicio, p_final, valor) --> elimina todos os elementos de valor específico
    // não altera o tamanho do vetor,
    // se foram retirados k elementos de uma vez só,
    // ele completa o vetor com últimos k elementos do vetor original, mesmo que contenha o elemento retirado.
    // assim, para casos específicos podemos utilizar v.resize(n - k).
    // a exemplo:
    vector <int> v = {1, 1, 1, 1, 2, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 5, 0, 6, 7, 8};
    
    remove(v.begin(), v.end(), 0); // remove os zeros e completa o vetor com os elementos do original
    for (int i : v) {cout << i << " ";} // outra forma de percorrer objetos da STL
    cout << endl;
    
    remove(v.begin(), v.end(), 1); // remove os 1's e completa o vetor com os 'k' últimos elementos remanescentes
    for (int i : v) {cout << i << " ";}
    cout << endl;
    
    
    // reverse(v.begin(), v.end()) --> inverte a ordem dos elementos de um vector
    reverse(v.begin(), v.end());
    
    // random_shuffle(v.begin(), v.end()) --> randomiza a ordem dos elementos de um vector
    random_shuffle(v.begin(), v.end());
    
    for (auto i : v) {cout << i << " ";}
    cout << "\n";


    // lower_bound(v.begin(), v.end(), x) --> ponteiro para o primeiro menor elemento maior ou igual a x
    // upper_bound(v.begin(), v.end(), x) --> ponteiro para o último menor elemento maior que x
    // O(log n)
    // ambas retornam -1 quando não existir tal valor
    // ambas p/ vetores ordenados
    // lower(x) - v.begin() --> posição de tal elemento (0-indexado)
    // *lower(x) --> valor numérico de tal elemento

    // equal_range(v.begin(), v.end(), x) === {lower_bound(x), upper_bound(x)};
    // auto r = equal_range(v.beign(), v.end(), x);
    // r.second - r.first --> retorna o número de elementos x presentes no vetor

    // ex.: Um código que retorna o valor mais próximo de x, num vector
    vector <int> v = {1, 3, 4, 7, 10, 15};
    
    int x = 6;
    auto it = lower_bound(v.begin(), v.end(), x);
    if (it == v.begin()) {
        cout << *it << "\n";
    } else if (it == v.end()) {
        it--;
        cout << *it << "\n";
    } else {
        int a = *it; it--;
        int b = *it;
        if (x-b < a-x) {cout << b << "\n";}
        else {cout << a << "\n";}
    } // 7
}