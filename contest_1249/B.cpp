#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int dfs (vector < int > & p, vector < int > & ind, vector < bool > & visited, int s) {
    if (visited[s]) return 0;
    visited[s] = true;
    ind.push_back (s);
    return 1 + dfs (p, ind, visited, p[s]);
}

void solve () {
    int n; cin >> n;
    vector < int > p (n);
    for (int i = 0; i < n; i++) {
        cin >> p[i]; p[i]--;
    }
    vector < bool > visited (n, false);
    vector < int > days (n);
    for (int i = 0; i < n; i++){
        if (!visited[i]) {
            vector < int > ind;
            int count = dfs (p, ind, visited, i);
            for (int x : ind) {
                days[x] = count;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << days[i] << " ";
    }
    cout << endl;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        solve ();
    }
}
