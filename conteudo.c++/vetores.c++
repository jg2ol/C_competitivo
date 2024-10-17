#include <bits/stdc++.h>
using namespace std;

#define maxn 100100

// declarar vetores aqui fora fará com que eles já venham todos "zerados"
int empr[maxn], capital[maxn];

// funções utilizadas...

// Função que compara dois inteiros a partir dos capitais nos respectivos índices
bool comparaCap(int x, int y) {
    if (capital[x] >= capital[y]) {return true;}
    return false;
}

int main() {
    // Estudo focado nas melhores formas de se tratar vetores (listas)
    // vetores == listas (Python) --> possui índices numerados da mesma forma
    // --> o mesmo vale p/ chamadas de valores de dentro de vetores; ex.: int a = idades[1];
    // p/ declarar um vetor precisamos ter seu tamanho em mãos
    // estrutura: tipo vetor[n]; --> cria um vetor com n elementos do tipo especificado, ou seja,
    // não é permitido que um vetor tenha elementos de mais de um tipo diferente
    int n;
    cout << "Digite a quantidade de valores: ";
    cin >> n;
    int vetor1[n]; // --> vetor com n elementos inteiros
    for (int x = 0; x < n; x++) {
        cout << "Digite o " << x+1 << "o valor: ";
        cin >> vetor1[x];
    }
    cout << "Voce digitou os valores: ";
    for (int x = 0; x < n; x++) {cout << vetor1[x] << " ";}
    cout << endl << endl;

    // ordenando um vetor de n elementos com a biblioteca algorithm (complexidade: O(n*log(n) --> log na base 2))
    // a função sort() recebe dois valores, o início e o fim declarando um intervalo p/ ser ordenado no vetor
    // os valores são do formato (nome + início, nome + fim)
    // se quizermos ordenar um vetor cujo nome é 'vetor' no índice i até o índice j (inclusive), deveremos chamar:
    // sort(vetor + i; vetor + j + 1); --> sort(vetor + 0, vetor + n) => ordena o vetor completo (de 0 a n-1)
    cout << "Quantos elementos tera o vetor? ";
    cin >> n;
    cout << "Digite os valores: ";
    int vetor2[n];
    for (int x = 0; x < n; x++) {cin >> vetor2[x];}
    sort(vetor2+0, vetor2+n);
    cout << "Em ordem crescente fica: ";
    for (int x = 0; x < n; x++) {cout << vetor2[x] << " ";}
    cout << endl << endl;

    // a função sort() também pode receber um terceiro parâmetro, o 'fator de ordenação'
    // podemos mudar o critério de ordenação da função, agora não necessariamente ela vai deixar o vetor em ordem crescente
    // vejamos um exemplo com n empresas numeradas de 1 a n, cada uma com seu capital, e queremos um vetor com os capitais
    // na ordem da empresa mais rica até a mais pobre, e também ordenar seus numeradores
    // para isso, precisaremos comparar seus capitais, criamos então uma função para isso
    // essa função (compara) será o terceiro parâmetro da função sort()
    cout << "Quantas sao as empresas? ";
    cin >> n;
    cout << "Digite o capital da empresas de 1 a n: ";
    for (int x = 0; x < n; x++) {cin >> capital[x]; empr[x] = x;}
    sort(empr+0, empr+n, comparaCap);
    cout << "A ordem dos numeradores das empresas de acordo com os capitais fica: ";
    for (int x = 0; x < n; x++) {cout << empr[x]+1 << " ";}
    cout << endl << endl;
}