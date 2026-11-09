#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> frase;
string f[55], aux[55];

bool comparaji(string a, string b) {
    if (a.length() != b.length()) {return a.length() > b.length();}
    return false;
}

// Função que ordena adequadamente o vetor de strings f[55]
// ordem: decrescente em tamanho, em caso de empate, preserva a ordem inicial
void merge_sort(int ini, int fim) {
    if (ini == fim) {return;}
    merge_sort(ini, (ini+fim)/2);
    merge_sort((ini+fim)/2+1, fim);

    int tam = 0, j = (ini+fim)/2+1;
    for (int i = ini; i <= (ini+fim)/2; i++) {
        while (j <= fim && comparaji(f[j], f[i])) {aux[tam++] = f[j++];}
        aux[tam++] = f[i];
    }
    while (j <= fim) {aux[tam++] = f[j++];}
    for (int x = ini; x <= fim; x++) {f[x] = aux[x-ini];}
}

int main() {
    cin >> n;
    cin.ignore();
    for (int q = 0; q < n; q++) {
        string s, palavra;
        getline(cin, s);
        istringstream fluxo(s);
        while (fluxo >> palavra) {frase.push_back(palavra);}
        int t = (int)frase.size();
        for (int x = 0; x < t; x++) {f[x] = frase[x];}
        merge_sort(0, t-1);
        frase.clear();
        cout << f[0];
        for (int x = 1; x < t; x++) {cout << " " << f[x];}
        cout << "\n";
    }
}
