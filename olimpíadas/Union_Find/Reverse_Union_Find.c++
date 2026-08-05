#include <bits/stdc++.h>
using namespace std;

// Union Find "de trás pra frente"
// problema base: a partir de um grafo inicial, remover arestas dele e dizer no final de tudo
// qual o número de componentes conexas do grafo a cada remoção

#define maxn 10010
// n:: número de vértices do grafo; m:: número de arestas do grafo inicial; q:: número de arestas removidas
int n, m, q, cc;
int pai[maxn], peso[maxn];

// edge[i] --> aresta de índice i
pair <int, int> edge[maxn];
// removida[i] --> índice da i-ésima aresta removida
// ans[i] --> resposta após a i-ésima aresta ser removida
int removida[maxn], ans[maxn];
// fora[i] --> índice da i-ésima aresta que foi removida
bool fora[maxn];

int find(int x) {
    if (pai[x] == x) {return x;}
    else {return pai[x] = find(pai[x]);}
}

void join(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) {return;}

    if (peso[x] > peso[y]) {pai[y] = x;}
    else if (peso[x] < peso[y]) {pai[x] = y;}
    else {pai[y] = x; peso[x]++;}
    cc--;
}

int main() {
    cin >> n >> m >> q;
    
    // inicializando o union find
    cc += n;
    for (int x = 1; x <= n; x++) {pai[x] = x; peso[x] = 1;}
    
    // lendo as arestas e guardando o índice das mesmas
    for (int x = 1; x <= m; x++) {
        int i, j;
        cin >> i >> j;
        edge[x] = {i, j};
    }

    // lendo o índice da i-ésima aresta removida
    for (int x = 1; x <= q; x++) {
        int E;
        cin >> E;
        // guardo o índice da x-ésima aresta removida e digo que ela está fora do grafo final
        removida[x] = E;
        fora[E] = true;
    }

    // faço o grafo final
    for (int i = 1; i <= m; i++) {
        if (!fora[i]) {join(edge[i].first, edge[i].second);}
    }
    ans[q] = cc; // esta já é a última resposta do problema

    // p/ cada aresta removida coloquemos ela de volta e guardamos a resposta
    for (int x = q; x > 1; x--) {
        join(edge[removida[x]].first, edge[removida[x]].second);
        ans[x-1] = cc;
    }

    // expondo as respostas na ordem correta
    for (int x = 1; x <= q; x++) {cout << ans[x] << "\n";}
}