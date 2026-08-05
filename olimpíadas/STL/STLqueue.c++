#include <bits/stdc++.h>
using namespace std;

// queue --> uma fila, ou seja, podemos acessar/remover seu começo/final facilmente

int main() {
    // declaração
    // estrutura: queue <tipo> nome;
    queue <int> fila1;

    // .push() --> insere um elemento no final da fila
    fila1.push(10000);
    fila1.push(1);
    fila1.push(2);
    fila1.push(-5);

    // .pop() --> remove o elemento do começo da fila
    fila1.pop(); // remove o 10000

    // .front() --> acessa o elemento da frente da fila
    cout << "O elemento que esta na frente, na fila1 e " << fila1.front() << endl;

    // .back() --> acessa o último elemento da fila
    cout << "O último elemento de fila1 e " << fila1.back() << endl;

    // .size() --> retorna a quantidade de termos da fila
    cout << "A fila1 tem " << (int)fila1.size() << " elementos." << endl;

    // .empty() --> booleano que verifica se a fila está vazia
    if (fila1.empty()) {cout << "A fila1 esta vazia." << endl;}
    else {cout << "A fila1 nao esta vazia." << endl;}
}