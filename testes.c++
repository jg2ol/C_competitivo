#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
int n;
int bit[maxn];

void upd(int x, int v) {
    for (int k = x; k <= n; k += (x & -x)) {
        bit[k] += v;
    }
}

int soma(int x) {
    // soma de de [1, x]
    int ans = 0;
    for (int k = x; k > 0; k -= (x & -x)) {
        ans += bit[k];
    }

    return ans;
}

int main() {
    
}