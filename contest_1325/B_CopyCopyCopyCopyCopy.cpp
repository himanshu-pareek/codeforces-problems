#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int>;

/**
 * Codeforces Round #628 (Div. 2)
 * Contest Link : http://codeforces.com/contest/1325
 * Problem : B [ CopyCopyCopyCopyCopy ]
 * Problem Link : http://codeforces.com/contest/1325/problem/B
 */

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	unordered_set < int > s;
	for (int x : a) {
		s.insert (x);
	}
	printf ("%d\n", (int) s.size());	
}

int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
