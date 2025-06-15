#include <bits/stdc++.h>
using namespace std;

// Componentes conexas em um grid M x N
// link:

#define maxn 1003
int n, m, cc;
int comp[maxn][maxn], mapa[maxn][maxn];

// int di[8] = {0, 0, -1, 1, 1, -1, -1, 1}, dj[8] = {-1, 1, 0, 0, 1, -1, 1, -1}; [p/ as 8 casas vizinhas]
// Truque didj (p/ 4 casas vizinhas)
int di[4] = {0, 0, -1, 1}, dj[4] = {-1, 1, 0, 0};
void dfs(int i, int j) {
    for (int k = 0; k < 4; k++) {
        int vizi = i + di[k];
        int vizj = j + dj[k];
        if (vizi <= 0 or vizi > n or vizj <= 0 or vizj > m) {continue;}

        if (mapa[vizi][vizj] == 1 and comp[vizi][vizj] == -1) {comp[vizi][vizj] = comp[i][j]; dfs(vizi, vizj);}
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            comp[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {cin >> mapa[i][j];}
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (comp[i][j] == -1 and mapa[i][j] == 1) {cc++; comp[i][j] = cc; dfs(i, j);}
        }
    }

    cout << cc << "\n";
}