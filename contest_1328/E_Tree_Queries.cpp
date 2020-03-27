/**
 * Contest : Codeforces Round #629 (Div. 3)
 * Contest URL : http://codeforces.com/contest/1328
 * Problem : E - Tree Queries
 * Problem URL : http://codeforces.com/contest/1328/problem/E
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// This section is for Policy Based Data Structure, more precisely Ordered Set.
// All Functions of set works here, in addition we have order_of_key() and find_by_order() function. find_by_order() returns iterator
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<functional>
using namespace __gnu_pbds;

// 1. Custom Set
template < class T, class COMP >
using custom_set = tree < T, null_type, COMP, rb_tree_tag, tree_order_statistics_node_update >;

// 2. Ordered Set
template < class T >
using ordered_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;

// 3. Ordered Multi Set
// For storing multiple occurance of same value we need to use pair. In pair first value is our key and second is useless count variable.
// order_of_key(make_pair(key, 0)) returns first occurance of a value, order_of_key(make_pair(key, INT_MAX)) returns last occurance.
template < class T >
using ordered_multiset = tree < pair < T, int >, null_type, less < pair < T, int > >, rb_tree_tag, tree_order_statistics_node_update >;

// 4. Ordered Map
template < class T, class U >
using ordered_map = tree < T, U, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
// Policy End

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector < set < int > > g;
vector < int > level;
int BITS, n;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= BITS; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : g[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = BITS; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    BITS = ceil(log2(n));
    up.assign(n, vector<int>(BITS + 1));
    dfs(root, root);
}

void level_dfs (int u, int p, int l) {
	level[u] = l;
	for (int v : g[u]) {
		if (v != p) {
			level_dfs (v, u, l + 1);
		}
	}
}

void solve() {
	int m, u, v;
	cin >> n >> m;
	// vector < set < int > > g (n);
	g.resize (n);
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		u--, v--;
		g[u].insert (v);
		g[v].insert (u);
	}
	preprocess (0);
	level.resize (n);
	level_dfs (0, -1, 0);
	while (m--) {
		int k;
		cin >> k;
		bool valid = true;
		vector < int > nodes (k);
		for (int i = 0; i < k; i++) {
			cin >> nodes[i];
			nodes[i]--;
		}
		sort (nodes.begin(), nodes.end(), [&] (const int & a, const int & b) {
			return level[a] < level[b];
		});
		u = nodes.back();
		for (int i = (int) nodes.size() - 1; i >= 0; i--) {
			v = nodes[i];
			int w = lca (u, v);
			if (w == v || (g[w].find (v) != g[w].end())) {
				// kuch nhi
			} else {
				valid = false;
				break;
			}
		}
		if (valid) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}

