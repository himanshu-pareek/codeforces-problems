#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;

int main() {
    int n, u, v;
    cin >> n;
    vector < vector < int > > c (3, vector < int > (n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    vector < vector < int > > g (n);
    bool valid = true;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        if (g[u].size() == 2 || g[v].size() == 2) {
            valid = false;
        }
        g[u].push_back (v);
        g[v].push_back (u);
    }
    ll ans = LLONG_MAX, comboIndex = 0;
    if (n == 1) {
        ans = min ({c[0][0], c[1][0], c[2][0]});
        cout << ans << endl;
        for (int i = 0; i < 3; i++) {
            if (ans == c[i][0]) {
                cout << (i + 1) << endl;
                break;
            }
        }
        return 0;
    }
    if (!valid) {
        cout << -1 << endl;
        return 0;
    }
    int leaf = -1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            leaf = i;
            break;
        }
    }
    vector < int > parent (n, -1);
    int node = g[leaf][0], child = leaf;
    while (node != -1) {
        parent[child] = node;
        int nd = -1;
        for (int u : g[node]) {
            if (u != child) {
                child = node;
                nd = u;
                break;
            }
        }
        node = nd;
    }
    

    pair < int , int > combos[] = {{0, 1}, {1, 0}, {0, 2}, {2, 0}, {1, 2}, {2, 1}};
    for (int i = 0; i < 6; i++) {
        int first = combos[i].first;
        int second = combos[i].second;
        ll sum = c[first][leaf] + c[second][parent[leaf]];
        node = parent[parent[leaf]];
        while (node != -1) {
            int current = 3 - (first + second);
            sum += c[current][node];
            node = parent[node];
            first = second;
            second = current;
        }
        if (sum < ans) {
            ans = sum;
            comboIndex = i;
        }
        // ans = min (ans, sum);
    }
    vector < int > b (n);
    cout << ans << endl;
    int first = combos[comboIndex].first;
    int second = combos[comboIndex].second;
    b[leaf] = first;
    b[parent[leaf]] = second;
    // cout << (first + 1) << " " << (second + 1) << " ";
    node = parent[parent[leaf]];
    while (node != -1) {
        int current = 3 - (first + second);
        // sum += c[current][node];
        b[node] = current;
        // cout << (current + 1) << " ";
        node = parent[node];
        first = second;
        second = current;
    }
    for (int color : b) {
    	cout << color + 1 << " ";
    }
    cout << endl;
    // cout << comboIndex << endl;
    return 0;
}
