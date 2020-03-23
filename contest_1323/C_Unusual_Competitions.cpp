#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Contest : Codeforces Round #626 (Div. 2)
 * Contest URL : https://codeforces.com/contest/1323/
 * Problem : C - Unusual Competitions
 * Problem URL : https://codeforces.com/contest/1323/problem/C
 */

void solve () {
	int n; string s;
	cin >> n >> s;
	assert (n == s.size());
	int answer = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		count += s[i] == '(';
		count -= s[i] == ')';
		// if (count == -1) answer += 2;
		if (count < 0 || (s[i] == '(' && count == 0)) answer++;
	}
	if (count != 0) {
		answer = -1;
	}
	printf ("%d\n", answer);
}

int main() {
	int t = 1;
	// scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
