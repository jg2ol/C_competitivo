#include <bits/stdc++.h>
using namespace std;

int main() {
    // Estudo de tratamento de números

    // já conhecidos os métodos, podemos fazer operações entre números
    // + --> adição
    // - --> subtração
    // / --> divisão
    // * --> multiplicação
    // % --> módulo
    cout << "2 x 3 x 5 x 7 = "<< 2*3*5*7 << endl;

    // na divisão entre dois inteiros considera-se o valor inteiro com menor módulo; ex.'s: 5/2 = 2, 5/-2 = -2
    // p/ termos o valor exato da divisão, devemos dizer que pelo menos um dos dois valores são do tipo double
    int a = 7;
    int b = 2;
    double c = 2;
    int d = -2;
    cout << "a / b = " << a/b << "     (valor inteiro)" << endl;
    cout << "a / c = " << a/c << "   (valor real)" << endl;
    cout << "a / d = " << a/d << "    (valor inteiro negativo)" << endl;
    
    // a função abs(n) trás o valor absoluto de n
    // na declaração de inteiros, os números têm limites, assim, podemos definir com um outro tipo de variável:
    // int --> de -2*10^9 até 2*10^9
    // long long --> de -4*10^18 até 4*10^18
    // as funções max() e min() só aceitam dois valores, mas, max({}) e min({}) aceitam qualquer quantidade de valores
}