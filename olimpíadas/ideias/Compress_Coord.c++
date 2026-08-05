#include <bits/stdc++.h>
using namespace std;

// Problema base: em um vetor inicialmente zerado, são dados M posições em ordem que serão atualizadas (ordenadamente).
// Após isso, K perguntas serão feitas, pedindo a soma dos valores do intervalo [l, r], inclusive.
// N <= 10**9; M, K <= 10**5 [note que terá muitos valores iguais a zero mesmo depois das atualizações]

#define maxn 100010
int n, m, k;
// int v[n] não precisa nem deve existir, pelo seu custo altíssimo
int soma[maxn]; // soma[i] --> v[1] + v[2] + ... + v[i]

int main() {
    cin >> n >> m >> k;

    vector <pair <int, int>> aux; // 0-indexado e ordenado pelo próprio input
    for (int x = 1; x <= m; x++) {
        int pos, valor;
        cin >> pos >> valor;
        aux.push_back({pos, valor});
    }

    soma[0] = 0;
    for (int x = 1; x <= n; x++) {soma[x] = soma[x-1] + aux[x-1].second;} // soma de prefixos
    
    for (int x = 1; x <= k; x++) {
        int l, r;
        cin >> l >> r;

        int a = (int)(lower_bound(aux.begin(), aux.end(), make_pair(l, 0)) - aux.begin());
        int b = (int)(lower_bound(aux.begin(), aux.end(), make_pair(r+1, 0)) - aux.begin() - 1);
        // como o vetor aux é 0-indexado, precisamos ajustar a e b
        a++; b++;

        if (a > b) {cout << "0\n";}
        else {cout << soma[b] - soma[a-1] << "\n";}
    }
}