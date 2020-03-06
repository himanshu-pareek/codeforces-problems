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
		string t;
		int pos = 0;
		bool possible = true;
		vector < bool > visited (26, false);
		for (int i = 0; i < n - 1; i++) {
			int a = s[i], b = s[i + 1];
			if (t.empty()) {
				t += a; t += b; pos = 1;
				visited[a - 'a'] = true;
				visited[b - 'a'] = true;
			} else {
				if (pos > 0 && t[pos - 1] == b) {
					pos--;
				} else if (pos + 1 < t.size() && t[pos + 1] == b) {
					pos++;
				} else if (visited[b - 'a']) {
					possible = false;
					break;
				} else if (pos == 0) {
					t = string (1, b) + t;
					pos = 0;
					visited[b - 'a'] = true;
				} else if (pos + 1 == t.size()) {
					t += b;
					pos = (int) t.size() - 1;
					visited[b - 'a'] = true;
				} else {
					possible = false;
					break;
				}
			}
		}
		if (!possible) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int i = 0; i < 26; i++) {
			if (!visited[i]) {
				t += (char) (i + 'a');
			}
		}
		cout << t << endl;				
	}
	return 0;
} 
