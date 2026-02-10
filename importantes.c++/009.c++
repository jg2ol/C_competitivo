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
                    cout << n*i + j + 1;
                    if (j != n-1) {cout << " ";}
                }
                if (i != n-1) {cout << "\n";}
            }
        } else {
            int k = n/2;
            for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < n-1; j++) {
                    cout << 3*k*i + j + 1 << " ";
                }
                cout << 3*k*(i+1) << "\n";
            }
            int x = 3*k*(n-1)+1;
            int aux = n-1 + 3*k*(k-1)*(2*k-1);
            while(true) {
                if ((aux+x) % n == 0 && (aux + x)/n % (3*k) == 1) {break;}
                x++;
            }
            for (int i = 0; i < n-1; i++) {
                cout << x + i << " ";
            }
            cout << x + n-2 + k+1;
        }
    }
}