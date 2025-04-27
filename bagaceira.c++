#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int m[n][n], somas[2*n+2];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        somas[2*n] += m[i][i];
        somas[2*n+1] += m[i][n-1-i];
        for (int j = 0; j < n; j++) {
            somas[i] += m[i][j];
            somas[n-1+j] += m[i][j];
        }
    }

    for (int x = 0; x < 2*n+2; x++) {
        if (somas[x] != somas[0]) {cout << -1; break;}
        else {if (x == 2*n+1) {cout << somas[0];}}
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        } cout << "\n";
    } cout << "\n";
    for (int i : somas) {cout << i << " ";}
}