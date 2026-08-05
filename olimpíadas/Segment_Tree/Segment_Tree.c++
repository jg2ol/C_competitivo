#include <bits/stdc++.h>
using namespace std;

// Segment Tree - Árvore de segmentos
// Dado um vetor com n posições, guardarenos na Seg uma informação
// específica de todos os intervalos possíveis do vetor (soma, maior velor, menor valor, etc)
// apenas uma informação, que variará de acordo com o que está sendo pedido
// Construção: O(n)
// Iteração/Atualização: O(log n)
// código base p/: https://neps.academy/br/exercise/43 (pede a soma dos intervalos)

#define maxn 100010
int n, q;
int v[maxn], tree[4*maxn]; // 1-indexados
// se fossem 0-indexados, toda vez que aparecer 2*node, 2*node+1 muda p/ 2*node+1, 2*node+2
// ajustando-se as posições

void build(int node, int l, int r) {
    // se o intervalo é unitáiro, a soma dos valores é o próprio número único
    if (l == r) {
        tree[node] = v[l];
        return;
    }

    // senão, construímos os filhos de forma análoga
    int m = (l + r)/2;
    build(2*node, l, m);
    build(2*node+1, m+1, r);

    // por fim, damos o valor do nó
    tree[node] = tree[2*node] + tree[2*node + 1];
}

void updt(int node, int l, int r, int ind, int x) {
    // p/ o intervalo unitário, atualize
    if (l == r) {
        tree[node] = x;
        v[l] = x;
        return;
    }
    
    // senão, atualize primeiro o filho que tiver o índice contido em seu intervalo
    int m = (l + r)/2;
    if (ind <= m and ind >= l) {updt(2*node, l, m, ind, x);}
    else {updt(2*node+1, m+1, r, ind, x);}

    // por fim, atualize o valor dos nós
    tree[node] = tree[2*node] + tree[2*node+1];
}

// soma dos valores do intervalo [l, r]
int query(int node, int dl, int dr, int l, int r) {
    if (dr < l or dl > r) {return 0;}
    else if (dl >= l and dr <= r) {return tree[node];}
    else {
        int m = (dl + dr)/2;
        return query(2*node, dl, m, l, r) + query(2*node+1, m+1, dr, l, r);
    }
}

int main() {
    cin >> n >> q;
    for (int x = 1; x <= n; x++) {cin >> v[x];}
    build(1, 1, n);

    for (int x = 0; x < q; x++) {
        int op;
        cin >> op;
        if (op == 0) {
            int ind, val;
            cin >> ind >> val;
            updt(1, 1, n, ind, val);
        }
        else {
            int k;
            cin >> k;
            cout << query(1, 1, n, 1, k);
        }
    }
}