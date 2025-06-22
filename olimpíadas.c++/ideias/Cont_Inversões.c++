#include <bits/stdc++.h>
using namespace std;

// Compressão de Coordenadas - A ideia é reduzir os valores, por exemplo, de um vetor de n posições
// a valores menos custosos, reduzindo o tempo de execução
// Utilizando a estrutura BIT

// Problema base: contar o número de inversões em um vetor v [em O(nlog n)]
// uma inversão ocorre quando há dois valores de i e j tais que 1 <= i < j <= n e v[i] > v[j]

#define maxn 100010
int n;
int v[maxn], bit[maxn];

void updt(int x, int v) {
    for (int i = x; i <= n; i += (i & -i)) {
        bit[i] += v;
    }
}

int soma(int x) {
    // soma de 1 até x
    int ans = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
        ans += bit[i];
    }
    return ans;
}

int main() {
    cin >> n;

    // vetor auxiliar
    vector <int> aux;

    for (int x = 1; x <= n; x++) {
        cin >> v[x];
        aux.push_back(v[x]);
    }
    // ordenamos o vetor auxiliar
    sort(aux.begin(), aux.end());

    int ind = 0;
    map <int, int> mp;
    for (int x = 0; x < n; x++) {
        // mapeando os valores, tomando cuidado com as repetições
        if (mp.find(aux[x]) == mp.end()) {mp[aux[x]] = ++ind;}
    }

    // resposta final, que pode ser long long já que v[i] <= 10**9
    long long ans = 0;
    for (int x = n; x >= 1; x--) {
        // trocando os valores do vetor original pelos seus valores mapeados
        ans += soma(mp[v[x]] - 1); // inversões em que x participa
        updt(mp[v[x]], 1);
    }

    cout << ans << "\n";
}