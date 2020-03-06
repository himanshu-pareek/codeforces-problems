#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 2e6 + 10;

struct DSU {
	vector < int > p, r;
	
	DSU (int n) {
		p.assign (n, -1);
		r.assign (n, 0);
	}
	
	void init (int i) {
		p[i] = i;
		r[i] = 1;
	}
	
	int find (int u) {
		if (u != p[u]) p[u] = find (p[u]);
		return p[u];
	}
	
	bool merge (int u, int v) {
		u = find (u);
		v = find (v);
		if (u == v) return false;
		if (r[u] < r[v]) {
			swap (u, v);
		} else if (r[u] == r[v]) {
			r[u]++;
		}
		p[v] = u;
		return true;
	}
};

int n, m;

vector < pii > toAdd = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void calc (vector < int > & diff, vector < pii > & s, int coefficient) {
	vector < vector < int > > a (n, vector < int > (m));
	DSU dsu (n * m);
	for (int i = 0; i < n * m; i++) {
		dsu.init (i);
	}
	for (pii p : s) {
		int currentIncrease = 1;
		int x = p.first / m, y = p.first % m;
		a[x][y] = 1;
		for (pii q : toAdd) {
			int i = x + q.first, j = y + q.second;
			if (i >= 0 && j >= 0 && i < n && j < m && a[i][j] == 1) {
				currentIncrease -= dsu.merge (p.first, m * i + j);
			}
		}
		diff[p.second] += coefficient * currentIncrease;
	}
}

int main() {
	int q, x, y, c;
	scanf ("%d %d %d", &n, &m, &q);
	vector < vector < pii > > addQuery (mx), delQuery (mx);
	vector < vector < int > > a (n, vector < int > (m));
	for (int i = 0; i < q; i++) {
		scanf ("%d %d %d", &x, &y, &c);
		x--, y--;
		int index = m * x + y;
		if (a[x][y] == c) continue;
		addQuery[c].push_back (make_pair (index, i));
		delQuery[a[x][y]].push_back (make_pair (index, i));
		a[x][y] = c;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int index = m * i + j;
			delQuery[a[i][j]].push_back (make_pair (index, q));
		}
	}
	for (int i = 0; i <= c; i++) {
		reverse (delQuery[i].begin(), delQuery[i].end());
	}
	vector < int > diff (q + 1);
	for (int i = 0; i <= c; i++) {
		calc (diff, addQuery[i], 1);
	}
	for (int i = 0; i <= c; i++) {
		calc (diff, delQuery[i], -1);
	}
	
	int components = 1;
	for (int i = 0; i < q; i++) {
		components += diff[i];
		printf ("%d\n", components);
	}
	return 0;
}
	
