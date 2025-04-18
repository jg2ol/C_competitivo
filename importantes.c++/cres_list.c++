#include <bits/stdc++.h>
using namespace std;

int lista[1010];

int main() {
    // imprime uma lista de números em ordem crescente
    int n;
    cin >> n;
    int numeros[n];
    for (int x = 0; x < n; x++) {cin >> numeros[x];}
    
    for (int x = 0; x < n; x++) {
        int menor = numeros[0], ind_menor = 0;
        for (int i = 0; i < n; i++) {
            if (numeros[i] < menor and lista[i] == 0) {menor = numeros[i]; ind_menor = i;}
        }
        cout << menor << " ";
        lista[ind_menor] = 1;
    }
}