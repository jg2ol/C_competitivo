#include <bits/stdc++.h>
using namespace std;

// Família de troia (OBI)
// Problema: https://neps.academy/br/exercise/512
// pode ser resolvido por Union-Find contando-se o número de patriarcas
// porém, apresenta-se outra estratégia: DFS
// vamos contar quantas componentes conexas o grafo resultante do problema possui

// Cuidado com o valor de maxn
#define maxn 50050
int componente[maxn];
vector <int> vizinhos[maxn]; // vector de vetores-padrão com maxn posições em cada um

// Funcão recursiva que faz os vértices vizinhos (direta e indiretamente) de x serem uma componente só
void dfs(int x) {
    for (int i = 0; i < (int)vizinhos[x].size(); i++) {
        int v = vizinhos[x][i];
        if (componente[v] == -1) {componente[v] = componente[x]; dfs(v);}
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int x = 1; x <= n; x++) {componente[x] = -1;}
    for (int x = 0; x < m; x++) {
        int i, j;
        cin >> i >> j;
        // defino i e j como vértices vizinhos (aresta {i, j})
        vizinhos[i].push_back(j);
        vizinhos[j].push_back(i);
    }
    int qtd_comp = 0;
    for (int x = 1; x <= n; x++) {
        // faço a DFS em todos os vértices do grafo
        if (componente[x] == -1) {qtd_comp++; componente[x] = qtd_comp; dfs(x);}
    }
    cout << qtd_comp;
}