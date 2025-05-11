#include <bits/stdc++.h>
using namespace std;

int n, m, v[100100]; // 1-indexado e ordenado (entrada ordenada)

int buscabin(int x) {
    int i = 1, f = n, meio, ans = -1;
    while (i <= f) {
        meio = (i+f)/2;
        if (v[meio] >= x) {
            ans = v[meio]; // possível resposta
            f = meio-1;
        }
        else {i = meio+1;}
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int x = 1; x <= n; x++) {cin >> v[x];}
    for (int x = 1; x <= m; x++) {int valor; cin >> valor; cout << buscabin(valor);}
}