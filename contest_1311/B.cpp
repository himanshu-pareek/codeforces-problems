#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct DSU {
	vector < int > p, r;
	
	DSU (int n) {
		p.clear(); r.clear();
		p.resize (n); r.resize (n);
	}
	
	void init (int u) {
		p[u] = u;
		r[u] = 1;
	}
	
	int find (int u) {
		if (u != p[u]) p[u] = find (p[u]);
		return p[u];
	}
	
	void merge (int u, int v) {
		u = find (u); v = find (v);
		if (u == v) return;
		if (r[u] < r[v]) swap (u, v);
		else if (r[u] == r[v]) r[u]++;
		p[v] = p[u];
	}
};

void solve(){
	int n, m;
	scanf ("%d %d", &n, &m);
	vector < int > a (n), p (m);
	for (int & x : a) {
		scanf ("%d", &x);
	}
	DSU dsu (n);
	for (int i = 0; i < n; i++) {
		dsu.init (i);
	}
	for (int & x : p) {
		scanf ("%d", &x);
		--x;
		dsu.merge (x, x + 1);
	}
	vector < int > indices (n);
	for (int i = 0; i < n; i++) indices[i] = i;
	sort (indices.begin(), indices.end(), [&] (const int & i, const int & j) {
		if (a[i] == a[j]) return i < j;
		return a[i] < a[j];
	});
	bool possible = true;
	for (int i = 0; i < n; i++) {
		if (dsu.find (i) != dsu.find (indices[i])) {
			possible = false;
			break;
		}
	}
	if (possible) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
