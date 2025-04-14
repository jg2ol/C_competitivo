#include <bits/stdc++.h>
using namespace std;

// deque --> queue em que podemos facilmente adicionar/remover
// elementos do final e início da "fila"
// deque = queue + vector
// IMPORTANTE: iterator's e ponteiros geralmente não mudam de valor,
// mesmo quando o valor de uma posição já tenha mudado

void print_deque(deque <int> &d) {
    for (int i : d) {cout << i << " ";}
}
void fprint_deque(deque <int> &d) {
    cout << "{";
    print_deque(d);
    cout << "}" << endl;
}

int main() {
    deque <int> dq;
    
    // .push_front() --> adiciona um valor no começo da fila
    // O(n)
    dq.push_front(1);
    dq.push_front(-5);
    dq.push_front(150);
    dq.push_front(4);
    dq.push_front(9); // dq = {1, -5, 150, 4, 9}

    // .push_back() --> adiciona um valor no final da fila
    // O(n)
    dq.push_back(0);
    dq.push_back(9);
    dq.push_back(5);
    dq.push_back(-10);
    dq.push_back(-4); // dq = {1, -5, 150, 4, 9, 0, 9, 5, -10, -4}

    // .pop_back() --> remove um elemento do final da fila
    // O(1)
    dq.pop_back();
    dq.pop_back(); // dq = {1, -5, 150, 4, 9, 0, 9, 5}
    
    // .pop_front() --> remove um elemento do começo da fila
    // O(1)
    dq.pop_front();
    dq.pop_front(); // dq = {150, 4, 9, 0, 9, 5}
    
    // .size() --> retorna o número de elementos do deque
    // O(n)
    cout << "O deque 'dq' possui " << dq.size() << " elementos." << endl;
    
    // .back() --> acessa o último elemento do deque
    cout << "O ulitmo elemento do deque 'dq' e " << dq.back() << "." << endl;

    // .front() --> acessa o primeiro elemento do deque
    cout << "O primeiro elemento do deque 'dq' e " << dq.front() << "." << endl;

    // também podemos acessar aos elementos assim como em vetores
    // assim como podemos mudar seus valores
    dq[1] = 55;
    // .at() --> define um novo valor para uma posição específica
    dq.at(2) = -1;

    cout << "O segundo elemento do deque 'dq' e " << *(dq.begin()+1) << "." << endl;
    cout << "O terceiro elemento do deque 'dq' e " << dq[2] << "." << endl;

    // percorrendo um deque
    // .begin() --> poteiro para o começo do deque
    // .end() --> ponteiro para o final do deque
    cout << "Os elementos do deque 'dq' sao:";
    deque <int> ::iterator dii;
    for (dii = dq.begin(); dii != dq.end(); dii++) {
        cout << " " << *dii;
    }
    cout << "." << endl;
    
    // .clear() --> remove todos os elementos do deque
    // O(n)
    dq.clear();

    // .empty() --> booleano que verifica se o deque está vazio
    if (dq.empty()) {cout << "O deque 'dq' esta vazio." << endl;}
    else {cout << "O deque 'dq' nao esta vazio." << endl;}
    cout << endl;

    deque <int> d1(3, 5); // d1 = {5, 5, 5}
    // .resize() --> modifica o tamanho do deque completando com elementos específicos
    // funciona do mesmo jeito que em vector
    d1.resize(2); // d1 = {5, 5}
    d1.resize(5, 3); // d1 = {5, 5, 3, 3, 3}
    
    // .insert() --> adiciona um elemento específico numa posição específica
    d1.insert(d1.begin() + 1, 4); // d1 = {5, 4, 5, 3, 3, 3}
    d1.insert(d1.begin(), 2); // d1 = {2, 5, 4, 5, 3, 3, 3}
    
    cout << "d1 = {";
    for (dii = d1.begin(); dii != d1.end(); dii++) {cout << *dii << " ";}
    cout << "}" << endl;

    // inserindo x elementos iguais
    // estrutura: d.insert(início, final, valor)
    deque <int> d2(4, 10);
    d2.insert(d2.begin() + 1, 2, -7); // à partir da posição 1, coloque duas vezes o -7
    // d2 = {10, -7, -7, 10, 10, 10}
    d2.insert(d2.end(), {1, 2, 3}); // d2 = {10, -7, -7, 10, 10, 10, 1, 2, 3}
    d2.insert(d2.begin(), 1); // d2 = {1, 10, -7, -7, 10, 10, 10, 1, 2, 3}
    cout << "d2 = ";
    fprint_deque(d2);
    cout << endl;

    // também podemos adicionar um conjunto de elementos para o deque usando o .insert()
    // estrutura: d.insert((início, final), início, final)
    // [pelo menos um entre (i1, f1) tem que ser ponteiro que indique o deque]
    // resultado:
    // inicialmente d1 = {v1, v2, v3, v4, v5, v6, v7} e d2 = {t1, t2, t3, t4}
    // d1.insert((d1.begin(), 2), d2.begin(), d2.end() - 1)
    // d1 = {t1, t2, v1, v2, v3, v4, v5, v6, v7, t3}
    d2.insert((d2.begin() + 1, d2.begin() + 4), d1.begin(), d1.end() - 2);
    // === d2.insert((d1.begin() + 1, 4), d1.begin(), d1.end());
    // d2 = {1, 10, -7, -7, *2, *5, *4, *5, *3, 10, 10, 10, 1, 2, 3} [*x --> elementos adicionados]

    cout << "d1 = {";
    for (int i : d1) {cout << i << " ";}
    cout << "}" << endl;

    cout << "d2 = {";
    print_deque(d2);
    cout << "}" << endl << endl;
    
    // .erase() --> elimina elementos em um certo intervalo de um deque
    d2.erase(d2.begin()); // d2 = {10, -7, -7, 2, 5, 4, 5, 3, 10, 10, 10, 1, 2, 3}
    d2.erase(d2.begin() + 2, d2.begin() + 7); // d2 = {10, -7, 3, 10, 10, 10, 1, 2, 3}
    for (dii = d2.begin(); dii != d2.end(); dii++) {if (*dii%2 == 0) {d2.erase(dii);}} // elimina todos os nº pares
    // foi necessário o uso do iterator para que pudéssemos remover com erase, que pede ponteiro para as posições
    // d2 = {-7, 3, 1, 3}
    cout << "d2 = ";
    fprint_deque(d2);
}