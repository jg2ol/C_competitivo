#include <bits/stdc++.h>
using namespace std;

// https://neps.academy/br/exercise/535
// Saída Errada

#define maxn 205
int n, m, x, y, k;
int q[maxn][maxn], pintados;
vector <pair <int, int>> vizinhos[maxn*maxn];

void pinta(int i, int j) {q[i][j] = 1; pintados++;}
void dfs(int i, int j) {
    for (pair <int, int> p : vizinhos[(i-1)*m+j]) {
        int vx = p.first, vy = p.second;
        if (q[vx][vy] == 0) {pinta(vx, vy); dfs(vx, vy);}
    }
}

int main() {
    cin >> n >> m >> x >> y >> k;

    for (int x = 0; x <= n+1; x++) {q[x][0] = 1; q[x][m+1] = 1;}
    for (int x = 0; x <= m+1; x++) {q[0][x] = 1; q[n+1][x] = 1;}
    for (int i = 1; i <= n; i++) {for (int j = 1; j <= m; j++) {
        vizinhos[(i-1)*m + j].push_back({i-1, j-1});
        vizinhos[(i-1)*m + j].push_back({i-1, j});
        vizinhos[(i-1)*m + j].push_back({i-1, j+1});
        vizinhos[(i-1)*m + j].push_back({i, j-1});
        vizinhos[(i-1)*m + j].push_back({i, j+1});
        vizinhos[(i-1)*m + j].push_back({i+1, j-1});
        vizinhos[(i-1)*m + j].push_back({i+1, j});
        vizinhos[(i-1)*m + j].push_back({i+1, j+1});
    }}
    
    for (int x = 0; x < k; x++) {
        int a, b;
        cin >> a >> b;
        q[a][b] = 1;
    }
    
    dfs(x, y);
    cout << pintados;
}