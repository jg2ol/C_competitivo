#include <bits/stdc++.h>
using namespace std;

// código do Union-Find totalmente desenvolvido e otimizado

// a intenção é resolver problemas do tipo do problema Fusões (OBI - 2010 - 2ª Fase - P1)
// link: https://neps.academy/br/exercise/264

#define maxn 100100

int pai[maxn]; // pai[i] = pai de i
int peso[maxn]; // peso[i] = distância do descendente de i mais longe do patriarca de i
// também podemos saber quantos elementos tem o conjunto com o elemento x em O(1)
int qtd[maxn]; // qtd[i] = quantos elementos têm o mesmo patriarca que i (inclusive ele mesmo)

// Função otimizada com vetor que retorna o pai de x
int find(int x) {
    // a ideia é evitar procuras repetidas; ex.: pai[1] = 2; pai[2] = 3; pai[3] = 4; pai[4] = 4;
    // => find(1) = find(pai[1]) = find(2) = find(3) = 4;
    // => find(2) = find(pai[2]) = find(3) = 4;
    // mas, já sabemos, pela verificação anterior que find(2) = 4; devemos procurar salvar estes dados
    if (pai[x] == x) {return x;}
    else {
        // pai[x] = find(pai[x]);
        return pai[x] = find(pai[x]); // salvo o pai de x no vetor "pai"
        // toda vez que o código entra aqui, salvamos o pai de x no vetor
        // assim: pai[1] = 4; pai[2] = 4; ...
    }
}

// Função otimizada que faz o patriarca de x ser o patriarca de y
void join(int x, int y) {
    // aqui, a ideia é fazer com que join(x, y) = min(join(x, y), join(y, x))
    // ou seja, saber em qual do dois casos é melhor declarar quem é pai de quem
    // de modo a minimizar soma das distâncias dos elementos aos seus patriarcas
    // assim, reduzindo o caminho de find(x)
    x = find(x);
    y = find(y);
    if (peso[x] < peso[y]) {pai[x] = y; qtd[y] += qtd[x];}
    else if (peso[x] > peso[y]) {pai[y] = x; qtd[x] += qtd[y];}
    else {pai[x] = y; peso[y]++; qtd[y] += qtd[x];}
    // atualizo a quantidade de elementos dos conjuntos no vetor qtd
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int x = 1; x <= n; x++) {pai[x] = x; qtd[x] = 1;}
    // inicialmente, todo elemento é pai somente de si mesmo, portanto, qtd[i] = 1;

    char c;
    int b1, b2;
    for (int x = 0; x < k; x++) {
        cin >> c >> b1 >> b2;
        if (c == 'F') {join(b1, b2);}
        else {if (find(b1) == find(b2)) {cout << 'S';} else {cout << 'N';} cout << endl;}
    }

    // Accepted; 100/100
}