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
    bitset <10> b2("0010011010"); // da direita p/ a esquerda
    cout << b2[0] << " " << b2[1] << " " << b2[2] << "\n\n";

    // Assim sendo, podemos considerar um bitset como um vector (mais simples) de bool's
    bitset <10> a(string("0010110110"));
    bitset <10> b(string("1011011000"));
    // assim, os bitset's recebem as string's na ordem em que aparecem (da esquerda p/ a direita)
    
    cout << a << "\n";
    cout << b << "\n\n";
    
    // (a & b)[x] == 1 <=> a[x] == 1 and b[x] == 1;
    cout << (a&b) << "\n"; // 0010010000
    // (a | b)[x] == 1 <=> a[x] == 1 or b[x] == 1;
    cout << (a|b) << "\n"; // 1011111110
    // (a ^ b)[x] == 1 <=> (a[x] + b[x])%2 == 1; [ou exculsivo]
    cout << (a^b) << "\n"; // 1001101110
}