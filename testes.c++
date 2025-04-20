#include <bits/stdc++.h>
using namespace std;

int pai[100100], inimigo[100100], peso[100100];

int find(int x) {
    if (pai[x] == x) {return x;}
    else {return pai[x] = find(pai[x]);}
}

void setFriends(int x, int y) {
    x = find(x);
    y = find(y);
    if (inimigo[x] == y or inimigo[y] == x) {cout << -1 << endl; return;}
    if (x != y) {
        if (peso[x] < peso[y]) {pai[x] = y;}
        else if (peso[x] > peso[y]) {pai[y] = x;}
        else {pai[x] = y; peso[y]++;}
    }
}

void setEnemies(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {cout << -1 << endl;}
    else {inimigo[x] = y; inimigo[y] = x;}
}

bool areFriends(int x, int y) {
    x = find(x);
    y = find(y);
    if (inimigo[x] == inimigo[y] or x == y) {return true;}
    else {return false;}
}
bool areEnemies(int x, int y) {
    x = find(x);
    y = find(y);
    if (inimigo[x] == y or inimigo[y] == x) {return true;}
    else {return false;}
}

int main() {
    int n;
    cin >> n;
    for (int x = 0; x < n; x++) {pai[x] = x; inimigo[x] = -x;}
    while (true) {
        int c, x, y;
        cin >> c >> x >> y;

        if (c == 1) {setFriends(x, y);}
        if (c == 2) {setEnemies(x, y);}
        if (c == 3) {if (areFriends(x, y)) {cout << 1;} else {cout << 0;} cout << endl;}
        if (c == 4) {if (areEnemies(x, y)) {cout << 1;} else {cout << 0;} cout << endl;}

        if (c == 0) {break;}
    }
}
// 10
// 1 0 1
// 1 1 2
// 2 0 5
// 3 0 2
// 3 8 9
// 4 1 5
// 4 1 2
// 4 8 9
// 1 8 9
// 1 5 2
// 3 5 2
// 0 0 0