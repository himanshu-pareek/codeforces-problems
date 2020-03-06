#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector < string > p (n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			

