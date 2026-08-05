#include <bits/stdc++.h>
using namespace std;

// 10440 - Ferry Loading II
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1381
// fazendo tempo com calma

int c, n, t, m;

int main() {
    cin >> c;
    for (int q = 0; q < c; q++) {
        cin >> n >> t >> m;
        int mod = m%n;
        int time = 0, viagens = (m+n-1)/n;
        for (int x = 1; x <= m; x++) {
            int hora;
            cin >> hora;
            if (x == mod) {time = max(time, hora) + 2*t;}
            if ((x-mod)%n == 0 && x != mod) {time = max(time, hora) + 2*t;}
        }
        time -= t;
        cout << time << " " << viagens << "\n";
    }
}
