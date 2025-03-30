#include <bits/stdc++.h>
using namespace std;

// priority_queue --> fila de prioridade, é uma fila (queue) com ordem crescente
// ou seja, no topo fica o maior elemento da priority_queue
// possui diversas semelhanças com a queue

int main() {
    // declaração de uma priority
    // estrutura: priority_queue <tipo> nome; --> cria uma fila de prioridade de um certo tipo
    priority_queue <int> fila1;
    
    // .push() --> inserção de elementos
    // O(log n)
    fila1.push(1);
    fila1.push(0);
    fila1.push(3);
    fila1.push(2);
    
    // .top() --> acessando topo
    // O(log n)
    cout << "O topo de fila1 e " << fila1.top() << endl;
    // fila1 = {0, 1, 2, 3}

    // .pop() --> deletando elementos
    // O(log n)
    fila1.pop(); // elimina o 3
    fila1.pop(); // elimina o 2
    cout << "Agora, o topo de fila1 e " << fila1.top() << endl;
    
    // .size() --> retorna a quantidade de elementos na fila de prioridade
    // O(log n)
    cout << "A fila1 tem " << fila1.size() << " elementos."<< endl << endl;

    // podemos modificar uma priority_queue fazendo ela se organizar em ordem decrescente
    // ou seja, o elemento do topo sendo o de menor valor
    // estrutura: priority_queue <tipo, vector <tipo>, greater <tipo>> nome; --> todos os três devem ter o mesmo tipo
    priority_queue <int, vector <int>, greater <int>> fila2; // crio uma priority_queue com ordem decrescente
    fila2.push(2);
    fila2.push(-1);
    fila2.push(1);
    fila2.push(5);
    fila2.push(4);
    cout << "O elemento do topo de fila2 e " << fila2.top() << endl;
    fila2.pop();
    fila2.pop();
    cout << "Agora, o elemento do topo de fila2 e " << fila2.top() << endl;
    cout << "A fila2 tem " << fila2.size() << " elementos.";
}