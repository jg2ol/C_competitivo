#include <bits/stdc++.h>
using namespace std;

// "parte bruta" do método Union-Find
// a intenção é resolver problemas do tipo do problema Fusões (OBI - 2010 - 2ª Fase - P1)
// link: https://neps.academy/br/exercise/264

#define maxn 100100

int pai[maxn];  // pai[i] = número do pai de 'i'

// Funcão recursiva que retorna o pai de um elemento qualquer
int find(int x) {
    if (pai[x] == x) {return x;}  // se x é o patriarca, então é pai de si mesmo
    else {return find(pai[x]);}   // senão, o "pai verdadeiro" de x será o pai do "pai" de x
}

// Função que faz o patriarca de x ser o patriarca de y (Função Union)
void join(int x, int y) {
    // teoricamente, pai[x] = y; seria suficiente
    // porém, podemos generalizar para quaisquer elementos, veja:
    pai[find(x)] = find(y); // assim, 'juntamos' os dois elementos à mesma família (o 'caminho' entre eles também)
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int x = 1; x <= n; x++) {pai[x] = x;}

    char c;
    int b1, b2;
    for (int x = 0; x < k; x++) {
        cin >> c >> b1 >> b2;
        if (c == 'F') {join(b1, b2);}
        else {if (find(b1) == find(b2)) {cout << 'S';} else {cout << 'N';} cout << endl;}
    }

    // Time Limit Exceeded
    // TLE, o código passa do limite de tempo
}