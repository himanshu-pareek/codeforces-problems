#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;
		const int n = s.size();
		const int m = t.size();
		vector < vector < int > > indices (26);
		for (int i = 0; i < n; i++) {
			indices[s[i] - 'a'].push_back (i);
		}
		vector < int > pointers (26, 0);
		int iteration = 0;
		int previousIndex = -1;
		bool possible = true;
		
		auto search_bin = [&] (int c, int ind) {
			int low = pointers[c], high = (int) (indices[c].size()) - 1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (indices[c][mid] > ind) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			return low;
		};
		
		for (int i = 0; i < m; i++) {
			int d = t[i] - 'a';
			if (indices[d].empty()) {
				possible = false;
				break;
			}
			int ind = search_bin (d, previousIndex);
			if (ind >= indices[d].size()) {
				iteration++;
				for (int j = 0; j < 26; j++) pointers[j] = 0;
				ind = 0;
			}
			previousIndex = indices[d][ind];
			pointers[d]++;
		}
		if (!possible) {
			cout << -1 << endl;
		} else {
			cout << (iteration + 1) << endl;
		}
	}
	return 0;
}
