#include <bits/stdc++.h>
using namespace std;

// Calculando números binomiais em módulo p [p primo geralmente igual a 10**9 + 7] de forma eficiente

#define maxn 1000010
#define int long long // definimos "int" na verdade como "long long"
int p = 1e9 + 7; // quase sempre: int p = 1e9 + 7;
int n;

// p/ maximizar a eficiência, guardamos os fatoriais num vetor p/ reciclarmos
int fat[maxn];
int fatorial(int n) {
    if (fat[n] != 0) {return fat[n];}

    if (n == 0) {return fat[0] = 1;}
    else {return fat[n] = (n*fatorial(n-1)) % p;}
}

// como (n, k) = n!/(k! * (n-k)!) ["n escolhe k"], então temos que calcular n!*(k!)^(-1)*((n-k)!)^(-1) mod p
// pelo pequeno teorema de Fermat: (n, k) === n!*(k!)^(p-2)*((n-k)!)^(p-2) [congruência]
// que conseguimos calcular em O(log p) utilizando a Exponenciação Rápida
int Exp(int x, int n) {
    if (n == 0) {return 1;}

    int t = Exp(x, n/2) % p;
    if (n % 2 == 0) {return (t*t) % p;}
    else {return x*(t*t % p) % p;}
}

// por fim, o número binomial
int binomial(int n, int k) {
    // n escolhe k módulo p
    return ((fatorial(n)*Exp(fatorial(k), p-2)) % p) * Exp(fatorial(n-k), p-2) % p;
}

// como "int" está definido como "long long", utilizamos outro tipo de inteiro p/ a função main
// sem que tenhamos prejuízos de valores
int32_t main() {
    cin >> n;
    for (int x = 0; x <= n; x++) {cout << fatorial(x) << " ";}
    cout << "\n";
    for (int x = 0; x <= n; x++) {cout << binomial(n, x) << " ";}
}