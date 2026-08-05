#include <bits/stdc++.h>
using namespace std;

// 10946 - You want what filled?
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1887
// contagem de quantidade de células nas componentes conexas e ordenação específica com pair's

#define maxn 55
string mapa[maxn];
int comp[maxn][maxn];
bool visitado[maxn][maxn];
pair<int, char> buracos[maxn*maxn];
int n, m, problem = 1, cc, bc;

bool compara(pair<int, char> a, pair<int, char> b) {
    if (a.first != b.first) {return a.first < b.first;}
    return a.second > b.second;
}

int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};
void dfs(int i, int j) {
    visitado[i][j] = true;
    for (int x = 0; x < 4; x++) {
        int I = i + di[x], J = j + dj[x];
        if (I >= 0 && I < n && J >= 0 && J < m) {
            if (mapa[I][J] == mapa[i][j] && !visitado[I][J]) {
                buracos[comp[i][j]].first++;
                comp[I][J] = comp[i][j];
                dfs(I, J);
            }
        }
    }
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 || m == 0) {break;}
        for (int i = 0; i < n; i++) {
            cin >> mapa[i];
            for (int j = 0; j < m; j++) {
                visitado[i][j] = false;
                buracos[n*(i+1)+(j+1)].first = 0;
                comp[i][j] = -1;
            }
        }
        cc = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mapa[i][j] != '.' && !visitado[i][j]) {
                    cc++;
                    comp[i][j] = cc;
                    buracos[cc] = {1, mapa[i][j]};
                    dfs(i, j);
                }
            }
        }
        sort(buracos+1, buracos+(cc+1), compara);
        cout << "Problem " << problem++ << ":\n";
        for (int x = 1; x <= cc; x++) {
            cout << buracos[x].second << " " << buracos[x].first << "\n";
        }
    }
}