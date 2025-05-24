#include <bits/stdc++.h>
using namespace std;

char mapa[10][10]; // 1-indexado
int per[10][10];

int main() {
    int l, c, a, b;
    cin >> l >> c;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] == 'o') {a = i; b = j;}
        }
    }
    
    int pl = a, pc = b;
    while (true) {
        bool b = 0;
        per[pl][pc] = 1;

        // char x1 = mapa[pl-1][pc], x2 = mapa[pl+1][pc], x3 = mapa[pl][pc-1], x4 = mapa[pl][pc+1];
        if (mapa[pl-1][pc] == 'H' and per[pl-1][pc] == 0) {pl--; b = 1;}
        if (mapa[pl+1][pc] == 'H' and per[pl+1][pc] == 0) {pl++; b = 1;}
        if (mapa[pl][pc-1] == 'H' and per[pl][pc-1] == 0) {pc--; b = 1;}
        if (mapa[pl][pc+1] == 'H' and per[pl][pc+1] == 0) {pc++; b = 1;}

        if (b) {break;}
    }

    cout << pl << " " << pc << "\n";
}