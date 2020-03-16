#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Educational Codeforces Round #83 (Div. 2)
 * Contest Link : https://codeforces.com/contest/1312
 * Problem : D [ Count the Arrays ]
 * Problem Link : https://codeforces.com/contest/1312/problem/D
 */

const int mod = 998244353;

template < typename T >
void add_self (T & a, T b) {
	a += b;
	if (a >= mod) a -= mod;
}

template < typename T >
void sub_self (T & a, T b) {
	a -= b;
	if (a < 0) a += mod;
}

int mul (int a, int b) {
	return (ll) a * b % mod;
}

int power (int n, int k) {
	int answer = 1;
	while (k > 0) {
		if (k & 1) answer = mul (answer, n);
		n = mul (n, n);
		k >>= 1;
	}
	return answer;
}

int inverse (int n) {
	return power (n, mod - 2);
}

const int mx = 2e5 + 10;
int fact[mx];

void solve() {
	int n, m;
	scanf ("%d %d", &n, &m);
	// answer is choose (m, n - 1) * pow (2, n - 3)  * (n - 2)
	if (n < 3) {
		printf ("%d\n", 0);
		return;
	}
	
	int fact_mul = mul (fact[n - 1], fact[m - n + 1]);
	int inv_fact_mul = inverse (fact_mul);
	int choose = mul (fact[m], inv_fact_mul);
	int pwr = power (2, n - 3);
	int answer = (n - 2) % mod;
	answer = mul (answer, choose);
	answer = mul (answer, pwr);
	printf ("%d\n", answer);
}

int main() {
	int t = 1;
	fact[0] = 1;
	for (int i = 1; i < mx; i++) {
		fact[i] = mul (fact[i - 1], i);
	}
	//scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
