#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
int n, viz[maxn], pos[maxn];
long long int trabalho;

bool compara(int i, int j) {return viz[i] < viz[j];}

int main() {
    while(true) {
        cin >> n;
        if (n == 0) {break;}
        for (int i = 0; i < n; i++) {cin >> viz[i]; pos[i] = i;}
        
        trabalho = 0;
        sort(pos, pos+n, compara);
        int disp = n-1;
        for (int v = 0; v < n; v++) {
            if (viz[pos[v]] >= 0) {break;}
            for (int c = disp; c >= 0; c--) {
                if (viz[pos[v]] + viz[pos[c]] < 0) {
                    trabalho += abs(viz[pos[c]]*(pos[v]-pos[c]));
                    viz[pos[v]] += viz[pos[c]];
                    viz[pos[c]] = 0;
                    disp--;
                }
                else if (viz[pos[v]] + viz[pos[c]] == 0) {
                    trabalho += abs(viz[pos[c]]*(pos[v]-pos[c]));
                    viz[pos[v]] = 0;
                    viz[pos[c]] = 0;
                    disp--;
                }
                else {
                    trabalho += abs(viz[pos[v]]*(pos[v]-pos[c]));
                    viz[pos[c]] += viz[pos[v]];
                    viz[pos[v]] = 0;
                }
                if (viz[pos[v]] == 0) {break;}
            }
        }
        cout << trabalho << "\n";
    }
}