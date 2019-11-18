#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void min_self (int & a, int b) {
	a = min (a, b);
}

int main() {
    int n, m, u, v;
    scanf ("%d %d", &n, &m);
    vector < pii > a (n);
    for (pii & p : a) scanf ("%d %d", & (p.first), & (p.second));
    vector < int > covered (m + 5, 0);
    for (int i = 0; i < n; i++) {
		a[i] = {max (0, a[i].first - a[i].second), min (m, a[i].first + a[i].second)};
		covered[max (1, a[i].first)]++;
		covered[min (m, a[i].second) + 1]--;
	}
	for (int i = 1; i <= m; i++) {
		covered[i] += covered[i - 1];
	}
	vector < int > dp (m + 1, INT_MAX);
	dp[m] = 0;
	for (int x = m - 1; x >= 0; x--) {
		if (covered[x + 1] > 0) {
			dp[x] = dp[x + 1];
		} else {
			dp[x] = m - x;
			for (pii p : a) {
				if (p.first > x + 1) {
					min_self (dp[x], p.first - x - 1 + dp[min (m, p.second + p.first - x - 1)]);
				}
			}
		}
	}
	printf ("%d\n", dp[0]);
    return 0;
}
