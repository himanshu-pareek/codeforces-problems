#include <bits/stdc++.h>
// #include <unordered_map>

using namespace std;

int main () {
	
	int n, x;
	cin >> n;
	
	unordered_map < int, int > m;
	
	for (int i = 0; i < n * n; i++) {
		cin >> x;
		if (m.find (x) == m.end()) m[x] = 0;
		m[x]++;
	}
	
	int center = 0, two = 0;
	
	for (unordered_map < int, int > :: iterator it = m.begin(); it != m.end(); it++) {
		switch (it -> second % 4) {
			case 1: center++; break;
			case 2: two++; break;
			case 3: center++; two++; break;
		}
	}
	
	if ((n % 2 == 0 && (center != 0 || two != 0)) || (n % 2 == 1 && (center != 1 || two >= n))) {
		cout << "NO" << endl;
		return 0;
	}
	
	vector < vector < int > > matrix (n, vector < int > (n, 0));
	
	unordered_map < int, int > :: iterator it = m.begin();
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (it -> second == 0) {
				int val = it -> first;
				it++;
				m.erase (val);
			}
			while (it -> second < 4) it++;
			matrix[i][j] = matrix[i][n - 1 - j] = matrix[n - 1 - i][j] = matrix[n - 1 - i][n - 1 - j] = it -> first;
			it -> second -= 4;
		}
	}
	it = m.begin();
	if (n % 2) {
		int i, j;
		j = n / 2;
		for (i = 0; i < n / 2; i++) {
			if (it -> second == 0) {
				int val = it -> first;
				it++;
				m.erase (val);
			}
			while (it -> second < 2) it++;
			matrix[i][j] = matrix[n - 1 - i][j] = it -> first;
			it -> second -= 2;
		}
		i = n / 2;
		for (j = 0; j < n / 2; j++) {
			if (it -> second == 0) {
				int val = it -> first;
				it++;
				m.erase (val);
			}
			while (it -> second < 2) it++;
			matrix[i][j] = matrix[i][n - 1 - j] = it -> first;
			it -> second -= 2;
		}
		it = m.begin();
		matrix[n/2][n/2] = it -> first;
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
