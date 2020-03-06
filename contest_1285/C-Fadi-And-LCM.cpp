#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lcm (ll a, ll b) {
	return a / __gcd (a, b) * b;
}

int main() {
	ll x;
	scanf ("%lld", &x);
	ll ans;
	for (ll i = 1; i * i <= x; i++) {
		if (x % i == 0 && lcm (i, x /i) == x) {
			ans = i;
		}
	}
	printf ("%lld %lld\n", ans, x / ans);
	return 0;
}
