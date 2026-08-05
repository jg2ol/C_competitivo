#include <bits/stdc++.h>
using namespace std;

// 1661 - Comércio de Vinhos na Gergóvia
// https://judge.beecrowd.com/pt/problems/view/1661
// começar pequeno e analisar o primeiro movimento recursivamente

#define maxn 100010
int n;

int main() {
    while (true) {
        cin >> n;
        if  (n == 0) {break;}
        long long acum = 0, res = 0;
        for (int x = 0; x < n; x++) {
            int vinho;
            cin >> vinho;
            acum += vinho;
            res += abs(acum);
        }
        cout << res << "\n";
    }
}
