#include <bits/stdc++.h>
using namespace std;
// Minqueue - Complexidade O(1) amortizada

// Minqueue --> deque ordenado de pair's de inteiros, valor-tempo
// A Minqueue pode facilmente ser adaptada para Maxqueue, respondendo
// o valor máximo na estrutura

struct Minqueue {
    deque <pair <int, int>> d;
    // l --> tempo em que o elemento da frente foi adicionado, mesmo se já tiver sido removido
    int l, r;

    void init(void) {
        l = r = 1;
        d.clear();
    }

    // Adiciona um elemento no final da fila
    void push(int v) {
        while (!d.empty() and d.back().first > v) {d.pop_back();}
        d.push_back({v, r});
        r++;
    }

    // Remove o elemento da frente da fila em O(1)
    void pop() {
        if (!d.empty() and d.front().second == l) {d.pop_front();}
        l++;
    }

    // Retorna o menor elemento da fila em O(1)
    int getmin(void) {return d.front().first;}
};

int main() {
    
}