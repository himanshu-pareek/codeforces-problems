#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mod = 998244353;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

int add (int a, int b) {
	add_self (a, b);
	return a;
}

void sub_self (int & a, int b) {
	a -= b;
	if (a < 0) a += mod;
}

int sub (int a, int b) {
	sub_self (a, b);
	return a;
}

int mul (int a, int b) {
	return (int)(((ll) a * b) % mod);
}

int power (int a, int k) {
	int ans = 1;
	while (k >= 1) {
		if (k & 1) {
			ans = mul (ans, a);
		}
		a = mul (a, a);
		k >>= 1;
	}
	return ans;
}

int inverse (int a) {
	return power (a, mod - 2);
}

int main() {
	int n, q, u;
	scanf ("%d %d", &n, &q);
	int inv_100 = inverse (100);
	vector < int > p (n);
	for (int & x : p) {
		scanf ("%d", &x);
		x = mul (x, inv_100);
	}
	vector < int > s (n), t (n);
	s[0] = p[0];
	for (int i = 1; i < n; i++) {
		s[i] = mul (s[i - 1], p[i]);
	}
	t[0] = add (1, s[0]);
	for (int i = 1; i < n; i++) {
		t[i] = add (t[i - 1], s[i]);
	}
	s.push_back (s.back()); t.push_back (t.back());
	auto calc = [&] (int i, int j) {
		int x = t[j - 2];
		int y = (i >= 2) ? t[i - 2] : 0;
		sub_self (x, y);
		y = inverse (s[j - 1]);
		return mul (x, y);
	};
	set < int > st;
	for (int i : {0, n}) st.insert (i);
	int answer = calc (0, n);
	cout << answer << endl;
	while (q--) {
		scanf ("%d", &u);
		u--;
		auto lower_it = st.lower_bound (u);
		if (*lower_it == u) {
			// Found u
			// Remove u --- OK
			--lower_it;
			int l = *lower_it;
			++lower_it++;
			int r = *lower_it;
			// Remove calc (l, u) and calc (u, r)
			// Add calc (l, r)
			sub_self (answer, calc (l, u));
			sub_self (answer, calc (u, r));
			add_self (answer, calc (l, r));
			st.erase (u);
		} else {
			// Didn't find u
			// Add u --- OK
			--lower_it;
			int l = *lower_it;
			++lower_it;
			int r = *lower_it;
			// Add calc (l, u) and calc (u, r)
			// Remove calc (l, r)
			add_self (answer, calc (l, u));
			add_self (answer, calc (u, r));
			sub_self (answer, calc (l, r));
			st.insert (u);
		}
		printf ("%d\n", answer);
	}
	return 0;
}
