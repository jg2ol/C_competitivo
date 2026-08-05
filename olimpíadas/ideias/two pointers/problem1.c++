#include <bits/stdc++.h>
using namespace std;

// Cities Robbery
// https://csacademy.com/contest/archive/task/cities-robbery/statement/
// ligação entre two pointers e prefix sums

typedef long long ll;
struct cidade {ll dist, din;};
int n;
ll X, k, max_din;
vector<cidade> esq, dir;

bool comparaCidade(cidade a, cidade b) {return a.dist < b.dist;}

int main() {
    cin >> n >> X >> k;
    for (int x = 0; x < n; ++x) {
        ll pos, valor;
        cin >> pos >> valor;
        // cidades à esquerda de X
        if (pos < X) {esq.push_back({X-pos, valor});}
        // cidades à direita de X
        else {dir.push_back({pos-X, valor});}
    }
    // ordeno as cidades pela distância até o veículo p/ poder usar BS mais a frente
    sort(esq.begin(), esq.end(), comparaCidade);
    sort(dir.begin(), dir.end(), comparaCidade);
    int esq_len = esq.size(), dir_len = dir.size();
    // somas de prefixo p/ o dinheiro roubado
    vector<ll> pref_esq(esq_len+1, 0), pref_dir(dir_len+1, 0);
    for (int x = 0; x < esq_len; ++x) {pref_esq[x+1] = pref_esq[x] + esq[x].din;}
    for (int x = 0; x < dir_len; ++x) {pref_dir[x+1] = pref_dir[x] + dir[x].din;}
    // 1º Caso: ir p/ a esquerda e depois ir p/ a direita
    for (int x = 0; x <= esq_len; ++x) {
        ll dist_esq;
        if (x == 0) {dist_esq = 0;}
        else {dist_esq = esq[x-1].dist;}
        if (dist_esq <= k) {
            max_din = max(max_din, pref_esq[x]);
            if (2*dist_esq <= k) {
                ll sobra = k-2*dist_esq;
                int ini = 1, fim = dir_len, ultimo = 0;
                // busca binária p/ encontrar até onde o veículo consegue ir
                while (ini <= fim) {
                    int m = ini + (fim-ini)/2;
                    if (dir[m-1].dist <= sobra) {ultimo = m; ini = m+1;}
                    else {fim = m-1;}
                }
                max_din = max(max_din, pref_esq[x] + pref_dir[ultimo]);
            }
        }
    }
    // 2º Caso: ir p/ a direita e depois ir p/ a esquerda
    for (int x = 0; x <= dir_len; ++x) {
        ll dist_dir;
        if (x == 0) {dist_dir = 0;}
        else {dist_dir = dir[x-1].dist;}
        if (dist_dir <= k) {
            max_din = max(max_din, pref_dir[x]);
            if (2*dist_dir <= k) {
                ll sobra = k-2*dist_dir;
                int ini = 1, fim = esq_len, ultimo = 0;
                while (ini <= fim) {
                    int m = ini + (fim-ini)/2;
                    if (esq[m-1].dist <= sobra) {ultimo = m; ini = m+1;}
                    else {fim = m-1;}
                }
                max_din = max(max_din, pref_dir[x] + pref_esq[ultimo]);
            }
        }
    }
    cout << max_din << "\n";
}
