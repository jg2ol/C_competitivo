#include <bits/stdc++.h>
using namespace std;

// busca binária + menor caminho
// qual a altura mínima para ir de 1 a n com preço menor que k, ou -1
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int INF = 1e14+10;
#define maxn 100100

int n, m;
ll k;
ll dist[maxn];
bool mark[maxn];
vector<pair<int, pll>> grafo[maxn];

bool dijkstra(ll S) {
    for (int x = 1; x <= n; x++) {dist[x] = INF;}
    dist[S] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> fila;
    fila.push({0, S});
    while (!fila.empty()) {
        ll u = fila.top().second;
        fila.pop();
        if (mark[u]) {continue;}
        mark[u] = true;
        for (auto v : grafo[u]) {
            int viz = v.first;
            ll peso = v.second.first, altura = v.second.second;
            if (dist[viz] > dist[u]+peso && altura <= S) {dist[viz] = dist[u]+peso; fila.push({dist[viz], viz});}
        }
    }
    if (dist[n] < k) {return true;}
    return false;
}

int main() {
    cin >> n >> m >> k;
    for (int x = 0; x < m; x++) {
        int a, b;
        ll p, h;
        cin >> a >> b >> p >> h;
        grafo[a].push_back({b, {p, h}});
        grafo[b].push_back({a, {p, h}});
    }
    if (!dijkstra(1)) {cout << "-1\n";}
    else {
        ll i = 1, f = INF;
        while (i <= f) {
            ll m = (i+f)/2;
            if (dijkstra(m)) {f = m;}
            else {i = m+1;}
        }
        cout << f << "\n";
    }
    return 0;
}
