#include <bits/stdc++.h>
using namespace std;

#define maxn 105
int n, m, p, xs, ys, a, b, cc;
int lago[maxn][maxn], comp[maxn][maxn];

int di[12] = {-1, -2, -3, 1, 2, 3, 0, 0, 0, 0, 0, 0}, dj[12] = {0, 0, 0, 0, 0, 0, -1, -2, -3, 1, 2, 3};
void dfs(int i, int j) {
    for (int k = 0; k < 12; k++) {
        int I = i + di[k], J = j + dj[k];
        if (I <= 0 or I > n or J <= 0 or J > m) {continue;}

        if (lago[I][J] == 1 and comp[I][J] == 0) {comp[I][J] = cc; dfs(I, J);}
    }
}

int main() {
    cin >> n >> m >> p;
    for (int x = 0; x < p; x++) {
        int i, j;
        cin >> i >> j;
        lago[i][j] = 1;
    }
    cin >> xs >> ys >> a >> b;

    cc++;
    comp[xs][ys] = cc;
    dfs(xs, ys);
    if (comp[a][b] > 0) {cout << "S\n";}
    else {cout << "N\n";}
}