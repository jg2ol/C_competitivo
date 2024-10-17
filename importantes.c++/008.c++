#include <bits/stdc++.h>
using namespace std;

// Função que calcula quantos grupos de valores menores ou iguais a k existem dentro de n (dividindo n em duas partes iguais)
int emp(int n, int k, int q = 1) {
    while (k < n) {
        if (n%2 == 0) {q *= 2; return emp(n/2, k, q);}
        else {return emp(n/2+1, k, q) + emp(n/2, k, q);}
    }
    return q;
}

int main() {
    while (true) {
        int n, k;
        cin >> n >> k;
        if (n == 0) {break;}
        cout << emp(n, k) << endl;
    }
}