#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd (ll a, ll b) {
	if (a == 0) return b;
	return gcd (b % a, a);
}

ll phi (ll n) {
	ll answer = n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			answer -= answer / i;
		}
	}
	if (n > 1) {
		answer -= answer / n;
	}
	return answer;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, m;
		cin >> a >> m;
		cout << phi (m / gcd (a, m)) << endl;
	}
	return 0;
}
