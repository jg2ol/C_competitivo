#include <bits/stdc++.h>
using namespace std;

// Min queue / deque --> estrutura semelhante à queue, porém em ordem crescente
// a estrutura guarda um par de valores: o valor do elemento e o tempo em que foi adicionado

// int main() {
//     // declaração, estrutura: deq <pair <tipo1, tipo2>> nome;
//     deque <pair <int, int>> lista;

//     // .push() --> adiciona elementos no final da fila
//     lista.push(1);
//     lista.push(0);
//     lista.push(3);
//     lista.push(4);

//     // .pop() --> remove o último elemento da fila
// }

// struct MinQueue {
// 	deque <pair <int, int>> dq;
// 	int l, r;

// 	// inicialmente, dizemos que l = r = 1
// 	void init(void) {
// 		l = r = 1;
// 		dq.clear();
// 	}

// 	// adiciona v atrás da fila
// 	void push(int v) {
// 		while (!dq.empty() && v < dq.back().ff) {dq.pop_back()};

// 		dq.push({v, r}); // inserimos v com tempo r
// 		r++; // aumentamos o tempo r
// 	}

// 	// remove o elemento da frente da fila
// 	void pop(void) {
// 		if (!dq.empty() && dq.front().ss == l) {dq.pop_front()};
// 		l++; //aumentamos o tempo l
// 	}

// 	int getmin(void) {return dq.front().ff;} // retorna o valor mínimo da estrutura
// };