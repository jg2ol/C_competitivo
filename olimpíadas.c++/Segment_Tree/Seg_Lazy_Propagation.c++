#include <bits/stdc++.h>
using namespace std;

// Lazy Propagation
// dessa vez, ao invés de atualizar os valores do vetor em apenas uma posição
// iremos atualizar os valores de um intervalo inteiro de uma vez só
// problema base: calcular o maior valor de um intervalo dado de um vetor dado
// e atualizar os valores do vetor para x em um dado intervalo

#define maxn 100010
int n;
int v[maxn], tree[4*maxn], lz[4*maxn]; // lz[i] --> valor a ser atualizado em v[i]

void build(int node, int l, int r) {
    if (l == r) {tree[node] = v[l]; return;}
    int m = (l+r)/2;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    // parte em q é definida o tipo da Seg
    // neste caso, a Seg representará os valores máximos dos intervalos
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

void unlazy(int node, int dl, int dr) {
    // se não há o que atualizar, nada faremos
    if (lz[node] == 0) {return;}

    // senão, atualize
    tree[node] = lz[node];
    // se tiver filhos, propague p/ os primeiros
    // aqui, não precisa da recursividade pois esta será feita nas outras funções
    if (dl != dr) {
        tree[2*node] = lz[node];
        tree[2*node+1] = lz[node];
    }
    lz[node] = 0;
}

void updt(int node, int dl, int dr, int l, int r, int v) {
    unlazy(node, dl, dr);
    if (dl > r or dr < l) {return;}
    else if (dl >= l and dr <= r) {
        lz[node] = v;
        unlazy(node, dl, dr);
        return;
    }
    else {
        int m = (dl+dr)/2;
        updt(2*node, dl, m, l, r, v);
        updt(2*node+1, m+1, dr, l, r, v);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}

int query(int node, int dl, int dr, int l, int r) {
    unlazy(node, dl, dr);
    if (dl > r or dr < l) {return 0;}
    else if (dl >= l and dr <= r) {return tree[node];}
    else {
        int m = (dl+dr)/2;
        return max(query(2*node, dl, m, l, r), query(2*node+1, m+1, dr, l, r));
    }
}

int main() {
    cin >> n;
    for (int x = 1; x <= n; x++) {cin >> v[x];}
    build(1, 1, n);
}