#include <bits/stdc++.h>
using namespace std;

// Quadrado
// link: https://neps.academy/br/exercise/2174
// Resposta errada

int main() {
    int n;
    cin >> n;
    if (n == 1) {cout << 1;}
    else if (n == 2) {cout << -1;}
    else {
        if (n%2 == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << j+1 + n*i << " ";
                } cout << endl;
            }
        } else {
            int k = (n-1)/2;
            for (int i = 0; i < n-1; i++) {
                for (int j = 1; j < n; j++) {cout << j + i*3*(k+1) << " ";}
                cout << (i+1)*3*(k+1) << endl;
            }
            for (int j = 1; j < n; j++) {cout << j + 3*(k+1)*(n+1)*(n-2)/2 << " ";}
            cout << 3*(k+1)*n*(n-1)/2;
        }
    }
}