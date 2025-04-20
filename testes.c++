#include <bits/stdc++.h>
using namespace std;

int pai[100100], peso[100100];

// Função que retorna o patriarca de x
int find(int x) {
    if (pai[x] == x) {return x;}
    else {return pai[x] = find(pai[x]);}
}

// Funcão que une as famílias de x e y
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (peso[x] < peso[y]) {pai[x] = y;}
        else if (peso[x] > peso[y]) {pai[y] = x;}
        else {pai[x] = y; peso[y]++;}
    } else {return;}
}

int main() {
    int n, k;
    cin >> n >> k;

    // faço cada valor ser seu próprio descendente, inicialmente
    for (int x = 0; x < n; x++) {pai[x] = x;} // nesse caso, não é necessário fazer peso[x] = 0, pois o vetor já está zerado
    for (int x = 0; x < k; x++) {
        char c;
        int b1, b2;
        cin >> c >> b1 >> b2;
        if (c == 'F') {join(b1, b2);}
        else {if (find(b1) == find(b2)) {cout << "S" << endl;} else {cout << "N" << endl;}}
    }
}