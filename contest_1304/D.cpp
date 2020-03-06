#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector < vector < int > > g;
vector < bool > visited;
vector < int > res;
int current;

void dfs1 (int s) {
	visited[s] = true;
	for (int u : g[s]) {
		if (!visited[u]) {
			dfs1 (u);
		}
	}
	res[s] = current--;
}

void dfs2 (int s) {
	visited[s] = true;
	for (int i = (int) g[s].size() - 1; i >= 0; i--) {
		if (!visited[g[s][i]]) {
			dfs2 (g[s][i]);
		}
	}
	res[s] = current--;
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		int n; string desc;
		cin >> n >> desc;
		g.resize (n);
		for (int i = 0; i < n; i++) {
			g[i].resize (0);
		}
		for (int i = 0; i < (int) desc.size(); i++) {
			if (desc[i] ==  '<') {
				g[i].push_back (i + 1);
			} else {
				g[i + 1].push_back (i);
			}
		}
		res.assign (n, 0);
		visited.assign (n, false);
		current = n;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs1 (i);
			}
		}
		for (int x : res) {
			cout << x << " ";
		}
		cout << endl;
		res.assign (n, 0);
		visited.assign (n, false);
		current = n;
		for (int i = n - 1; i >= 0; i--) {
			if (!visited[i]) {
				dfs2 (i);
			}
		}
		for (int x : res) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
