#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
	int n;
	cin >> n;
	vector < pii > a (n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort (a.begin(), a.end());
	vector < vector < int > > dp (n + 1, vector < int > (2));
	dp[n][0] = 0; dp[n][1] = 1;
	for (int i = n - 1; i > 0; i--) {
		// Calculate dp[i][0]
		// Don't take i
		// Use dp[i + 1][1]
		
}

int main() {
	ios::sync_with_stdio (false);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

