#include <bits/stdc++.h>
using namespace std;


int main() {
    // Produto triplo, médio
    // link: https://neps.academy/br/exercise/676
    int n;
    cin >> n;

    long long a[n];
    for (int x = 0; x < n; x++) {cin >> a[x];}

    cout << max(a[0]*a[1]*a[n-1], a[n-3]*a[n-2]*a[n-1]);
}