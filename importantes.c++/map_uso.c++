#include <bits/stdc++.h>
using namespace std;

// Machine Learning
// link: https://neps.academy/br/exercise/2835
// Limit Time Execeeded

int main() {
    map <string, pair <map <string, bool>, int>> temas;
    map <string, pair <map <string, bool>, int>> ::iterator it1;
    map <string, bool> ::iterator it2;
    int n, m;
    cin >> n;
    for (int x = 0; x < n; x++) {
        int c;
        string S;
        cin >> S >> c;
        for (int y = 0; y < c; y++) {string s; cin >> s; temas[S].first[s] = true;}
        temas[S].second = 0;
    }

    cin >> m;
    for (int x = 0; x < m; x++) {
        string s; cin >> s;
        for (it1 = temas.begin(); it1 != temas.end(); it1++) {
            if ((*it1).second.first.find(s) != (*it1).second.first.end()) {(*it1).second.second++;}
        }
    }
    
    int cont_max = -1;
    string tema;
    for (it1 = temas.begin(); it1 != temas.end(); it1++) {
        if ((*it1).second.second > cont_max) {cont_max = (*it1).second.second; tema = (*it1).first;}
    }
    
    cout << tema;
}