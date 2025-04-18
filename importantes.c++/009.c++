#include <bits/stdc++.h>
using namespace std;

// Quadrado
// link: https://neps.academy/br/exercise/2174
// análise numérica de médias aritméticas
// Resposta errada (??)

int main() {
    int n;
    cin >> n;
    if (n == 1) {cout << 1;}
    else if (n == 2) {cout << -1;}
    else {
        if (n%2 == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j != n-1) {cout << j+1 + n*i << " ";}
                    else {cout << j+1 + n*i;}
                }
                if (i != n-1) {cout << endl;}
            }
        } else {
            int k = n/2;
            for (int i = 0; i < n-1; i++) {
                for (int j = 1; j < n; j++) {long int v = j + i*3*k; cout << v << " ";}
                long int x = (i+1)*3*k;
                cout << x << endl;
            }
            for (int j = 1; j < n; j++) {long int v = j + 3*k*(n+1)*(n-2)/2; cout << v << " ";}
            long int y = 3*k*n*(n-1)/2;
            cout << y;
        }
    }
}