#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

const int N = 500005;

vector < pair < int, int > > g[N];
ll dp[N][2];
int k;

int f (int root, int parent) {
	ll curr = 0;
	vector < ll > adds;
	for (pair < int, int > p : g[root]) {
		int v = p.first, w = p.second;
		if (parent == v) continue;
		f (v, root);
		curr += dp[v][0];
		adds.push_back (dp[v][1] + w - dp[v][0]);
	}
	sort (adds.begin(), adds.end(), greater < ll > ());
	for (int i = 0; i < min (k, (int)adds.size()); i++) {
		if (adds[i] > 0) curr += adds[i];
	}
	dp[root][0] = dp[root][1] = curr;
	if (k <= adds.size() && adds[k - 1] > 0) {
		dp[root][1] -= adds[k - 1];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int q, n, u, v, w;
	cin >> q;
	while (q--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) g[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> u >> v >> w;
			u--, v--;
			g[u].push_back ({v, w});
			g[v].push_back ({u, w});
		}
		f (0, -1);
		cout << dp[0][0] << endl;
	}
	return 0;
}

