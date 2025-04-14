#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    
    vector <pair <int, string>> jog;
    for (int x = 0; x < n; x++) {string j; int h; cin >> j >> h; jog.push_back({h, j});}
    
    sort(jog.begin(), jog.end());

    vector <vector <pair <int, string>>> times;
    for (int x = 0; x < k; x++) {times.push_back({});}
    
    while (!jog.empty()) {
        for (int i = 0; i < k; i++) {
            if (jog.empty()) {break;}
            times[i].push_back(jog[0]);
            jog.erase(jog.begin());
        }
    }

    for (int x = 0; x < k; x++) {
        sort(times[x].begin(), times[x].end());
        cout << "Time " << x+1 << endl;
        for (int i = 0; i < (int)times[x].size(); i++) {cout << times[x][i].second << endl;}
        if (x != k-1) {cout << endl;}
    }
}