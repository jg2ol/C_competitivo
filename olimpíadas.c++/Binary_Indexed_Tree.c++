#include<bits/stdc++.h>
using namespace std;

// BIT - Binary Indexed Tree
// código base p/ problemas que pedem a soma dos termos de posições 1 até x de forma dinâmica
// p/ melhor visualização: https://www.youtube.com/watch?v=uSFzHCZ4E-8

#define maxn 100010
int n;

// lsb(x) --> expoente da maior potência de 2 que divide x [em código: lsb(x) = (x&-x);]
// bit[i] --> soma dos termos do intervalo [i - 2**(lsb(x)) + 1, i]
struct BIT {
    int tree[maxn];
    
    void update(int x, int val) {
        // exatamente assim, se tentarmos fazer int k = x; --> erro
        for (; x <= n; x += (x & -x)) {
            tree[x] += val;
        }
    }

    // soma de de [1, x]
    int soma(int x) {
        int ans = 0;
        for (; x > 0; x -= (x & -x)) {
            ans += tree[x];
        }
        return ans;
    }
} bit;

int main() {
    // problema base (o mais simples): https://neps.academy/br/exercise/43
    int q;
    cin >> n >> q;

    vector <int> v;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        bit.update(i, x);
        v.push_back(x);
    }

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;

        if (op == 0) {
            int b, c;
            cin >> b >> c;
            bit.update(b, c - v[b-1]);
            v[b-1] = c;
        }
        else {
            int b;
            cin >> b;
            cout << bit.soma(b) << "\n";
        }
    }
}