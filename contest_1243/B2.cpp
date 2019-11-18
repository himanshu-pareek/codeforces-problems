#include <iostream>
#include <vector>
using namespace std;

int search (string & s, int l, int r, int c, vector < bool > & v) {
	for (int i = l; i <= r; i++) {
		if (v[i] && (c == s[i])) return i;
	}
	return -1;
}

void swap (char & a, char & b) {
	char temp = a;
	a = b; b = temp;
}

void solve() {
	int n;
	string s, t;
	scanf ("%d", &n);
	cin >> s >> t;
	vector < bool > a (n, false);
	vector < int > count (26, 0);
	int m = 0;
	for (int i = 0; i < n; i++) {
		count[s[i] - 'a']++;
		count[t[i] - 'a']++;
		if (s[i] != t[i]) {
			a[i] = true;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (count[i] % 2) {
			printf ("No\n");
			return;
		}
	}
	printf ("Yes\n");
	vector < pair < int, int > > vec;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			int j;
			j = search (s, i + 1, n - 1, s[i], a);
			if (j != -1) {
				// printf ("%d %d\n", j + 1, i + 1);
				vec.push_back (make_pair (j, i));
				swap (s[j], t[i]);
				a[i] = false;
				if (s[j] == t[j]) {
					a[j] = false;
				}
				continue;
			}
			j = search (t, i + 1, n - 1, t[i], a);
			if (j != -1) {
				// printf ("%d %d\n", i + 1, j + 1);
				vec.push_back (make_pair (i, j));
				swap (s[i], t[j]);
				a[i] = false;
				if (s[j] == t[j]) {
					a[j] = false;
				}
				continue;
			}
			// printf ("%d %d\n", i + 1, i + 1);
			vec.push_back (make_pair (i, i));
			swap (s[i], t[i]);
			j = search (s, i + 1, n - 1, s[i], a);
			if (j != -1) {
				// printf ("%d %d\n", j + 1, i + 1);
				vec.push_back (make_pair (j, i));
				swap (s[j], t[i]);
				a[i] = false;
				if (s[j] == t[j]) {
					a[j] = false;
				}
				continue;
			}
			j = search (t, i + 1, n - 1, t[i], a);
			if (j != -1) {
				// printf ("%d %d\n", i + 1, j + 1);
				vec.push_back (make_pair (i, j));
				swap (s[i], t[j]);
				a[i] = false;
				if (s[j] == t[j]) {
					a[j] = false;
				}
				continue;
			}
		}
	}
	printf ("%lu\n", vec.size());
	for (int i = 0; i < vec.size(); i++) {
		printf ("%d %d\n", vec[i].first + 1, vec[i].second + 1);
	}
}

int main() {
	int k;
	scanf ("%d", &k);
	while (k--) {
		solve();
	}
}

