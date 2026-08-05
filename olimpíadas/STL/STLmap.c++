#include <bits/stdc++.h>
using namespace std;

// map --> o mesmo que o dicionário do Python
// uma lista generalizada, necessitando de chaves para guardar valores respectivos
// pode ser interpretado como um vetor de pairs

int main() {
    // declaração estrutura: map <tipo_chave, tipo_valor> nome;
    map <string, int> idades;

    // inserindo elementos: temos dois métodos, interpretando como um dicionário ou como um vetor
    // nome[chave] = valor; --> interpretação por dicionário
    // O(log n)
    idades["Joao"] = 13;

    // .insert --> insere um pair, interpretação por vetor
    // O(log n)
    idades.insert({"ana", 10});
    idades.insert({"Pedro", 5});

    // .erase(chave) --> remove um elemento, dada sua chave
    // O(log n)
    idades.erase("ana");
    
    // podemos acessar um elemento utilizando apenas 'nome[chave]'
    cout << "Nome: Joao; Idade: " << idades["Joao"] << endl;

    // .begin() --> início do map
    // .end() --> final do map
    // .begin() e .end() funcionam como iterator e não ponteiros

    // .find(chave) --> retorna o valor da chave especificada, se a chave não for encontrada retornará o último valor
    if (idades.find("ana") == idades.end()) {cout << "'ana' nao esta no map." << endl;}
    else {cout << "Nome: ana; Idade: " << idades["ana"] << endl;}
    
    // também podemos "contar" quantas vezes um valor aparece num map
    // .count() --> retorna 1 se o valor tiver presente, 0 caso contrário
    // se tentarmos acessar um elemento inexistente no map, será criado automaticamente com valor 0
    if (idades.count("ana")) {cout << "S\n";}
    else {cout << "N\n";}
    cout << endl;

    // percorrendo um mapa
    // para isto, usaremos um iterator para passar por um set, o set do mapa
    // ou seja, percorreremos por um vetor de pairs utilizando o set, portanto será ordenado
    idades["Thiago"] = 17;
    idades["Gabriel"] = 20;
    idades["Emilia"] = 31;
    idades["Ednaldo"] = 60;

    map <string, int> ::iterator it;
    // podemos reduzir o código do iterator, fazendo simplesmente:
    // for (auto it = idades.begin(); it != idades.end(); it++) {}

    for (it = idades.begin(); it != idades.end(); it++) {
        cout << "Nome: " << (*it).first << "; Idade: " << (*it).second << endl;
    }
}