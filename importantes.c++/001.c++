#include <bits/stdc++.h>
using namespace std;

// link: https://neps.academy/br/exercise/254
// Sorveteiros
// resposta errada (??)

int main() {
    int p, s;
    cin >> p >> s;
    
    vector <pair <int, int>> sorveteiros;
    for (int x = 0; x < s; x++) {
        int u, v;
        cin >> u >> v;
        
        if (!sorveteiros.empty()) {
            int ultimo = sorveteiros.back().second;
            if (ultimo < u) {sorveteiros.push_back({u, v});}
            else if (ultimo < v) {sorveteiros.back().second = v;}
        } else {sorveteiros.push_back({u, v});}
    }

    for (pair <int, int> p : sorveteiros) {cout << p.first << " " << p.second << endl;}
}