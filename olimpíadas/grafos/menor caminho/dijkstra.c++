#include <bits/stdc++.h>
using namespace std;

// Caminho das Pontes [OBI - 2009 - f1]
// https://neps.academy/br/exercise/297
// problema básico
// dijkstra não funciona p/ grafos com pesos negativos

typedef pair<int, int> pii;
#define maxn 1005
const int inf = 1e9+10;
int n, m;
int dist[maxn]; // vetor das menores distâncias
bool mark[maxn];
vector<pii> grafo[maxn];

// algoritmo que calcula a menor distância a todos os vértices partindo de um vértice inicial
void dijkstra(int S) {
    for (int x = 0; x <= n+1; x++) {dist[x] = inf;}
    dist[S] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0, S});
    while (!fila.empty()) {
        int u = fila.top().second;
        fila.pop();
        if (mark[u]) {continue;}
        mark[u] = true;
        for (auto V : grafo[u]) {
            int buracos = V.first, v = V.second;
            if (dist[v] > dist[u] + buracos) {dist[v] = dist[u] + buracos; fila.push({dist[v], v});}
        }
    }
}

int main() {
    cin >> n >> m;
    for (int x = 1; x <= m; x++) {
        int s, t, b;
        cin >> s >> t >> b;
        grafo[s].push_back({b, t});
        grafo[t].push_back({b, s});
    }
    dijkstra(0);
    cout << dist[n+1];
}
