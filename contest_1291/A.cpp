#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int countOdd = 0;
		char first, second;
		for (char c : s) {
			if (1 & (c - '0')) {
				if (countOdd == 0) {
					first = c;
					countOdd++;
				} else if (countOdd == 1) {
					second = c;
					countOdd++;
					break;
				}
			}
		}
		if (countOdd < 2) {
			cout << -1 << endl;
		} else {
			cout << first << second << endl;
		}
	}
	return 0;
}
