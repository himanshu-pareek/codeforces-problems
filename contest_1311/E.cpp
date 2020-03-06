#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;


void solve () {
	int n, d;
	cin >> n >> d;
	int left_bound = 0, right_bound = n * (n - 1) / 2;
	for (int i = 1, cd = 0; i <= n; i++) {
		if (!(i & (i - 1))) cd++;
		left_bound += cd - 1;
	}
	if (d < left_bound || d > right_bound) {
		cout << "NO" << endl;
		return;
	}
	vector < int > parent (n);
	vector < int > depth (n);
	vector < int > c_count (n);
	vector < bool > bad (n, false);
	
	parent[0] = -1;
	depth[0] = 0;
	c_count[0] = 1;
	for (int i = 1; i < n; i++) {
		parent[i] = i - 1;
		depth[i] = depth[parent[i]] + 1;
		c_count[i] = 1;
	}
	c_count[n - 1] = 0;
	
	int current_sum = right_bound;
	
	while (current_sum > d) {
		// Find the topmost leaf node
		int v = -1;
		for (int i = 0; i < n; i++) {
			if (!bad[i] && c_count[i] == 0 && (v == -1 || depth[v] > depth[i])) {
				v = i;
			}
		}
		assert (v != -1);
		// Find the node p which has the same depth as v's grandparent
		// and which has less than 2 children
		// and make p parent of v (height of v will be reduced by one)
		int p = -1;
		for (int i = 0; i < n; i++) {
			if (c_count[i] < 2 && depth[v] - depth[i] > 1 && (p == -1 || depth[i] > depth[p])) {
				p = i;
			}
		}
		if (p == -1) {
			bad[v] = true;
			continue;
		}
		assert (depth[v] - depth[p] == 2);
		c_count[parent[v]]--;
		depth[v]--;
		c_count[p]++;
		parent[v] = p;
		current_sum--;
	}
	cout << "YES" << endl;
	for (int i = 1; i < n; i++) {
		cout << parent[i] + 1 << " ";
	}
	cout << endl;
}
	

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
