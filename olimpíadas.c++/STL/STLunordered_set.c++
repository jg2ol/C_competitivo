#include <bits/stdc++.h>
using namespace std;

// unordered_set --> um set sem ordem de comparação, ou seja, quase um vector
// vantagens: algoritmos mais rápidos que vector e insert mas rápido que set

int main() {
    unordered_set <int> a, b;
    int n;
    cin >> n;
    for (int x = 0; x < n; x++) {int v; cin >> v; a.insert(v);}
    for (int x = 0; x < n; x++) {int v; cin >> v; b.insert(v);}

    int cont = 0;
    for (auto x : a) {if (b.count(x)) {cont++;}}
    cout << cont << "\n";
}