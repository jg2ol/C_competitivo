#include <bits/stdc++.h>
using namespace std;

// 10670 - Work Reduction
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1611
// entrada com string, ordenação específica e organização de atualização de variáveis

struct res {string nome; int valor;};
int c, n, m, l;

bool comparaRes(res a, res b) {
    if (a.valor != b.valor) {return a.valor < b.valor;}
    return a.nome < b.nome;
}

int main() {
    cin >> c;
    for (int q = 1; q <= c; q++) {
        cin >> n >> m >> l;
        int aux = n, qtdhalf = 0;
        while (aux >= m) {aux /= 2; qtdhalf++;}
        qtdhalf--; aux = n;
        res v[l];
        for (int x = 0; x < l; x++) {
            string line, nome;
            int A, B;
            cin >> line;
            size_t colon_pos = line.find(':');
            size_t comma_pos = line.find(',');
            nome = line.substr(0, colon_pos);
            A = stoi(line.substr(colon_pos + 1, comma_pos - colon_pos - 1));
            B = stoi(line.substr(comma_pos + 1));

            int custo = 0, trab = n;
            while (trab > m) {
                int met = trab/2;
                if (met >= m) {custo += min(A*(trab-met), B); trab = met;}
                else {custo += A*(trab-m); trab = m;}
            }
            v[x].nome = nome; v[x].valor = custo;
        }
        sort(v, v+l, comparaRes);
        cout << "Case " << q << "\n";
        for (int x = 0; x < l; x++) {
            cout << v[x].nome << " " << v[x].valor << "\n";
        }
    }
}
