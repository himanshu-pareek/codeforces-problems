#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct customer {
	ll t, l, h;
};

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector < customer > customers (n);
		for (int i = 0; i < n; i++) {
			cin >> customers[i].t >> customers[i].l >> customers[i].r;
		}
		ll temp_low = temp_high = prev_temp = m;
		ll previous_time = 0;
		bool possible = true;
		for (int i = 0; i < n; i++) {
			customer c = customers[i];
			ll time_diff = c.t - previous_time;
			ll min_possible = prev_temp - time_diff;
			ll max_possible = prev_temp + time_diff;
			if (min_possible > c.h || max_possible < c.l) {
				possible = false;
				break;
			}
			if (i + 1 < n) {
				customer next_c = customers[i + 1];
				if (
	}
	return 0;
}
