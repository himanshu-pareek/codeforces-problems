#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	double ans = 0.0;
	for (int s = n; s >= 1; s--) {
		ans += 1.0 / (double) s;
	}
	printf ("%.8lf\n", ans);
	return 0;
}

