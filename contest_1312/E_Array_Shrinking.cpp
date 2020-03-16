#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Educational Codeforces Round #83 (Div. 2)
 * Contest Link : https://codeforces.com/contest/1312
 * Problem : E [ Array Shrinking ]
 * Problem Link : https://codeforces.com/contest/1312/problem/E
 */

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", &x);
	/**
	 * dp[i][j] = -1, if we can't merge from index i to index j
	 * 			= final value of range [i,...,j] after merging, otherwise
	 */
	vector < vector < int > > dp (n, vector < int > (n));
	for (int len = 1; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (len == 1) {
				dp[i][j] = a[i];
			} else {
				dp[i][j] = -1;
				for (int k = i; k < j; k++) {
					if (dp[i][k] != -1 && dp[k + 1][j] != -1 && dp[i][k] == dp[k + 1][j]) {
						dp[i][j] = dp[i][k] + 1;
					}
				}
			}
		}
	}
	
	vector < int > dp2 (n + 1);
	// dp2[i] = min length of final array for subarray [0,..., i - 1]
	for (int i = 1; i <= n; i++) {
		dp2[i] = n;
		for (int j = 0; j < i; j++) {
			if (dp[j][i - 1] != -1) {
				dp2[i] = min (dp2[i], dp2[j] + 1);
			}
		}
	}
	
	printf ("%d\n", dp2[n]);
}

int main() {
	int t = 1;
	//scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
