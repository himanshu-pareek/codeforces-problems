#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector < int > x (m);
	for (int i = 0; i < m; i++) {
		cin >> x[i];
		x[i]--;
	}
	
	vector < ll > res (n);
	for (int i = 0; i < m - 1; i++) {
		res[0] += abs (x[i] - x[i + 1]);
	}
	
	vector < int > count (n);
	vector < vector < int > > adj (n);
	for (int i = 0; i < m - 1; i++) {
		int a = x[i], b = x[i + 1];
		if (a != b) {
			adj[a].push_back (b);
			adj[b].push_back (a);
		}
		if (a > b) {
			a^=b^=a^=b;
		}
		if (b - a < 2) {
			continue;
		}
		count[a + 1]++;
		count[b]--;
	}
	
	for (int i = 0; i < n - 1; i++) {
		count[i + 1]+=count[i];
	}
	
	for (int i = 1; i < n; i++) {
		res[i] = res[0] - count[i];
		for (int j : adj[i]) {
			res[i] -= abs (i - j);
			res[i] += j + (j < i);
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}


