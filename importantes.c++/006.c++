#include <bits/stdc++.h>
using namespace std;

// Jogo da Vida (OBI - 1ª Fase - 2024)
// link: https://neps.academy/br/exercise/2714
// Matrizes...
int n, q, matriz[55][55], mod[55][55];

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            if (s[j-1] == '1') {matriz[i][j] = 1;}
            else {matriz[i][j] = 0;}
        }
    }

    for (int Q = 1; Q <= q; Q++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int vizinhos_vivos = 0;
                
                vizinhos_vivos += matriz[i-1][j-1];
                vizinhos_vivos += matriz[i-1][j];
                vizinhos_vivos += matriz[i-1][j+1];
                vizinhos_vivos += matriz[i][j-1];
                vizinhos_vivos += matriz[i][j+1];
                vizinhos_vivos += matriz[i+1][j-1];
                vizinhos_vivos += matriz[i+1][j];
                vizinhos_vivos += matriz[i+1][j+1];

                if (matriz[i][j] == 0) {
                    if (vizinhos_vivos == 3) {mod[i][j] = 1;}
                    else {mod[i][j] = 0;}
                }
                else {
                    if (vizinhos_vivos == 2 or vizinhos_vivos == 3) {mod[i][j] = 1;}
                    else {mod[i][j] = 0;}
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {matriz[i][j] = mod[i][j];}
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {cout << matriz[i][j];}
        cout << "\n";
    }
}