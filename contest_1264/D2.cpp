#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void min_self (int & a, int b) {
	if (a > b) a = b;
}

void max_self (int & a, int b) {
	if (a < b) a = b;
}

const int mod = 998244353;

int mult (int a, int b) {
	return (int) (((ll) a * b) % mod);
}

int add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int sub_self (int & a, int b) {
	a -= b;
	if (a < 0) a += mod;
}

int power (int a, int k) {
	int answer = 1;
	while (k >= 1) {
		if (k & 1) {
			answer = mult (answer, a);
		}
		a = mult (a, a);
		k >>= 1;
	}
	return answer;
}

int inverse (int a) {
	// cout << mod << endl;
	return power (a, mod - 2);
}
	

void solve() {
	string s;
	cin >> s;
	const int n = (int) s.size();
	vector < vector < int > > dp (n, vector < int > (n));
	vector < int > count (n + 1);
	for (int i = 0; i < n; i++) {
		count[i + 1] = count[i] + (s[i] == '?');
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (s[i] != '(') {
				add_self (dp[i][j], dp[i + 1][j]);
			}
			if (s[j] != ')') {
				add_self (dp[i][j], dp[i][j - 1]);
			}
			if (s[i] != '(' && s[j] != ')') {
				sub_self (dp[i][j], dp[i + 1][j - 1]);
			}
			if (s[i] != ')' && s[j] != '(') {
				int p = power (2, count[j] - count[i + 1]);
				add_self (p, dp[i + 1][j - 1]);
				add_self (dp[i][j], p);
			}
		}
	}
	printf ("%d\n", dp[0][n - 1]);
}

int main() {
	int t;
	// scanf ("%d", &t);
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
