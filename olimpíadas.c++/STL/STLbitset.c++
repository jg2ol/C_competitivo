#include <bits/stdc++.h>
using namespace std;

// bitset --> uma lista de valores 0 ou 1 inicialmente zerada
// podemos acessar os elementos assim como em vector, utilizando []

int main() {
    bitset <10> b1;
    b1[0] = 0; // desnecessário pois o bitset já está zerado
    b1[5] = 1;
    cout << b1[0] << " " << b1[1] << " " << b1[5] << " " << b1[7] << "\n";

    // podemos fazer um bitset a partir de uma string de caracteres 0 e 1
    bitset <10> b2("0010011010"); // da esquerda p/ a direita
    cout << b2[0] << " " << b2[1] << " " << b2[2];
}