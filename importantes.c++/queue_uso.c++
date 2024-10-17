#include <bits/stdc++.h>
using namespace std;

// uso do queue
// o último time que sobra na fila é o vencedor
// link: https://neps.academy/br/exercise/276

int main() {
    queue <char> times;
    times.push('A');
    times.push('B');
    times.push('C');
    times.push('D');
    times.push('E');
    times.push('F');
    times.push('G');
    times.push('H');
    times.push('I');
    times.push('J');
    times.push('K');
    times.push('L');
    times.push('M');
    times.push('N');
    times.push('O');
    times.push('P');
    for (int x = 0; x < 15; x++) {
        int a1, a2;
        cin >> a1 >> a2;
        if (a1 < a2) {times.pop(); times.push(times.front()); times.pop();}
        else {times.push(times.front()); times.pop(); times.pop();}
    }
    cout << times.front();
}