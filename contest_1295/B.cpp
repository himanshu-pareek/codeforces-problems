#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		string s;
		cin >> s;
		vector < int > count0 (n + 1), count1 (n + 1);
		for (int i = 0; i < n; i++) {
			count0[i + 1] = count0[i] + (s[i] == '0');
			count1[i + 1] = count1[i] + (s[i] == '1');
		}
		bool inf = false;
		int cnt = count0[n] - count1[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int d = count0[i] - count1[i];
			if (cnt == 0) {
				if (d == x) {
					inf = true;
					break;
				}
			} else {
				if ((x - d) % cnt == 0) {
					int y = (x - d) / cnt;
					if (y >= 0) ans++;
					//cout << i << " " << y << endl;
				}
			}
		}
		if (inf) {
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
