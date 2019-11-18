#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

typedef long long ll;

void printVector (const vector < ll > & vec) {
	for (const ll x : vec) {
		cout << x << "\t";
	}
	cout << endl;
}

ll power (ll n, ll k) {
	if (k == 0)  return 1;
	ll ans = power (n, k / 2);
	ans = (ans * ans) % MOD;
	if (k % 2) ans = (ans * n) % MOD;
	return ans;
}

vector < ll > primeFactors (ll n) {
	vector < ll > primes;
	if (n % 2 == 0) {
		primes.push_back (2);
		while (n % 2 == 0) {
			n /= 2;
		}
	}
	ll k = 3;
	while (k <= sqrt (n)) {
		if (n % k == 0) {
			primes.push_back (k);
		}
		while (n % k == 0) {
			n /= k;
		}
		k += 2;
	}
	if (n > 2) {
		primes.push_back (n);
	}
	return primes;
}

ll h (ll n, ll p) {
	ll sum = 0;
	ll d = 0;
	do {
		d = n / p;
		sum = (sum + d) % (MOD - 1);
		n /= p;
	} while (d != 0);
	return sum;
}

int main() {
	ll x, n;
	cin >> x >> n;
	// cout << x << n << endl;
	vector < ll > primes = primeFactors (x);
	// printVector (primes);
	ll ans = 1;
	for (ll p : primes) {
		ans = (ans * power (p, h (n, p))) % MOD;
	}
	cout << ans << endl;
	return 0;	
}

