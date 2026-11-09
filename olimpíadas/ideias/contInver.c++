#include <bits/stdc++.h>
using namespace std;

// Contagem de inversões com Merge Sort + Ordenação
// O(nlog n)

#define maxn 100100
typedef long long int lli;
int n, v[maxn], copia[maxn], aux[maxn];

lli inv(int ini, int fim) {
    if (ini == fim) {return 0;}

    lli cont = inv(ini, (ini+fim)/2) + inv((ini+fim)/2+1, fim);
    int tam = 0, j = (ini+fim)/2+1;

    for (int i = ini; i <= (ini+fim)/2; i++) {
        while (j <= fim && copia[j] < copia[i]) {
            aux[tam] = copia[j];
            cont += (ini+fim)/2-i+1;
            tam++; j++;
        }
        aux[tam] = copia[i];
        tam++;
    }
    while (j <= fim) {
        aux[tam] = copia[j];
        tam++; j++;
    }
    for (int x = ini; x <= fim; x++) {copia[x] = aux[x-ini];}
    return cont;
}

int main() {
    cin >> n;
    for (int x = 1; x <= n; x++) {cin >> v[x]; copia[x] = v[x];}
    cout << inv(1, n) << "\n";
    for (int x = 1; x <= n; x++) {cout << v[x] << " ";} cout << "\n";
    for (int x = 1; x <= n; x++) {cout << copia[x] << " ";} cout << "\n";
}
