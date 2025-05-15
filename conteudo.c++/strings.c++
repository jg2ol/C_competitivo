#include <bits/stdc++.h>
using namespace std;

int main() {
    // Estudo de tratamento de strings
    // char c = 'a'; --> um único caractere
    // string s = "chama"; --> uma cadeia de caracteres, na prática, pode ser entendida como um vetor de char
    // ao citar char's usar aspas simples (''), p/ strings, aspas duplas (""); ex.'s: char a = 'c'; string s = "chama";
    
    // os comandos string.size() e strlen(string) retornam a quantidade de caracteres da string s
    string s = "chama";
    cout << "A string '" << s << "' tem " << s.size() << " caracteres." << endl;

    // também podemos ordenar string's
    sort(s.begin(), s.end());
    cout << s << "\n";
    
    // podemos concatenar strings mas não diretamente aspas, ex.: s += "1 chama2"; "Bom dia! " + "Chama!" --> não funciona
    string nome;
    cout << "Digite seu nome: ";
    cin >> nome;
    string sobrenome = "Chama";
    nome += " " + sobrenome;
    cout << nome << endl;

    // também podemos trabalhar com o ascii d e char's
    char c1 = 'a';
    printf("ASCII: %d; CARACT: %c\n", c1, c1); // imprime o ascii da letra correspondente e o char em si
    
    char c2 = 98;
    printf("ASCII: %d; CARACT: %c\n", c2, c2); // imprime o ascii da letra e a letra correspondente

    // getline(cin) e cin.ignore();
    // getline é usado para literalmente "pegar" a linha completa, independente do seu conteúdo (mesmo se vazio)
    string s;
    cin.ignore(); // não considere o "\n" deixado pelo último cout
    getline(cin, s); // leia uma linha e jogue na variável s
    cout << s << "\n";

    // .substr(pos, qtd) --> retorna uma substring com qtd caracteres a partir da posição pos
    string a = "Bom dia, " + nome;
    string c = a.substr(2, 5); // c = "m dia";
    cout << c << "\n";
}