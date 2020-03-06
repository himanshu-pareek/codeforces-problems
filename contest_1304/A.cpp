#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		ll x, y, a, b;
		scanf ("%lld %lld %lld %lld", &x, &y, &a, &b);
		ll diff_pos = y - x;
		ll sum_speed = a + b;
		if (diff_pos % sum_speed) {
			printf ("-1\n");
		} else {
			printf ("%lld\n", diff_pos / sum_speed);
		}
	}
	return 0;
}
