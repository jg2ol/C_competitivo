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

    // .insert --> insere um pair, interpreatação por vetor
    // O(log n)
    idades.insert({"Ana", 10});
    idades.insert({"Pedro", 5});

    // .erase(chave) --> remove um elemento, dada sua chave
    // O(log n)
    idades.erase("Ana");
    
    // podemos acessar um elemento utilizando apenas 'nome[chave]'
    cout << "Nome: Joao; Idade: " << idades["Joao"] << endl;
    
    // .find(chave) --> retorna o valor da chave especificada, se a chave não for encontrada retornará o último valor
    if (idades.find("Ana") == idades.end()) {cout << "'Ana' nao esta no mapa." << endl;}
    else {cout << "Nome: Ana; Idade: " << idades["Ana"] << endl;}
    cout << endl;

    // percorrendo um mapa
    // para isto, usaremos um iterator para passar por um set, o set do mapa
    // ou seja, percorreremos por um vetor de pairs utilizando o set, portanto será ordenado
    idades["Thiago"] = 17;
    idades["Gabriel"] = 20;
    idades["Emilia"] = 31;
    
    map <string, int> ::iterator it;
    for (it = idades.begin(); it != idades.end(); it++) {
        cout << "Nome: " << (*it).first << "; Idade: " << (*it).second << endl;
    }
}