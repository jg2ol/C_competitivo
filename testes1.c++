#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int inf = 1e7+10;
#define maxn 505
int n, m, s, d;
int dist[maxn];
bool mark[maxn];
vector<pii> grafo[maxn];

void dijkstra(int S) {
    for (int x = 0; x < n; x++) {dist[x] = inf;}
    dist[S] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0, S});
    while (!fila.empty()) {
        int u = fila.top().second;
        fila.pop();
        if (mark[u]) {continue;}
        mark[u] = true;
        for (auto V:grafo[u]) {
            int peso = V.first, v = V.second;
            if (dist[v] > dist[u]+peso) {dist[v] = dist[u]+peso; fila.push({dist[v], v});}
        }
    }
}

// ideia atual: dijkstra duplo ou em maxn
// calcular o menor caminho e depois calcular o "segundo" menor caminho, sem sobrepor com o menor caminho

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ((cin >> n >> m) && n&&m) {
        cin >> s >> d;
        for (int x = 0; x < n; x++) {grafo[x].clear();}
        for (int x = 0; x < m; x++) {
            int u, v, p;
            cin >> u >> v >> p;
            grafo[u].push_back({p, v});
        }
        dijkstra(s);
        cout << dist[d] << "\n";
    }
}
