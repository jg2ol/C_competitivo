#include <bits/stdc++.h>
using namespace std;

// set --> um vetor de elementos distintos e ordenados (não permite repetição de elemento)

int main() {
    // declaração, estrutura: set <tipo> nome;
    set <int> t;

    // .insert(elemento) --> insere um elemento no set
    // O(log n) [n: tamanho do set]
    t.insert(1);
    t.insert(3);
    t.insert(9);
    t.insert(-2);
    t.insert(0);
    t.insert(-2); // não acontece nada aqui, pois, -2 já está em t
    // t = {-2, 0, 1, 3, 9}

    // .erase(elemento) --> remove um elemento do set
    // O(log n)
    t.erase(9);
    t.erase(-1); // nada acontece, pois, -1 não pertence à t

    // .begin() --> ponteiro para o primeiro elemento do set
    cout << "O primeiro elemento do set 't' e " << *t.begin() << endl;
    
    // .end() --> ponteiro para o último elemento do set
    cout << "O ultimo elemento do set 't' e " << *(--t.end()) << endl;
    // ambos em O(1)
    // não faz sentido pensar em ordenar um set, pois, ele já é naturalmente ordenado

    // .find(elemento) --> retorna um ponteiro para o elemento procurado
    // caso não esteja no set, retorna um ponteiro para o final do set
    // O(log n)
    if (t.find(3) != t.end()) {cout << "3 e um elemento do set t." << endl;}
    else {cout << "3 nao e um elemento de t." << endl;}
    // verifca se um elemento pertence ao set

    // .empty() --> booleano que verifica se o set está ou não vazio
    // O(1)
    if (t.empty()) {cout << "O set t esta vazio." << endl;}
    else {cout << "O set t nao esta vazio." << endl;}

    // .size() --> retorna a quantidade de elementos do set
    // O(1)
    cout << "O set t tem " << (int)t.size() << " elementos." << endl << endl;

    // .clear() --> limpa o set
    // O(n)
    set <int> u;
    u.insert(1);
    u.insert(2);
    u.insert(3);
    u.clear();
    if (u.empty()) {cout << "O set u esta vazio." << endl;}
    else {cout << "O set u nao esta vaizo." << endl;}
    cout << endl;

    // .lower_bound(x) --> retorna um ponteiro para o primeiro elemento que não vem antes que x (o próprio x)
    // .uper_bound(x) --> retorna um ponteiro para o primeiro elemento que vem depois de x
    // ambos em O(log n)
    set <int> v;
    for (int x = 1; x < 10; x++) {v.insert(x);} // v = {1, 2, 3, 4, 5, 6, 7, 8, 9}
    int lb = *--v.lower_bound(3), ub = *v.upper_bound(3);
    cout << "O elemento que vem antes de 3 no set 'v' e " << lb << ", e o que vem depois e " << ub << endl;

    // .count(elemento) --> retorna 1 se o elemento está no set e 0 caso contrário
    if (v.count(5) == 1) {cout << "5 pertence ao set 'v'.  [v.count(5) = " << v.count(5) << "]" << endl;}
    else {cout << "5 nao pertence ao set 'v'.  [v.count(5) = " << v.count(5) << "]" << endl;}

    // percorrendo um set...
    // um set é organizado de maneira bem mais complaxa do que vetores, além da necessidade de ponteiros,
    // os elementos não estão lado a lado, além da ordenação crescente automática
    // https://pt.wikipedia.org/wiki/%C3%81rvore_rubro-negra --> sobre a organização de um set
    // para percorrer por todos os valores de um set, precisamos de um 'iterator'
    
    // estrutura: set <tipo> ::iterator nome_do_iterator;
    // for (nome = set.begin(); nome != set.end(); nome++) { bloco de código; ex.: cout << *it << " "; }
    cout << endl;
    set <int> lista;
    for (int x = 0; x <= 10; x++) {lista.insert(x);}
    set <int> ::iterator it;
    cout << "Elementos do set 'lista': ";
    for (it = lista.begin(); it != lista.end(); it++) {cout << *it << " ";}
    // imprime todos os valores do set 'lista' (sempre ordenado)
    // note que não podemos fazer it += k (para k E Z), mas podemos fazer it++;

    // as funções lower, upper e equal_range ficam mais simples usando set
    // .lower_bound(x) --> retorna um ponteiro p/ o primeiro menor elemento maior ou igual que x
}