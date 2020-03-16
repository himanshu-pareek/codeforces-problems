#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Educational Codeforces Round #83 (Div. 2)
 * Contest Link : https://codeforces.com/contest/1312
 * Problem : B [ Bogosort ]
 * Problem Link : https://codeforces.com/contest/1312/problem/B
 */

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", &x);
	sort (a.rbegin(), a.rend());
	for (int x : a) {
		printf ("%d ", x);
	}
	printf ("\n");
}

int main() {
	int t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
