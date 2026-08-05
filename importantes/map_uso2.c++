#include <bits/stdc++.h>
using namespace std;

// // link: https://neps.academy/br/exercise/2835
// erro na entrada dos dados (string...)

int main() {
    int n, maior_pres = 0;
    cin >> n;
    // map com os tópicos e as respectivas palavras no vetor correpondente
    map <string, vector <string>> topicos;
    // map que guarda todos os tópicos e a quantidade palavras do tópico no artigo
    map <string, int> poss_top_art;
    // os tópicos que empataram em quantidade de palavras presentes no artigo
    vector <string> top_art;

    for (int x = 0; x < n; x++) {
        string topico; int k;
        cin >> topico >> k;

        // coloco o tópico inicialmente com zero palavras presentes no artigo no map
        poss_top_art.insert({topico, 0});

        vector <string> v;
        for (int y = 0; y < k; y++) {cin >> v[y];}
        topicos.insert({topico, v});
    }

    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
        string p;
        cin >> p;
        int temp = 0;
        for (pair <string, vector <string>> k : topicos) {
            // verifico se esta palavra pertence a algum tópico
            for (string s : k.second) {if (p == s) {poss_top_art[k.first]++; temp++; break;}}
            if (temp == 1) {temp = 0; break;}
        }
    }

    // calculando a maior quantidade de palavras presentes em algum tópico
    for (pair <string, int> p : poss_top_art) {if (p.second == maior_pres) {maior_pres = p.second;}}
    // coloco todas as possibilidades em um vetor (em caso de empate)
    for (pair <string, int> p : poss_top_art) {if (p.second == maior_pres) {top_art.push_back(p.first);}}
    // ordeno-o e imprimo o primeiro tópico em ordem alfabética
    sort(top_art.begin(), top_art.end());
    cout << top_art[0];
}