#include <bits/stdc++.h>
using namespace std;

int tab[1000][1000], somas[1000][1000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int valor;
            cin >> valor;
            tab[i][j] = valor;
            for (int x = 0; x < n; x++) {
                if (x != i) {somas[x][j] += valor;}
                if (x != j) {somas[i][x] += valor;}
            }
        }
    }

    int maior = 0;
    for (int i = 0; i < n; i++) {for (int j = 0; j < n; j++) {if (somas[i][j] > maior) {maior = somas[i][j];}}}
    cout << maior;
}