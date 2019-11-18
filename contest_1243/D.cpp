#include <iostream>
#include <vector>
#include <math.h>
#include <set>

using namespace std;
typedef long long ll;

void max_self (int & a, int b) {
	a = max (a, b);
}

ll gcd (ll a, ll b) {
	if (a == 0) return b;
	return gcd (b % a, a);
}

void dfs (vector < set < int > > & g, vector < bool > & visited, set < int > & toVisit, int s, int n) {
	visited[s] = true; toVisit.erase (s);
	vector < int > new_nodes;
	for (set < int > :: iterator it = toVisit.begin(); it != toVisit.end(); it++) {
		if (!g[s].count (*it)) {
			new_nodes.push_back (*it);
		}
	}
	for (int x : new_nodes) {
		toVisit.erase (x);
	}
	for (int x : new_nodes) {
		dfs (g, visited, toVisit, x, n);
	}
}

void solve () {
	int n, m, u, v;
	scanf ("%d %d", &n, &m);
	vector < set < int > > g (n + 1);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &u, &v);
		g[u].insert (v);
		g[v].insert (u);
	}
	vector < bool > visited (n + 1, false);
	set < int > toVisit;
	for (int i = 1; i <= n; i++) toVisit.insert (i);
	int countCC = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			countCC++;
			dfs (g, visited, toVisit, i, n);
		}
	}
	printf ("%d\n", countCC - 1);
}

int main() {
	int k;
	// scanf ("%d", &k);
	k = 1;
	while (k--) {
		solve();
	}
}

