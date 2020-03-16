#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Educational Codeforces Round #83 (Div. 2)
 * Contest Link : https://codeforces.com/contest/1312
 * Problem : A [ Two Regular Polygons ]
 * Problem Link : https://codeforces.com/contest/1312/problem/A
 */

void solve() {
	int n, m;
	cin >> n >> m;
	if (n % m == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
	int t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
