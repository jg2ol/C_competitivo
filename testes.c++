#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
int n, cont = 1;
vector <pii> agenda;

int main() {
    cin >> n;
    for (int x = 0; x < n; x++) {
        int i, f;
        cin >> i >> f;
        agenda.push_back({i, f});
    }
    sort(agenda.begin(), agenda.end());

    
}