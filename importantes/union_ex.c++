#include <bits/stdc++.h>
using namespace std;

// Gincana (OBI 2011)
// link: https://neps.academy/br/exercise/309

#define maxn 1010

int pai[maxn], peso[maxn];
set <int> pais;

int find(int x) {
    if (pai[x] == x) {return x;}
    else {return pai[x] = find(pai[x]);}
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (peso[x] < peso[y]) {pai[x] = y; pais.erase(x);}
        else if (peso[x] > peso[y]) {pai[y] = x; pais.erase(y);}
        else {pai[x] = y; peso[y]++; pais.erase(x);}
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int x = 1; x <= n; x++) {pai[x] = x; pais.insert(x);}
    for (int x = 0; x < m; x++) {int i, j; cin >> i >> j; join(i, j);}
    
    cout << (int)pais.size();
}