#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << 0 << endl;
		} else if (a < b) {
			int diff = b - a;
			if (diff & 1) cout << 1 << endl;
			else cout << 2 << endl;
		} else {
			int diff = a - b;
			if (diff & 1) cout << 2 << endl;
			else cout << 1 << endl;
		}
	}
	return 0;
}
