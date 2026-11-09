#include <bits/stdc++.h>
using namespace std;

#define maxn 105
int n, pontos[maxn], mark[maxn], receb[maxn], aux[maxn];
double avarage[maxn];

bool compara(int x, int y) {
    if (pontos[x] != pontos[y]) {return pontos[x] > pontos[y];}
    if (avarage[x] != avarage[y]) {return avarage[x] > avarage[y];}
    return x < y;
}

int main() {
    int t = 1;
    while (1) {
        cin >> n;
        if (n == 0) {break;}
        for (int x = 1; x <= n; x++) {pontos[x] = 0; mark[x] = 0; receb[x] = 0; avarage[x] = 0; aux[x] = x;}
        for (int x = 1; x <= n*(n-1)/2; x++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (b > d) {pontos[a] += 2;}
            else {pontos[c] += 2;}
            mark[a] += b; mark[c] += d;
            receb[a] += d; receb[c] += b;
        }
        for (int x = 1; x <= n; x++) {
            if (receb[x] != 0) {avarage[x] = mark[x]/receb[x];}
            else {avarage[x] = mark[x];}
        }
        sort(aux+1, aux+n+1, compara);
        cout << "Instancia " << t++ << "\n" << aux[1];
        for (int x = 2; x <= n; x++) {cout << " " << aux[x];}
        cout << "\n\n";
    }
}
