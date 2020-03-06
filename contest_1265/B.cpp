#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void min_self (int & a, int b) {
	if (a > b) a = b;
}

void max_self (int & a, int b) {
	if (a < b) a = b;
}

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	vector < pii > dp (n + 1);
	for (int i = 0; i < n; i++) {
		dp[a[i]] = {i, i};
	}
	for (int m = 2; m <= n; m++) {
		min_self (dp[m].first, dp[m - 1].first);
		max_self (dp[m].second, dp[m - 1].second);
	}
	for (int m = 1; m <= n; m++) {
		int left = dp[m].first;
		int right = dp[m].second;
		if (right - left + 1 == m) {
			printf ("1");
		} else {
			printf ("0");
		}
	}
	printf ("\n");
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
