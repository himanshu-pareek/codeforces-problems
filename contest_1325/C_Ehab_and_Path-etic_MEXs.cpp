#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int>;

/**
 * Codeforces Round #628 (Div. 2)
 * Contest Link : http://codeforces.com/contest/1325
 * Problem : C [ Ehab and Path-etic MEXs ]
 * Problem Link : http://codeforces.com/contest/1325/problem/C
 */

void solve() {
	int n;
	scanf ("%d", &n);
	vector < vector < pii > > g (n);
	int u, v;
    vector < int > label (n - 1, -1);
	for (int i = 1; i < n; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		g[u].push_back (make_pair (v, i - 1));
		g[v].push_back (make_pair (u, i - 1));
	}
	int num = 0;
    for (int u = 0; u < n; u++) {
        if (g[u].size() >= 3) {
            label[g[u][0].second] = 0;
            label[g[u][1].second] = 1;
            label[g[u][2].second] = 2;
            num = 3;
            break;
        }
    }
	for (int i = 0; i < n - 1; i++) {
        if (label[i] == -1) {
            label[i] = num++;
        }
    }
    for (int x : label) {
        printf ("%d ", x);
    }
    printf ("\n");
}

int main() {
	int T = 1;
	//scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
