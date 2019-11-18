#include <iostream>
#include <vector>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll min (ll a, ll b) {
	return a < b ? a : b;
}

ll vectorSum (const vector < int > & vec, int left, int right) {
	ll sum = 0;
	for (int i = left; i <= right; i++) {
		sum += vec[i];
	}
	return sum;
}

int main() {
	ll n, k;
	cin >> n >> k;
	// vector < int > visited (n + 1, false);
	// index starts from 1
	k = k - n * (n + 1) / 2;
	if (k < 0) {
		cout << -1 << endl;
		return 0;
	}
	vector < int > a (n + 1);
	for (int i = 1; i <= n; i++) a[i] = i;
	int last = n;
	for (int i = 1; i <= n; i++) {
		ll element = min (i + k, last);
		k -= (element - i);
		last = element - 1;
		if (element > i) {
			a[element] = i;
			a[i] = element;
		}
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += max (i, a[i]);
	}
	cout << sum << endl;
	for (int i = 1; i <= n; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}


