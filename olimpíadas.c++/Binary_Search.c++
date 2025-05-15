#include <bits/stdc++.h>
using namespace std;

// Material apenas TEÓRICO
// Teoria: num vetor, encontrar a menor solução de um problema
// em vez de percorrermos o vetor por completo, daremos saltos
// de tamanho recursivo tam = n; tam /= 2;
#define maxn 100100
int n, m;
vector <int> v;

// Função que verifica se o valor x é uma possível solução do problema
bool ok(int x) {
    // return (x é solução do problema)
    // se x for solução, return true, senão, return false
}

// Função que retorna diretamente a rsposta procurada
int buscab(int x) {
    int i = 0, f = n-1, m, ans = -1;
    while (i <= f) {
        m = (i+f)/2;
        // if (m é a solução) {ans = m;}
        // if (m é menor do que a solução) {i = m+1;}
        // if (m é maior do que a solução) {f = m-1;}
    }
    return ans; // outra maneira de retornar a resposta (answer) do problema
}

int main() {
    cin >> n >> m;
    for (int x = 0; x < n; x++) {cin >> v[x];}
    // lembrando que v é um vetor ordenado pela entrada

    int x = -1; // considerando o vetor 0-indexado
    for (int b = n; b >= 1; b/= 2) {
        // enquanto x não for solução, daremos um salto para tentar chegar no valor mais próximo possível
        while (!ok(x+b)) {x += b;}
    }
    int k = x + 1; // k é a posição que nos dá a resposta p/ o problema


    for (int i = 0; i < m; i++) {
        int valor;
        cin >> valor;
        cout << buscab(valor) << " ";
    }
}