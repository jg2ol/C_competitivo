#include <bits/stdc++.h>
using namespace std;

#define int long long
#define maxn 100010
int n, k;
int fat[maxn];

int Exp(int x, int n) {
    if (n == 0) {return 1;}

    int t = Exp(x, n/2);
    if (n % 2 == 0) {return t*t;}
    else {return x*t*t;}
}

int fatorial(int n) {
    if (fat[n] != 0) {return fat[n];}
    if (n == 0) {return fat[0] = 1;}
    else {return fat[n] = n*fatorial(n-1);}
}

int binomial(int n, int k) {
    return fatorial(n)/(fatorial(k)*fatorial(n-k));
}

int32_t main() {
    cin >> n >> k;
}