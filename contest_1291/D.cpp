#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	const int n = (int) s.size();
	vector < vector < int > > count (n + 1, vector < int > (26));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			count[i + 1][j] = count[i][j];
		}
		count[i + 1][s[i] - 'a']++;
	}
	int q, l, r;
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d", &l, &r);
		vector < int > cnt (26);
		 //= count[r] - count[l - 1];
		for (int i = 0; i < 26; i++) {
			cnt[i] = count[r][i] - count[l - 1][i];
		}
		int total = 0;
		for (int x : cnt) {
			if (x > 0) total++;
		}
		if (l == r || total > 2) {
			cout << "Yes" << endl;
		} else {
			if (total == 2 && s[l - 1] != s[r - 1]) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
