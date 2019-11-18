#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef long long ll;

void max_self (int & a, int b) {
	a = max (a, b);
}

ll gcd (ll a, ll b) {
	if (a == 0) return b;
	return gcd (b % a, a);
}

void solve () {
	ll n;
	scanf ("%lld", &n);
	ll g = n;
	for (ll x = 2; x <= sqrt (n); x++) {
		if (n % x == 0) {
			g = gcd (g, x);
			g = gcd (g, n / x);
		}
	}
	printf ("%lld\n", g);
}

int main() {
	int k;
	// scanf ("%d", &k);
	k = 1;
	while (k--) {
		solve();
	}
}

