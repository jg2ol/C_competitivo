// comentário
// a 1ª linha é reponsável por importar a biblioeca com todas as funções necessárias, sejam básicas como main(), ou avançadas
// a 2ª linha é responsável por dizer que não usaremos o termo "std" p/ declaração de variável (a termos
// de simplificação de código)


// importando uma biblioteca em c++
// estrutura: #include <'nome'>  --> não precisa de ";"
// a biblioteca bits/stdc++.h contém todas as outras bibliotecas dentro dela
// portanto, ao importá-la, teremos acesso a todo o conteúdo já criado em c++
#include <bits/stdc++.h>
// dizendo que não iremos usar a nomenclatura padrão (precisaria digitar 'std' toda vez que fosse usar algo)
using namespace std;

// podemos definir nomes p/ expressões "constantes" (geralmente máximos e mínimos p/ casos de teste)
// não precisa de ";"
// ex.'s:

// valor numérico constante
#define maxn 100100

// chamada de funções importadas
#define F first // pair.first == pair.F
#define S second // pair.second == pair.S
#define PB push_back // vector

// chamada de quaisquer estruturas "naturais" da linguagem
#define REP(i, a, b) for (int i = a; i <= b; i++)
// for (int x = 0; x < n; x++) {} == REP(x, 0, n-1) {}

// tomar cuidado com expressões, ex.:
// #define SQ(a) a*a
// SQ(1+2) = 1+2*1+2 = 5, e não (1+2)*(1+2) = 9
#define SQ(a) (a)*(a) // sempre colocar parênteses em valores

// não serve para tipagem de variáveis nem para as estruturas importadas em si, para isso, utilizamos outra estrutura
// estrutura: typedef tipo nome_atualizado;
typedef long long int lli;
typedef vector <int> vi;
typedef pair <int, int> pii;


// Função que recebe um ponteiro de um inteiro e faz com que o inteiro receba +3
void add3(int* p) {
    *p = *p + 3;
}

int main() {
    // a maior parte do código entra aqui
    // ao final de toda santa linha, precisa de um ";"
    // o c++ não tem problema com identação, mas serve p/ organização
    // o c++ não aceita acentuação e ç
    
    // semelhanças com Python, todas as linguagens de progrmação são parecidas
    
    // cout == print(, end = "")
    // Mostre <-- variável; "mostre a variável"
    // caso for usado mais de um cout os print's seram concatenados, ou seja, p/ haver quebra de linha, precisamos
    // dizer ao programa, utilizando o endl ou o '\n' (mais rápido) dentro de aspas
    cout << "chama" << endl;

    // declaração de variáveis, a tipagem mais usada é int
    // 'tipo' 'nome'; ou 'tipo' 'nome' = 'valor'; também podemos declarar mais de uma varável de uma vez só
    // tipos: int (inteiro), double (float), char (string com UM caractere, não pode ser lido com cin), string (cadeia
    // completa de caracteres, esse sim pode ser lido com cin) e bool (false, true)
    // p/ atualizar valores de variáveis, basta utilizar 'nome = valor_novo'
    int a = 10;
    a = 13;
    cout << "10a + 2 = " << a*10+2 << endl; // 132
    // vários cout's seguidos dá a ideia de concatenação de strings (+)
    cout << a << " " << "e o valor da variavel 'a'. \n" << endl;
    // == print(a + " " + "e o valor da variavel 'a'.", end = "\n") + print()
    // cout "\n" === cout << endl;

    // ex.'s:
    int idade = 33;
    bool vivo = true;
    char letra_favorita = 'x';  // variáveis do tipo char não podem ser lidas com cin
    double dolar = 1.5;
    
    cout << "Tenho " << idade << " anos!" << endl;
    if (vivo) {cout << "Estou vivo!" << endl;}
    else {cout << "Ja morri..." << endl;}
    cout << "Minha letra favorita e '" << letra_favorita << "'." << endl;
    cout << "Neste momento, estou com " << dolar << " dolares!" << endl << endl;

    // cin == input(), porém, mais poderoso
    // Leia --> variável, "leia a variável"
    // o cin procura um dado no input seja lá onde ele esteja, ou seja, na cadeia de caracteres
    // do input, ele mandará o dado p/ uma variável e mandará o outro p/ outra desde estejam separados,
    // seja por espaços, seja por um enter
    int n1, n2;
    cout << "Digite um numero: ";
    cin >> n1;
    cout << "Digite outro valor: ";
    cin >> n2;
    // == cin >> n1 >> n2, o cin vai procurar dois dados, mesmo que estejam separados por um enter
    cout << "A soma entre " << n1 << " e " << n2 << " e igual a " << n1 + n2 << endl << endl;

    // lembrando que: o bit é o menor espaço de informação que o computador consegue guardar
    // representando somente dois estados, 0 ou 1;
    // 1 byte = 8 bits; portanto, com 1 byte podemos representar até 2^8 = 256 valores distintos
    // uma variável do tipo int é formada por 4 bytes = 32 bits, já 
    // o tipo long long é formado por 8 bytes = 64bits

    // ponteiros, tipo de variável que retornam a posição de uma variável na memória do computador
    // para guardar um ponteiro numa variável int precisamos declará-la
    // estrutura: int x; int* p = &x, int *p = &x ou int * p = &x;
    int x = 13;
    int *p = &x;  // a partir daqui, todo '*p' que aparecer significará 'x', ou seja, *p === x
    // imprimindo a posição da variável x na memória (muda toda vez que rodamos o código)
    cout << "A variavel 'x' se encontra na posicao " << p << " na memoria do computador." << endl;
    cout << "x = " << *p << endl;   // imprime o valor de 'x'

    // com isso, podemos declarar funções capazes de modificar os valores originais das variáveis!
    // ex.: fazendo x += 3 utilizando a função add3();
    add3(p); // podemos fazer de forma mais direta: int x = 13; add3(&x); --> x = 16
    cout << "Agora, x = " << x << endl;

    // na declaração de vetores, seus elementos são armazenados um após o outro ('lado a lado')
    // veja:
    int vetor[4];
    for (int x = 0; x < 4; x++) {vetor[x] = x + 1;}
    int *p1 = &vetor[0], *p2 = &vetor[1], *p3 = &vetor[2], *p4 = &vetor[3];
    // poderíamos escrever 'vetor' no lugar de '&vetor[0]', ou seja,
    // int *p1 = &vetor[0] === int *p1 = vetor, *p2 = vetor + 1, ...
    cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    // note que os valores dos p's diferem em 4 bytes (no final da posição), justamente os 4 bytes que um int precisa
    if (p1 + 1 == p2) {cout << "vetor[0] e vetor[1] estao lado a lado na memoria do computador" << endl;}
    if (p1 + 3 == p4) {cout << "vetor[0] e vetor[3] estao a 3*4 = 12 bytes de distancia" << endl;}

    // note que a função sort() utiliza os ponteiros como parâmetros, portanto:
    // sort(vetor+0, vetor+4) === sort(&vetor[0], &vetor[0]+4) === sort(&vetor[0], &vetor[3]+1) === sort(p1, p4 + 1)

    // gerando e excluindo uma variável dinamicamente com os comandos new e delete
    // esturutura: tipo* nome = new tipo(valor); ou new tipo; --> cria uma variável com ponteiro em 'nome'
    int* p5 = new int;
    *p5 = 7;
    cout << "*p5 = " << *p5 << endl;
    int* p6 = new int(5);
    cout << "*p6 = " << *p6 << endl;
    
    // também podemos declarar vetores com o new
    int *p_vetor1 = new int[4];  // cria um vetor com nome "p_vetor1" com 4 posições
    // int p_vetor1 = new int[4]; --> erro
    for (int x = 0; x < 4; x++) {p_vetor1[x] = x+1; cout << "p_vetor1[" << x << "] = " << p_vetor1[x] << "; ";}
    cout << endl << endl;

    // agora, podemos deletar essas variáveis que não iremos mais utilizar
    // estrutura: delete 'nome da variável ou do ponteiro', se for vetor: delete[] 'nome do vetor';
    delete p5;
    delete[] p_vetor1;
    // Quando o programa termina, a memória das variáveis criadas com o new são deletadas automaticamente,
    // então nem sempre é um problema esquecer de liberar a memória. Mas, caso você crie várias variáveis usando o new
    // e não use o delete é criado um lixo de memória. Em programas simples isso normalmente não é um problema,
    // mas caso o lixo de memória fique muito grande ele pode ocupar toda a memória do programa e causar um Runtime Error.

    // utilizando a biblioteca <stdio.h>
    // printf("texto") --> cout << "texto";
    // \ -> vazio; \\ -> "\"; %% -> "%"; \n -> quebra linha; \t -> tabulação
    printf("Bom dia!\n");

    // scanf("texto: %tipo", &variável) --> lê um valor e joga na variável determinada, necessitando especificar um tipo
    // utiliza ponteiro, por isso a necessidade de colocar "&" antes do nome da variável
    // int -> %d; char -> %c; float -> %f; string -> %s;
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("num = %d\n", num); // análogo às f-strings do Python
    
    // Alinhamento
    printf("%3d; 3 casas para a direita\n", num);
    // imprime o valor de x com 3 espaços próprios à direita
    printf("%-3d; 3 casas para a esquerda\n", num);
    // imprime o valor de x com 3 espaços próprios à esquerda
    // como x tem apenas um algarismo, o alinhamento completa com espaços vazios
    
    printf("%03d; 3 casas para a direita, completando com zeros\n", num);
    // imprime o valor de x com 3 espaços próprios à esquerda, completando com zeros

    // swap() --> troca os valores de duas variáveis
    int a = 1, b = 3;
    cout << "Antes a = " << a << "; b = " << b << "\n";
    swap(a, b); // a partir daqui, a = 3 e b = 1
    cout << "Depois, a = " << a << "; b = " << b << "\n";
}