#include <bits/stdc++.h>
using namespace std;

// Estudo de funções (tanto criadas quanto já importadas)
// começamos declarando a função, da mesma maneira que definimos uma variável, precisamos do tipo
// o tipo a ser usado na declaração deve ser o tipo do return da mesma, na maioria das vezes, int
// assim como em Python devemos definir os parâmetros da função podendo também definir parâmetros opcionais
// estrutura: tipo nome(parâmetro1, parâmetro2, ...) { bloco de cálculo com return };

// Função que retorna o maior valor entre dois inteiros
int maior(int a, int b = 0) {
    if (a < b) {return b;}
    return a;  // se a função chegar até aqui então b <= a, portanto: return a;
}
// Função que retorna o menor valor entre dois inteiros
int menor(int a, int b) {
    if (a < b) {return a;}
    return b;
}
// Função que retorna o valor absoluto de n
int modulo(int n) {
    if (n < 0) {return -n;}
    return n;
}

// funções recursivas são as que "se chamam" p/ dar o seu return
// ex.: a função Fibonacci(n)

// Função que retorna o n-ésimo termo da sequência de Fibonacci
int fib(int n) {
    if (n < 0) {return 0;}
    else if (n == 0 or n == 1) {return n;}  // temos fib(0) = 0 e fib(1) = 1
    else {return fib(n-1) + fib(n-2);}  // com isso, a função procura por si mesma até encontrar um valor
}

// sempre podemos chamar uma função dentro de outra (até mesmo a si própria, nesse caso, dizemos que função é recursiva)
// mas nunca criá-la; por isso, precisamos utilizar este espaço p/ declaração de função (fora e antes da função main())

// Retorna o mdc entre dois inteiros
int mdc(int a, int b) {
    a = modulo(a); b = modulo(b);  // mdc(a, b) = mdc(|a|, |b|)

    int m = menor(a, b), n = maior(a, b);
    if (n % m == 0) {return m;}
    else {return mdc(n % m, m);}
    // qualquer else é opcional, mas facilita o entendimento
}

// Função que retorna o fatorial de n
int fat(int n) {
    int fat = 1;
    if (n <= 1) {return fat;}
    for (int x = 2; x <= n; x++) {fat *= x;}
    return fat;
}

// Função que recebe uma variável (ponteiro) e soma uma constante
int addk(int *n, int k = 1) {
    *n += k;
    return 0;
}

int main() {
    // função maior,  função menor e função módulo
    cout << maior(4, 5) << " > " << menor(4, 5)  << "; " << "|-5| = " << modulo(-5) << endl;
    
    // fib(n)
    int n;
    cout << "Digite a quantidade de termos que voce quer: ";
    cin >> n;
    for (int x = 0; x < n; x++) {cout << "Fibonacci(" << x << "): " << fib(x) << endl;}

    // mdc(a, b)
    int a, b;
    cout << "Digite um valor para 'a': ";
    cin >> a;
    cout << "Digite um valor para 'b': ";
    cin >> b;
    cout << "mdc(" << a << ", " << b << ") = " << mdc(a, b) << endl;

    // addk(&num, k = 1)
    int x = 3, y = 1;
    cout << "x = " << x << "; y = " << y << ";" << endl;
    int *p1, *p2;
    p1 = &x; p2 = &y;
    addk(p1, 5);
    addk(p2);
    cout << "Agora, x = " << x << "; y = " << y << ";" << endl;
}