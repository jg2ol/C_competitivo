#include <bits/stdc++.h>
using namespace std;

// stack --> um vetor que se comporta como uma pilha
// assim, só é possível acessar, tirar ou por o elemento de seu 'topo'

int main() {
    // declaração
    // estrutura: stack <tipo> nome;
    stack <int> pilha;

    // .push() --> insere um elemento no topo
    pilha.push(1);
    pilha.push(2);
    pilha.push(6);
    pilha.push(-5);

    // .top() --> acessa o elemento do topo
    cout << "O elemento do topo de 'pilha' e " << pilha.top() << endl;

    // .pop() --> remove o elemento do topo
    pilha.pop(); // agora o elemento de topo de 'pilha' é 6
    cout << "Agora, o elemento do topo de 'pilha' e " << pilha.top() << endl;

    // .size() --> retorna o tamanho da pilha
    cout << "A pilha tem " << pilha.size() << " elementos." << endl;

    // .empty() --> valor booleano que retorna true se a pilha estiver vazia e false caso contrário
    if (pilha.empty()) {cout << "A pilha esta vazia." << endl;}
    else {cout << "A pilha nao esta vazia." << endl;}
}