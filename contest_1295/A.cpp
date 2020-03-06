#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n & 1) { cout << 7; n-=3; }
		while (n > 0) {
			cout << 1;
			n -= 2;
		}
		cout << endl;
	}
	return 0;
}
