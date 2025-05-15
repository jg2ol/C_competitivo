#include <bits/stdc++.h>
using namespace std;


int main() {
    // objetivo: saber o número de elementos comuns entre duas listas de inteiros, ambas com n elementos
    vector <int> a, b;
    int n;
    cin >> n;
    for (int x = 0; x < n; x++) {cin >> a[x];}
    for (int x = 0; x < n; x++) {cin >> b[x];}

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    
}