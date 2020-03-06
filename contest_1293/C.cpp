#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, q, r, c;
	scanf ("%d %d", &n, &q);
	map < int, int > diag11, diag12;
	map < int, int > diag21, diag22;
	map < int, int > col1, col2;
	vector < vector < int > > mat (3, vector < int > (n + 1, 0));
	for (int i = 0; i < q; i++) {
		scanf ("%d %d", &r, &c);
		int d1 = c - r;
		int d2 = r + c;
		mat[r][c] = 1 - mat[r][c];
		if (mat[r][c] == 0) {
			// Remove lave
			if (diag12.count (d1)) {
				diag12.erase (d1);
				diag11[d1]++;
			} else {
				diag11.erase (d1);
			}
			
			if (diag22.count (d2)) {
				diag22.erase (d2);
				diag21[d2]++;
			} else {
				diag21.erase (d2);
			}
			
			if (col2.count (c)) {
				col2.erase (c);
				col1[c]++;
			} else {
				col1.erase (c);
			}
		} else {
			// Put lava
			if (diag11.find (d1) != diag11.end()) {
				diag11.erase (d1);
				diag12[d1]++;
			} else {
				diag11[d1]++;
			}
			
			if (diag21.find (d2) != diag21.end()) {
				diag21.erase (d2);
				diag22[d2]++;
			} else {
				diag21[d2]++;
			}
			
			if (col1.find (c) != col1.end()) {
				col1.erase (c);
				col2[c]++;
			} else {
				col1[c]++;
			}
		}
		if (!diag12.empty() || !diag22.empty() || !col2.empty()) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
	return 0;
}

