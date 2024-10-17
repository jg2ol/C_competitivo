#include <bits/stdc++.h>
using namespace std;

int main() {
    // Estudo de condicionais e loops
    // variáveis declaradas em if, for, while ..., têm escopo local, e não global, diferentemente do Python
    // dentro dessas estruturas só podemos modificar seu valor
    // também podemos reduzir a expressão p/ operação constante nas variáveis, em caso de passo 1, basta i++ ou i--
    // ex.'s: a += 1 --> a++, j--, cont += x;
    // cout << x++; --> imprime x e depois soma-se 1 (ou seja, imprime x mas depois do cout, x terá valor x+1)
    // cout << ++x; --> soma-se 1 no x e depois o imprime (ou seja, imprime x+1)
    // for x in range(0, n):
    // ==> for (int x = 0; x < n; x++) {} --> vai até n-1

    // estrutura condicional geral em c++ (não tem elif)
    // if (condição1) {
    //     faça 1;
    // } else if (condição2) {
    //     faça2;
    // } else {
    //     faça3;
    // };
    int a;
    cout << "Digite um numero para saber seu sinal: ";
    cin >> a;

    if (a < 0) {
        cout << "'a' --> negativo" << endl;
    }
    else if (a > 0) {
        cout << "'a' --> positivo" << endl;
    }
    else {
        cout << "'a' --> nulo" << endl;
    };

    // operadores lógicos
    // são os mesmos do Python porém podemos, também, usar os do js, ou seja,
    // and = &&, or = ||, not = !;

    // estruturas de repetição
    // for, estrutura: for (int i = 0; i <= n; i += 1) { faça }
    // for (inicialização; intervalo; atualização) { bloco de comando }
    // (declaração da variável temporária; condição; atualização)
    // ex.:
    for (int i = 10; i > 0; i--) {
        cout << i << " ";
    } cout << endl;

    // while, estrutura: while (condição) { faça }
    // ex.:
    // número a ser adivinhado pelo jogador
    int numeroSecreto = 47;
    int palpite;
    bool acertou = false;

    cout << "Bem-vindo ao jogo de adivinhacao!\n";
    cout << "Tente adivinhar o numero entre 1 e 100.\n";

    while (!acertou) {
        cout << "Insira seu palpite: ";
        cin >> palpite;

        if (palpite == numeroSecreto) {acertou = true;}
        else if (palpite < numeroSecreto) {cout << "O numero secreto e maior. Tente novamente!\n";}
        else {cout << "O numero secreto e menor. Tente novamente!\n";}
    }
    cout << "Voce acertou!" << endl << endl;

    // DoWhile --> while sem a verificação na primeira iteração
    // estrutura: do { bloco de código } while ( condição );
    int q = 23;
    do {
        cout << q << " ";
        q++;
    } while (q > 23 and q < 30);
    cout << endl;

    // switch - case
    // primo do if - elif - else, com mudanças estruturais
    /*
    estrutura: switch (variável) {
        case valor1:
            [bloco de código]1
            break;
        case valor2:
            [bloco de código]2
            break;
        .
        .
        .
        default:
            [bloco final]
    } --> faz as verificações: if (variável == valor1, valor2, valor3 ...) { [bloco de código]x } else { [bloco final] }
    */
    // ex.: id = 1 => papel; id = 2 => tesoura; id = 3 => cola; id = 4 => caneta
   int id;
   cout << "Digite o id (1, 2, 3 ou 4): ";
   cin >> id;
   switch (id) {
    case 1:
        cout << "Papel";
        break;
    case 2:
        cout << "Tesoura";
        break;
    case 3:
        cout << "Cola";
        break;
    case 4:
        cout << "Caneta";
        break;
    default:
        cout << "ID invalido!";
   }
   cout << endl;
}