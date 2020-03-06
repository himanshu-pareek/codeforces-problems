#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, g, b;
		cin >> n >> g >> b;
		ll m = (n + 1) / 2;
		ll num_g = (m - 1) / g;
		ll extra_g = m - num_g * g;
		ll extra_b = 0;
		if (num_g * b < n - m) {
			extra_b = n - m - (num_g * b);
		}
		ll ans = num_g * (g + b) + extra_g + extra_b;
		cout << ans << endl;
	}
	return 0;
} 
