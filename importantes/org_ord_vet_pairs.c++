#include <bits/stdc++.h>
using namespace std;

// Problema: Times (OBI - 2010 - 1ª Fase)
// link: https://neps.academy/br/exercise/253
// não há nomes iguais e também não há pessoas com mesmo nível de habilidade

int main() {
    // leio as duas variáveis n e k
    int n, k;
    cin >> n >> k;
    
    vector <pair <int, string>> jog;
    for (int x = 0; x < n; x++) {string j; int h; cin >> j >> h; jog.push_back({h, j});}
    
    // ordeno em crescente os jogadores em função do nível de habilidade
    sort(jog.begin(), jog.end());

    vector <vector <pair <string, int>>> times;
    // crio um vetor vazio dentro de cada time
    for (int x = 0; x < k; x++) {times.push_back({});}
    
    while (!jog.empty()) {
        for (int i = 0; i < k; i++) {
            if (jog.empty()) {break;}

            // coloco o melhor jogador restante no time i-1
            times[i].push_back({jog.back().second, jog.back().first});

            // apago o jogador que já está em algum time
            jog.erase(jog.end());
        }
    }

    for (int x = 0; x < k; x++) {
        // ordeno em função dos nomes, ou seja, coloco em ordem alfabética os times
        sort(times[x].begin(), times[x].end());
        
        // por fim, imprimo cada jogador de cada time de maneira organizada
        cout << "Time " << x+1 << endl;
        for (int i = 0; i < (int)times[x].size(); i++) {cout << times[x][i].first << endl;}

        if (x != k-1) {cout << endl;}
    }
}