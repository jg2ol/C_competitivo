#include <bits/stdc++.h>
using namespace std;

int lista[1010];

int main() {
    // ordena um vetor de inteiros em ordem crescente
    int n;
    cin >> n;  // n <= 1000
    bool ordenado = false;
    int numeros[n];
    for (int x = 0; x < n; x++) {cin >> numeros[x];}

    while (!ordenado) {
        ordenado = true;
        for (int i = 0; i < n-1; i++) {
            if (numeros[i] > numeros[i+1]) {
                int temp = numeros[i];
                numeros[i] = numeros[i+1];
                numeros[i+1] = temp;
                ordenado = false;
            }
        }
    }
    for (int x = 0; x < n; x++) {cout << numeros[x] << " ";}
}