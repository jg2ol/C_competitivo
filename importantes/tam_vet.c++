#include <bits/stdc++.h>
using namespace std;

int main() {
    // Zero para Cancelar
    // link: https://neps.academy/br/exercise/1486
    int n;
    cin >> n;
    int vetor[n], soma = 0, tam = 0;

    for (int x = 0; x < n; x++) {
        int num;
        cin >> num;
        if (num != 0) {
            vetor[tam] = num;
            tam++;
        } else {tam--;}
    }

    for (int x = 0; x < tam; x++) {soma += vetor[x];}
    cout << soma;
}