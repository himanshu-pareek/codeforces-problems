#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Educational Codeforces Round #83 (Div. 2)
 * Contest Link : https://codeforces.com/contest/1312
 * Problem : C [ Adding Powers ]
 * Problem Link : https://codeforces.com/contest/1312/problem/C
 */

void solve() {
	int n, k;
	scanf ("%d %d", &n, &k);
	vector < ll > a (n);
	for (ll & x : a) scanf ("%lld", &x);
	vector < bool > visited (64, false);
	for (ll x : a) {
		ll y = x;
		vector < int > rep;
		while (y > 0) {
			ll div = y / k;
			int rem = y % k;
			if (rem > 1) {
				cout << "NO" << endl;
				return;
			}
			rep.push_back (rem);
			y = div;
		}
		// reverse (rep.begin(), rep.end());
		//cout << x << " = ";
		//for (int x : rep) cout << x << " ";
		//cout << endl;
		for (int i = 0; i < rep.size(); i++) {
			if (rep[i] != 0) {
				if (visited[i]) {
					cout << "NO" << endl;
					return;
				}
				visited[i] = true;
			}
		}
	}
	cout << "YES" << endl;
}

int main() {
	int t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
