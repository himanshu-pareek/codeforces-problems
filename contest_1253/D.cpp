#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 200005;
vector < int > edges[mx];

pii dfs (int u, int p, vector < bool > & visited) {
    visited[u] = true;
    pii pr {u, u};
    for (int v : edges[u]) {
        if (!visited[v]) {
            pair < int, int > x = dfs (v, p, visited);
            pr.first = min (pr.first, x.first);
            pr.second = max (pr.second, x.second);
        }
    }
    return pr;
}

int main() {
    int n, m, u, v;
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &u, &v);
        edges[u].push_back (v);
        edges[v].push_back (u);
    }
    vector < bool > visited (n + 1, false);
    vector < pii > vec;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            pii p = dfs (i, i, visited);
            vec.push_back (p);
        }
    }
    int bigger = -1;
    int ans = 0;
    for (pii p : vec) {
		if (p.first <= bigger) {
			ans++;
		}
		bigger = max (bigger, p.second);
	}
	printf ("%d\n", ans);
    return 0;
}
