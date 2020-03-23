#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Contest : Codeforces Round #626 (Div. 2)
 * Contest URL : https://codeforces.com/contest/1323
 * Problem : E - Instant Noodles
 * Problem URL : https://codeforces.com/contest/1323/problem/E
 */
 
void solve () {
	int n, m, u, v;
	scanf ("%d %d", &n, &m);
	vector < ll > c (n);
	for (ll & x : c) scanf ("%lld", & x);
	vector < vector < int > > g (n);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		g[v].push_back (u);
	}
	
	map < vector < int >, ll > mp;
	for (int i = 0; i < n; i++) {
		if (g[i].empty()) continue;
		sort (g[i].begin(), g[i].end());
		mp[g[i]] += c[i];
	}
	ll answer = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		answer = __gcd (answer, it -> second);
	}
	printf ("%lld\n", answer);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
