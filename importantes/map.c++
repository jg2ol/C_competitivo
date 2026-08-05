#include <bits/stdc++.h>
using namespace std;

// link: https://codeforces.com/problemset/problem/499/B
// procurando strings em um map

int main() {
    int n, m;
    cin >> n >> m;
    string palestra[m];
    map <string, string> idiomas;
    for (int x = 0; x < m; x++) {
        string i1, i2;
        cin >> i1 >> i2;
        idiomas[i1] = i2;
    }
    for (int x = 0; x < n; x++) {cin >> palestra[x];}

    for (int x = 0; x < n; x++) {
        if ((int)palestra[x].size() > (int)idiomas[palestra[x]].size()) {cout << idiomas[palestra[x]] << " ";}
        else {cout << palestra[x] << " ";}
    }
}