#include <bits/stdc++.h>
using namespace std;

#define maxn 1005
int n, d, comp[maxn], qtd_comp;
vector <pair <int, int>> arvores;

void dfs(int i, int j) {
    for (int k = 1; k <= n; k++) {
        int x = arvores[k].first, y = arvores[k].second;
        if (x != i and y != j) {
            double dist = pow(pow(i-x, 2) + pow(j-y, 2), 0.5);
            if (dist <= d and comp[x] == -1) {
                comp[k] = qtd_comp;
                dfs(x, y);
            }
        }
    }
}

int main() {
    cin >> n >> d;

    for (int x = 1; x <= n; x++) {
        comp[x] = -1;
        int a, b;
        cin >> a >> b;
        arvores.push_back({a, b});
    }

    for (int x = 1; x <= n; x++) {
        if (comp[x] == -1) {
            qtd_comp++; comp[x] = qtd_comp;
            if (qtd_comp > 1) {break;}
            int xi = arvores[x].first, yi = arvores[x].second;
            dfs(xi, yi);
        }
    }

    if (qtd_comp == 1) {cout << "S\n";}
    else {cout << "N\n";}
    cout << qtd_comp;
}

#include <bits/stdc++.h>
using namespace std;

int componente[100100], qtd_comp;
vector <int> vizinhos[100100];

void dfs(int x) {
    for (int i = 0; i < (int)vizinhos[x].size(); i++) {
        int v = vizinhos[x][i];
        if (componente[v] == -1) {componente[v] = qtd_comp; dfs(v);}
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int x = 1; x <= n; x++) {componente[x] = -1;}
    for (int x = 0; x < m; x++) {
        int i, j;
        cin >> i >> j;
        vizinhos[i].push_back(j);
        vizinhos[j].push_back(i);
    }
    for (int x = 1; x <= n; x++) {
        if (componente[x] == -1) {qtd_comp++; componente[x] = qtd_comp; dfs(x);}
    }
    cout << qtd_comp;
}