#include <bits/stdc++.h>
using namespace std;

// Mina
// https://neps.academy/br/exercise/65
// exemplo básico de dijkstra em grid
// também é possível fazer em 1D traduzindo {i, j} p/ n*i + j
// p/ visualização em 1D, olhar minhas submissões do problema no link acima

// {peso, {i, j}}
typedef pair<int, pair<int, int>> piii;
const int inf = 1e9+10;
#define maxn 105
int n;
// como já sabemos quem são os vizinhos de um vértice, declaramos grafo[maxn][maxn]
int dist[maxn][maxn], grafo[maxn][maxn];
bool mark[maxn][maxn];

// truque didj
int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};
void dijkstra(int i, int j) {
    for (int x = 0; x < n; x++) {for (int y = 0; y < n; y++) {dist[x][y] = inf;}}
    dist[i][j] = 0;
    priority_queue<piii, vector<piii>, greater<piii>> fila;
    fila.push({0, {i, j}});
    while (!fila.empty()) {
        auto u = fila.top().second;
        fila.pop();
        int ui = u.first, uj = u.second;
        if (mark[ui][uj]) {continue;}
        mark[ui][uj] = true;
        for (int x = 0; x < 4; x++) {
            int vi = ui + di[x], vj = uj + dj[x];
            if (vi >= 0 && vi < n && vj >= 0 && vj < n) {
                int peso = grafo[vi][vj];
                if (dist[vi][vj] > dist[ui][uj] + peso) {
                    dist[vi][vj] = dist[ui][uj] + peso;
                    fila.push({dist[vi][vj], {vi, vj}});
                }
            }
        }
    }
}

int main() {
    cin >> n;
    // atenção com a abordagem do problema e com a entrada dos valores
    for (int i = 0; i < n; i++) {for (int j = 0; j < n; j++) {cin >> grafo[i][j];}}
    dijkstra(0, 0);
    cout << dist[n-1][n-1] << "\n";
}
