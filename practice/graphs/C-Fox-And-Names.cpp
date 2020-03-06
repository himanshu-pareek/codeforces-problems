#include <bits/stdc++.h>
using namespace std;

// Definng colors
// not visited - white
// currently active - gray
// visited - black
// cycle if encounter node with 
// color gray
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector < int > color, order;
vector < set < int > > g;
bool possible;

void dfs (int u) {
	color[u] = GRAY;
	for (auto it = g[u].rbegin(); it != g[u].rend(); it++) {
		int v = *it;
		if (color[v] == GRAY) {
			possible = false;
			return;
		}
		if (color[v] == WHITE) {
			dfs (v);
		}
	}
	order.push_back (u);
	color[u] = BLACK;
}

int main() {
	int n;
	possible = true;
	scanf ("%d", &n);
	string s, t;
	g.resize (26);
	for (int i = 0; i < 26; i++) {
		g[i].clear();
	}
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (i > 0) {
			// compare s and t and make edge
			int index = 0;
			while (index < s.size() && index < t.size() && s[index] == t[index]) {
				index++;
			}
			if (index == t.size()) {
				// t is smaller than s
				// but after s in i/p
				// so impossible
				possible = false;
			} else if (index == s.size()) {
				// s is smaller than t
				// and before t in i/p
				// so possible for every ordering
				// DO NOTHIG
			} else {
				// s[index] < t[index]
				g[s[index] - 'a'].insert (t[index] - 'a');
			}
			//cout << index << endl;
		}
		s = t;
	}
	if (!possible) {
		printf ("Impossible\n");
		return 0;
	}
	color.assign (26, WHITE);
	order.resize (0);
	for (int i = 25; i >= 0; i--) {
		if (color[i] == WHITE) {
			dfs (i);
		}
	}
	if (!possible) {
		printf ("Impossible\n");
	} else {
		reverse (order.begin(), order.end());
		for (int o : order) {
			printf ("%c", o + 'a');
		}
		printf ("\n");
	}
	return 0;
}
