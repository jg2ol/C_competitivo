#include <bits/stdc++.h>
using namespace std;

// Chaves
// link: https://neps.academy/br/exercise/56
// uso do getline() e cin.ignore()

int main() {
    int n;
    cin >> n;
    cin.ignore(); // ignora o "\n" deixado pelo cin >> n;
    
    bool correto = true; // identifica se as chaves estão corretamente empregadas
    stack <char> chaves;
    for (int x = 0; x < n; x++) {
        string s;
        getline(cin, s); // literalmente "pega a linha" independente do seu conteúdo e coloca na variável s
        
        if (correto) {
            for (char c : s) {
                if (c == '{' || c == '}') {
                    if (c == '{') {chaves.push(c);}
                    else if (chaves.empty()) {correto = false;}
                    else {chaves.pop();}
                }
            }
        }
    }

    if (!chaves.empty()) {cout << "N";}
    else if (correto) {cout << "S";}
    else {cout << "N";}
}