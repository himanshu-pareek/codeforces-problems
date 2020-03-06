#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		const int n = s.size();
		int first = 0, last = n - 1;
		while (first < n && s[first] == '0') {
			first++;
		}
		while (last >= 0 && s[last] == '0') {
			last--;
		}
		int cnt = 0;
		for (int i = first; i <= last; i++) {
			if (s[i] == '0') cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
} 
