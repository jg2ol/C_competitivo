#include <bits/stdc++.h>
using namespace std;

// código que rotaciona qualquer matriz M x N em 90°, 180° e 270°

#define REP(i, a) for (int i = a; i >= 0; i--)

int main() {
    int n, m, g;
    cin >> n >> m;
    
    int matriz[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matriz[i][j];
        }
    }
    
    cin >> g;
    if (g == 90) {
        for (int i = 0; i < m; i++) {
            for (int j = n-1; j >= 0; j--) {cout << matriz[j][i] << " ";}
            cout << "\n";
        }
    } else if (g == 180) {
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {cout << matriz[i][j] << " ";}
            cout << "\n";
        }
    } else {
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {swap(matriz[n-1-i][m-1-j], matriz[i][j]);}
        }
        REP(i, m-1) {
            for (int j = 0; j < n; j++) {cout << matriz[j][i] << " ";}
            cout << "\n";
        }
    }
}