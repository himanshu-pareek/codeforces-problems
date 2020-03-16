#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int>;

/**
 * Codeforces Round #628 (Div. 2)
 * Contest Link : http://codeforces.com/contest/1325
 * Problem : A [ EhAb AnD gCd ]
 * Problem Link : http://codeforces.com/contest/1325/problem/A
 */

void solve() {
	int x;
	scanf ("%d", &x);
	//for (int i = 1; (ll) i * i <= x; i++) {
		//if (x % i == 0) {
			//for (int g : {i, x / i}) {
				//int cd = (x / g) - 1;
				//for (int c = 1; (ll) c * c <= cd; c++) {
					//if (cd % c == 0) {
						//int d = cd / c;
						//if (__gcd (c, d) == 1) {
							//cout << g * c << " " << g * d << endl;
							//return;
						//}
					//}
				//}
			//}
		//}
	//}
	cout << 1 << " " << (x - 1) << endl;
}

int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
