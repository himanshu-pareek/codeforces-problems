#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int main() {
	int q, n, x;
	ll sum;
	cin >> q;
	while (q--) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			sum += x;
		}
		ll avg = sum / n;
		if (avg * n >= sum) {
			cout << avg << endl;
		} else {
			cout << (avg + 1) << endl;
		}
	}
	return 0;
}

