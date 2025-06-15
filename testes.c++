#include <bits/stdc++.h>
using namespace std;

// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=513
#define maxn 105
int n, m, cc;
char mapa[maxn][maxn];
int comp[maxn][maxn];

int di[8] = {0, 0, -1, 1, -1, 1, -1, 1}, dj[8] = {-1, 1, 0, 0, 1, -1, -1, 1};
void dfs(int i, int j) {
    for (int k = 0; k < 8; k++) {
        int vizi = i + di[k], vizj = j + dj[k];
        if (vizi <= 0 or vizi > n or vizj <= 0 or vizj > n) {continue;}

        if (mapa[vizi][vizj] == '@' and comp[vizi][vizj] == -1) {comp[vizi][vizj] = comp[i][j]; dfs(vizi, vizj);}
    }
}

int main() {
    while (true) {
        cin >> n >> m;
        cc = 0;
        if (n == 0 and m == 0) {break;}

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                comp[i][j] = -1;
                cin >> mapa[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mapa[i][j] == '@' and comp[i][j] == -1) {cc++; comp[i][j] = cc; dfs(i, j);}
            }
        }

        cout << cc << "\n";
    }
}