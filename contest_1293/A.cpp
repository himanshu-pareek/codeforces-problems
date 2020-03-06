#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int search (vector < int > & a, int x) {
	int low = 0, high = (int) a.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] < x) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

int main() {
	int t, n, s, k;
	cin >> t;
	while (t--) {
		cin >> n >> s >> k;
		vector < int > a (k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}
		sort (a.begin(), a.end());
		int ans;
		for (int dist = 0; ; dist++) {
			if (s - dist > 0 && s - dist <= n) {
				int pos = search (a, s - dist);
				if (pos == -1) {
					ans = dist; break;
				}
			}
			if (s + dist > 0 && s + dist <= n) {
				int pos = search (a, s + dist);
				if (pos == -1) {
					ans = dist; break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

