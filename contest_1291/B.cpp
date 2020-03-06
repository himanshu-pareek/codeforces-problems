#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector < int > a (n);
		for (int & x : a) scanf ("%d", & x);
		int cnt = 0;
		int reach = n / 2;
		for (int mid : {(n - 1) / 2, n / 2}) {
			bool possible = true;
			int ele = 0;
			for (int i = 0; i < mid; i++) {
				if (a[i] < ele) {
					possible = false;
					break;
				}
				ele++;
			}
			if (a[mid] < reach) possible = false;
			ele = reach - 1;
			for (int i = mid + 1; i < n; i++) {
				if (a[i] < ele) {
					possible = false;
					break;
				}
				ele--;
			}
			cnt += possible;
		}
		if (cnt >= 1) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
