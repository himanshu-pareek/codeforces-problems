#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n;
	string s, t;
	scanf ("%d", &n);
	cin >> s >> t;
	vector < int > differentInd;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (differentInd.size() == 2) {
				printf ("No\n");
				return;
			}
			differentInd.push_back (i);
		}
	}
	if (differentInd.size() == 0) {
		printf ("Yes\n");
		return;
	}
	if (differentInd.size() == 1) {
		printf ("No\n");
		return;
	}
	int i = differentInd[0], j = differentInd[1];
	if (s[i] == s[j] && t[i] == t[j]) {
		printf ("Yes\n");
	} else {
		printf ("No\n");
	}
}

int main() {
	int k;
	scanf ("%d", &k);
	while (k--) {
		solve();
	}
}

