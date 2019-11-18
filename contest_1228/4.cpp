#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

typedef long long ll;

void printMatrix (const vector < vector < int > > &matrix) {
	cout << "----------------------" << endl;
	for (const vector < int > vec : matrix) {
		for (const int x : vec) {
			cout << x << "\t";
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
}

int main () {
    int n, m, u, v;
    cin >> n >> m;
    vector < set < int > > g (n);
    for (int i = 0; i < m; i++) {
    	cin >> u >> v;
    	u--, v--;
    	g[u].insert (v);
    	g[v].insert (u);
    }
    /*
    for (int i = 0; i < n; i++) {
    	sort (g[i].begin(), g[i].end());
    } */
    // printMatrix (g);
    vector < int > groups (n, 0);
    for (int group = 1; group <= 3; group++) {
    	u = -1;
    	for (int i = 0; i < n; i++) {
    		if (groups[i] == 0) {
    			u = i;
    			break;
    		}
    	}
    	if (u == -1) {
    		cout << -1 << endl;
    		return 0;
    	}
    	// groups[u] = group;
    	for (int v = 0; v < n; v++) {
    		if (g[u].find (v) == g[u].end ()) {
    			if (groups[v] != 0) {
    				cout << -1 << endl;
    				return 0;
    			}
    			groups[v] = group;
    		}
    	}
    }
    vector < int > gs[3];
    for (int u = 0; u < n; u++) {
    	if (!groups[u]) {
    		cout << -1 << endl;
    		return 0;
    	}
    	gs[groups[u] - 1].push_back (u);
    }
    
    for (int i = 0; i < 3; i++) {
    	if (gs[i].size() == 0) {
    		cout << -1 << endl;
    		return 0;
    	}
    }
    
    for (int u = 0; u < n; u++) {
    	for (int v : g[u]) {
    		if (groups[u] == groups[v]) {
    			cout << -1 << endl;
    			return 0;
    		}
    	}
    }
    
    ll sz = 0;
    sz += (gs[0].size() * gs[1].size());
    sz += (gs[1].size() * gs[2].size());
    sz += (gs[2].size() * gs[0].size());
    
    if (sz != m) {
    	cout << -1 << endl;
    	return 0;
    }
    
    for (int u = 0; u < n; u++) {
    	cout << groups[u] << " ";
    }
    cout << endl;
    
    
    return 0;
}
