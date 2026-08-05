#include <bits/stdc++.h>
using namespace std;


int main() {
    // matriz de adjacências
    // Toupeira
    // link: https://neps.academy/br/exercise/2323
    int s, t, cont = 0;
    cin >> s >> t;
    int matriz[s+10][s+10]; // --> cria um vetor com vetores dentro dele
    for (int x = 0; x < t; x++) {
        int i, j;
        cin >> i >> j;
        matriz[i][j] = 1;
        matriz[j][i] = 1;
    }
    
    int p;
    cin >> p;
    for (int x = 0; x < p; x++) {
        int i;
        cin >> i;
        
        int caminho[i];
        for (int y = 0; y < i; y++) {cin >> caminho[y];}

        for (int y = 1; y < i; y++) {
            if (matriz[caminho[y-1]][caminho[y]] != 1) {break;}
            else if (y == i-1) {cont++;}
        }
    }
    cout << cont;
}