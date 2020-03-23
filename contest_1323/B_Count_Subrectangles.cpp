#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Contest : Codeforces Round #626 (Div. 2)
 * Contest URL : https://codeforces.com/contest/1323/
 * Problem : B - Count Subrectangles
 * Problem URL : https://codeforces.com/contest/1323/problem/B
 */

void solve () {
	int m, n;
	ll k;
	scanf ("%d %d %lld", &m, &n, &k);
	vector < int > a (m), b (n);
	for (int & x : a) scanf ("%d", & x);
	for (int & x : b) scanf ("%d", & x);
	for (int i = 1; i < m; i++) {
		if (a[i] == 1) {
			a[i] += a[i - 1];
		}
	}
	for (int j = 1; j < n; j++) {
		if (b[j] == 1) {
			b[j] += b[j - 1];
		}
	}
	vector < int > A (m + 1), B (n + 1);
	for (int i = 0; i < m; i++) {
		A[a[i]]++;
	}
	for (int j = 0; j < n; j++) {
		B[b[j]]++;
	}
	for (int i = m - 1; i >= 0; i--) {
		A[i] += A[i + 1];
	}
	for (int j = n - 1; j >= 0; j--) {
		B[j] += B[j + 1];
	}
	ll answer = 0LL;
	for (int i = 1; (ll) i * i <= k; i++) {
		if (k % i == 0) {
			int j = k / i;
			if (i <= m && j <= n) {
				answer += (ll) A[i] * B[j];
			}
			if (i != j) {
				if (i <= n && j <= m) {
					answer += (ll) A[j] * B[i];
				}
			}
		}
	}
	printf ("%lld\n", answer);
}

int main() {
	int t = 1;
	// scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
