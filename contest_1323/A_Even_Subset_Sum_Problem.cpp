#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Contest : Codeforces Round #626 (Div. 2)
 * Contest URL : https://codeforces.com/contest/1323/
 * Problem : A - Even Subset Sum Problem
 * Problem URL : https://codeforces.com/contest/1323/problem/A
 */

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	if (n == 1 && (a[0] & 1)) {
		printf ("-1\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!(a[i] & 1)) {
			printf ("1\n%d\n", i + 1);
			return;
		}
	}
	printf ("2\n1 2\n");
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
