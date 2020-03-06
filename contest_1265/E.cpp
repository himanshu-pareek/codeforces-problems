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
	int n;
	scanf ("%d", & n);
	vector < int > p (n);
	int inv_100 = inverse (100);
	//cout << inv_100 << endl;
	for (int & x : p) {
		scanf ("%d", & x);
		x = mult (x, inv_100);
		//cout << x << " ";
	}
	//cout << endl;
	int sum = 1;
	int prod = 1;
	for (int i = 0; i < n - 1; i++) {
		prod = mult (prod, p[i]);
		add_self (sum, prod);
	}
	prod = mult (prod, p[n - 1]);
	int prod_inv = inverse (prod);
	int answer = mult (sum, prod_inv);
	printf ("%d\n", answer);
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
