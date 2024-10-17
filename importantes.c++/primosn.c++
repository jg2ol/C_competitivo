#include <bits/stdc++.h>
using namespace std;

// Função que retorna true se n for primo, caso contrário, retorna false
bool primosn(int n) {
    if (n < 0) {n *= -1;}
    if (n == 1 or n == 0) {return false;}

    int qdiv = 1;
    for (int i = 2; i <= sqrt(n); i++) {if (n%i == 0) {qdiv++;}}

    if (qdiv == 1) {return true;}
    return false;
}

int main() {
    int i, f, cont = 0;
    cout << "Inicio: "; cin >> i;
    cout << "Fim: "; cin >> f;

    for (int x = i; x <= f; x++) {if (primosn(x)) {cout << x << " "; cont++;}}
    cout << endl << "No intervalo de " << i << " ate " << f << " temos " << cont << " numeros primos." << endl;
}