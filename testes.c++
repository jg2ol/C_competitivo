#include <bits/stdc++.h>
using namespace std;


int main() {
    int c = 0;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {break;}
        c++;
        
        cout << "Teste " << c << endl;
        
        int ans = 1;
        for (int x = 0; x < n; x++) {ans *= 2;}
        cout << ans - 1 << endl;
        cout << endl;
    }
}