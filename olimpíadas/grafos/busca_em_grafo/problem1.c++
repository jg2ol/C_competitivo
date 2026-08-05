#include <bits/stdc++.h>
using namespace std;

// Problema: 657 - The die is cast
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=598
// resolvido com double flood fill

#define maxn 55
int mapa[maxn][maxn], comp[maxn][maxn], alvos[maxn*maxn];
int n, m, lance = 1, cc, dc;

int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};
void dfs_dardo(int i, int j) {
    mapa[i][j] = 1;
    for (int x = 0; x < 4; x++) {
        int I = i + di[x], J = j + dj[x];
        if (I >= 0 && I < n && J >= 0 && J < m) {
            if (mapa[I][J] == 2) {dfs_dardo(I, J);}
        }
    }
}

void dfs(int i, int j) {
    if (mapa[i][j] == 2) {
        dc++;
        dfs_dardo(i, j);
    }
    mapa[i][j] = 0;
    for (int x = 0; x < 4; x++) {
        int I = i + di[x], J = j + dj[x];
        if (I >= 0 && I < n && J >= 0 && J < m) {
            if (mapa[I][J] > 0) {dfs(I, J);}
        }
    }
}

int main() {
    while (true) {
        cin >> m >> n;
        if (n == 0 || m == 0) {break;}
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == '.') {mapa[i][j] = 0;}
                else if (s[j] == '*') {mapa[i][j] = 1;}
                else {mapa[i][j] = 2;}
                comp[i][j] = 0;
                alvos[n*(i+1)+(j+1)] = 0;
            }
        }
        cc = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mapa[i][j] > 0) {
                    cc++; dc = 0;
                    dfs(i, j);
                    alvos[cc] = dc;
                }
            }
        }
        sort(alvos+1, alvos+(cc+1));
        cout << "Throw " << lance++ << "\n";
        for (int x = 1; x <= cc; x++) {
            cout << alvos[x] << (x == cc ? "" : " ");
        } cout << "\n\n";
    }
}