#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

ll cadane (vector < int > & a, int start, int end) {
	ll best = LLONG_MIN, sum = 0;
	for (int i = start; i <= end; i++) {
		sum = max (sum + a[i], (ll)a[i]);
		best = max (best, sum);
	}
	return best;
}

void solve() {
	int n;
	cin >> n;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll sum = 0LL;
	for (int x : a) sum += x;
	ll sum1 = cadane (a, 0, n - 2);
	ll sum2 = cadane (a, 1, n - 1);
	//cout << sum << sum1 << sum2 << endl;
	if (sum > max (sum1, sum2)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
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

