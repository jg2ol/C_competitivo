#include <bits/stdc++.h>
using namespace std;

#define maxn 100100
int n, v[maxn], aux[maxn];

// Função que ordena o vetor v no intervalo [ini, fim] (inclusive)
void merge_sort(int ini, int fim) {
    if (ini == fim) {return;}
    merge_sort(ini, (ini+fim)/2);
    merge_sort((ini+fim)/2+1, fim);

    int tam = 0, j = (ini+fim)/2+1;
    for (int i = ini; i <= (ini+fim)/2; i++) {
        while (j <= fim && v[j] < v[i]) {
            aux[tam] = v[j];
            tam++;
            j++;
        }
        aux[tam] = v[i];
        tam++;
    }
    while (j <= fim) {
        aux[tam] = v[j];
        tam++;
        j++;
    }
    for (int x = ini; x <= fim; x++) {v[x] = aux[x-ini];}
}

int main() {
    cin >> n;
    for (int x = 1; x <= n; x++) {cin >> v[x];}
    merge_sort(1, n);
    for (int x = 1; x <= n; x++) {cout << v[x] << " ";}
}
