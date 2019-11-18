#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main() {
	int q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		vector < int > a (n);
		vector < int > minIndex (n + 1, INT_MAX), maxIndex (n + 1, INT_MIN);
		vector < int > count (n + 1, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			count[a[i]]++;
			minIndex[a[i]] = min (minIndex[a[i]], i);
			maxIndex[a[i]] = max (maxIndex[a[i]], i);
		}
		vector < int > s;
		for (int i = 1; i <= n; i++) {
			if (count[i]) s.push_back (i);
		}		
		int maxLen = 1, currLen = 1;
		for (int i = 0; i < s.size() - 1; i++) {
			if (maxIndex[s[i]] < minIndex[s[i + 1]]) {
				currLen++;
			} else {
				currLen = 1;
			}
			maxLen = max (maxLen, currLen);
		}
		cout << (s.size() - maxLen) << endl;
	}
	return 0;
}

