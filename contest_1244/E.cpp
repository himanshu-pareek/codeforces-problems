#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	int n; ll k;
	cin >> n >> k;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort (a.begin(), a.end());
	int left = 0, right = n - 1;
	int countLeft = 1, countRight = 1;
	while (left < n - 1 && a[left] == a[left + 1]) {
		left++; countLeft++;
	}
	while (right > 0 && a[right] == a[right - 1]) {
		right--; countRight++;
	}
	while (left < right) {
		if (countLeft <= countRight) {
			ll delta = a[left + 1] - a[left];
			if (delta * countLeft > k) {
				delta = k / countLeft;
				a[left] += delta;
				break;
			}
			k -= (delta * countLeft);
			a[left] += delta;
			while (left < n - 1 && a[left] == a[left + 1]) {
				left++; countLeft++;
			}
		} else {
			ll delta = a[right] - a[right - 1];
			if (delta * countRight > k) {
				delta = k / countRight;
				a[right] -= delta;
				break;
			}
			k -= (delta * countRight);
			a[right] -= delta;
			while (right > 0 && a[right] == a[right - 1]) {
				right--; countRight++;
			}
		}
	}
	cout << a[right] - a[left] << endl;
	return 0;
}

