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
}