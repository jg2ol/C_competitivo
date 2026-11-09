#include <bits/stdc++.h>
using namespace std;

// problema 1258 do Beecrowd - Camisetas
int n;
bool b = 1;
struct camisa{string nome; string cor; char tam;};
camisa v[65];
bool compara(camisa x, camisa y) {
    if (x.cor != y.cor) {return x.cor < y.cor;}
    if (x.tam != y.tam) {return x.tam > y.tam;}
    return x.nome < y.nome;
}

int main() {
    while (1) {
        cin >> n;
        if (n == 0) {break;}
        cin.ignore();
        for (int x = 0; x < n; x++) {
            getline(cin, v[x].nome);
            cin >> v[x].cor >> v[x].tam;
            cin.ignore();
        }
        sort(v, v+n, compara);
        if (!b) {cout << "\n";}
        b = 0;
        for (int x = 0; x < n; x++) {cout << v[x].cor << " " << v[x].tam << " " << v[x].nome << "\n";}
    }
}
