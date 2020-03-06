#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve () {
	int n, m;
	scanf ("%d %d", &n, &m);
	string s;
	cin >> s;
	//cout << n << " => " << s << endl;
	assert (s.size() == n);
	vector < int > p (m);
	for (int & x : p) {
		scanf ("%d", &x);
	}
	vector < int > cnt (n + 1);
	for (int x : p) {
		cnt[x - 1]++;
	}
	vector < int > count (26);
	for (int i = n - 1; i >= 0; i--) {
		cnt[i] += cnt[i + 1];
		count[s[i] - 'a'] += cnt[i] + 1;
	}
	for (int c : count) {
		cout << c << " ";
	}
	cout << endl;
}
	

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
