#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fita Colorida
    // solução enorme
    // link: https://neps.academy/br/exercise/49
    int n;
    cin >> n;
    int fita[n], colorida[n];
    for (int x = 0; x < n; x++) {cin >> fita[x];}

    for (int x = 0; x < n; x++) {
        int menor_dist = 1000000, dist[2];
        dist[0] = 1000000; dist[1] = 1000000;

        if (fita[x] == -1) {
            if (x == 0) {for (int a = 0; a < n; a++) {if (fita[a] == 0) {dist[0] = a; break;}}}
            else if (x != n-1) {
                for (int a = x; a >= 0; a--) {if (fita[a] == 0) {dist[0] = x-a; break;}}
                for (int a = x; a < n; a++) {if (fita[a] == 0) {dist[1] = a-x; break;}}
            }
            else {for (int a = n-1; a >= 0; a--) {if (fita[a] == 0) {dist[0] = n-1-a; break;}}}
        }
        else {menor_dist = 0;}

        for (int a = 0; a < 2; a++) {if (dist[a] < menor_dist) {menor_dist = dist[a];}}
        if (menor_dist > 9) {menor_dist = 9;}
        colorida[x] = menor_dist;
    }
    
    for (int i = 0; i < n; i++) {cout << colorida[i] << " ";}
}