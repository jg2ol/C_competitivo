#include <bits/stdc++.h>
using namespace std;

int main() {
    // código utilizando variáveis do tipo bool
    // link: https://neps.academy/br/exercise/52
    int n;
    bool a = false, b =  false;
    cin >> n;

    for (int x = 0; x < n; x++) {
        int i;
        cin >> i;
        if (i == 1) {
            a = !a;
        } else {
            a = !a;  // --> uso do not
            b = !b;
        };
    };

    if (a) {cout << 1 << "\n";} else {cout << 0 << "\n";}
    if (b) {cout << 1 << "\n";} else {cout << 0 << "\n";}
}