#include <bits/stdc++.h>
using namespace std;

// as funções max() e min() só aceitam dois valores, mas, max({}) e min({}) aceitam qualquer quantidade de valores

int main() {
    // Estudo de tratamento de números

    // já conhecidos os métodos, podemos fazer operações entre números
    // + --> adição
    // - --> subtração
    // / --> divisão
    // * --> multiplicação
    // % --> módulo (congruência aritmética)
    
    int x = 2*3*5*6;
    cout << "2 x 3 x 5 x 6 = "<< x << "\n";
    
    // a%m --> retorna valor entre -m+1 e m-1, ou seja, pode ser negativo
    // para fazer a correção matemática (restos negativos não são considerados) somamos m
    int m = 7, rxm = x%m;
    if (rxm < 0) {rxm += m;} // assim rxm > 0, já que 0 <= |a%m| <= m-1
    cout << "O numero " << x << " deixa resto " << rxm << " quando dividido por " << m << ".\n";

    // na divisão entre dois inteiros considera-se o valor inteiro com menor módulo; ex.'s: 5/2 = 2, 5/-2 = -2
    // p/ termos o valor exato da divisão, devemos dizer que pelo menos um dos dois valores são do tipo double
    int a = 7;
    int b = 2;
    double c = 2;
    float f = -3.14;
    int d = -2;
    cout << "a / b = " << a/b << "     (valor inteiro)" << endl;
    cout << "a / c = " << a/c << "   (valor real)" << endl;
    cout << "a / d = " << a/d << "    (valor inteiro negativo)" << endl << "\n";
    
    // a função abs(n) retorna o valor absoluto de n
    // na declaração de inteiros, os números têm limites, assim, podemos definir com um outro tipo de variável:
    // int --> de -2*10^9 até 2*10^9
    // long long --> de -4*10^18 até 4*10^18
    long long l = 123456789123456789LL;
    cout << "l = " << l << "\n";

    // não misturar operações entre int e long long, pode causar erro
    int n1 = 123456789;
    long long n2 = n1*n1;
    cout << n2 << "\n"; // -1757895751 (erro)
    // solução:
    long long n3 = (long long)n1*n1; // ou defino n1 como long long (long long n1 = 123456789;)
    cout << "123456789 = " << n3 << "\n\n";

    // Precisão de casas decimais
    // estrutura: printf("%.nf", variável); --> 'n' é o número de casas decimais que desejamos
    // por padrão, C e C++ permitem manipulações até a 6ª casa decimal
    f = 1.123456789;
    printf("%.1f; %.2f; %.7f; %.10f;\n", f, f, f, f); // aproximação para 7 dígitos e erro para mais que 7 dígitos

    // também podemos mudar a base de um número na hora de imprimí-lo
    // estrutura: printf("%[base]", variável);
    // a 'base' pode ser: o -> octadecimal (8); x -> hexadecimal (16);
}