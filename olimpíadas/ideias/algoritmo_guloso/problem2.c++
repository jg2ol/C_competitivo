#include <bits/stdc++.h>
using namespace std;


// 1222 - Concurso de Contos
// https://judge.beecrowd.com/pt/problems/view/1222
// ordem rígida das palavras

int main() {
    int n, l, c;
    while (cin >> n >> l >> c) {
        int pag = 1, linha = 1, carac = 0;
        for (int x = 0; x < n; x++) {
            string s;
            cin >> s;
            int tam = s.size();
            if (carac == 0) {carac = tam;}
            else {carac += tam+1;}
            if (carac > c) {carac = tam; linha++;}
            if (linha > l) {pag++; linha = 1;}
        }
        cout << pag << "\n";
    }
}
