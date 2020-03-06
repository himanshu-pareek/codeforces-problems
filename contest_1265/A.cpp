#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
	string s;
	cin >> s;
	
	s = 'd' + s + 'd';
	const int n = s.size();
	string t = "";
	for (int i = 1; i < n - 1; i++) {
		if (s[i] != '?' && s[i] == s[i + 1]) {
			printf ("-1\n");
			return;
		}
		if (s[i] == '?') {
			for (char c : {'a', 'b', 'c'}) {
				if (s[i - 1] != c && s[i + 1] != c) {
					s[i] = c;
					break;
				}
			}
		}
	}
	cout << s.substr (1, n - 2) << endl;
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
