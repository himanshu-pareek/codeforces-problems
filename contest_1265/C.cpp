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

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > p (n);
	for (int & x : p) scanf ("%d", & x);
	int g = 0, s = 0, b = 0;
	// g = 1;
	int prev = p[0];
	int i = 0;
	while (i < n && prev == p[i]) {
		g++; i++;
	}
	while (s <= g && i < n) {
		prev = p[i]; s++; i++;
	}
	while (i < n && prev == p[i]) {
		s++; i++;
	}
	while (b <= g && i < n) {
		prev = p[i]; b++; i++;
	}
	while (i < n && prev == p[i]) {
		b++; i++;
	}
	int j = n/2;
	int nxt = p[j];
	while (j >= 0 && p[j] == nxt) {
		j--;
	}
	while (i <= j) {
		b++;
		i++;
	}
	
	if (g <= 0 || s <= 0 || b <= 0) {
		printf ("0 0 0\n"); return;
	}
	if (g >= s || g >= b) {
		printf ("0 0 0\n"); return;
	}
	if ((g + s + b) > n / 2) {
		printf ("0 0 0\n"); return;
	}
	
	printf ("%d %d %d\n", g, s, b);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
