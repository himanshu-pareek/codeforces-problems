#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void min_self (int & a, int b) {
	if (a > b) a = b;
}

void max_self (int & a, int b) {
	if (a < b) a = b;
}

void solve() {
	vector < int > nums(4);
	int total = 0;
	for (int & x : nums) {
		scanf ("%d", & x);
		total += x;
	}
	for (int start = 0; start < 4; start++) {
		if (nums[start]) {
			vector < int > curr = nums;
			int last = start;
			curr[last]--;
			vector < int > ans;
			ans.push_back (last);
			for (int i = 0; i < total - 1; i++) {
				if (last > 0 && curr[last - 1] > 0) {
					// take last - 1
					last = last - 1;
				} else if (last < 3 && curr[last + 1] > 0) {
					last = last + 1;
				} else {
					break;
				}
				curr[last]--;
				ans.push_back (last);
			}
			if (ans.size() == total) {
				// We got a solution
				printf ("YES\n");
				for (int x : ans) {
					printf ("%d ", x);
				}
				printf ("\n");
				return;
			}
		}
	}
	printf ("NO\n");
}

int main() {
	int t;
	// scanf ("%d", &t);
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
