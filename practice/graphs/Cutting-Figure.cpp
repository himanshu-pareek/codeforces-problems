#include <bits/stdc++.h>
using namespace std;
using pii = pair < int, int >;

const int mx = 55;

void min_self (int & a, int b) {
	if (a > b) a = b;
}

vector < vector < int > > discover (mx, vector < int > (mx));
vector < vector < int > > low (mx, vector < int > (mx));
vector < vector < bool > > visited (mx, vector < bool > (mx));

vector < pii > toAdd = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int ttime = 0;
bool hasCP = false;
void dfs (vector < string > & mat, pii u, pii p = {-1, -1}) {
	int x = u.first, y = u.second;
	visited[x][y] = true;
	low[x][y] = discover[x][y] = ttime++;
	int children = 0;
	for (pii add : toAdd) {
		int i = x + add.first, j = y + add.second;
		if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size()) continue;
		if (mat[i][j] == '.') continue;
		if (i == p.first && j == p.second) continue;
		if (visited[i][j]) {
			min_self (low[x][y], discover[i][j]);
		} else {
			dfs (mat, make_pair (i, j), u);
			min_self (low[x][y], low[i][j]);
			if (p.first != -1 && low[i][j] >= discover[x][y]) {
				//cout << "1." << u.first << " " << u.second << endl;
				hasCP = true;
			}
			children++;
		}
	}
	if (p.first == -1 && children > 1) {
		//cout << "2." << u.first << " " << u.second << endl;
		hasCP = true;
	}
}
			
		

int main() {
	int n, m;
	scanf ("%d %d", &m, &n);
	string s;
	vector < string > matrix (m);
	for (int i = 0; i < m; i++) {
		cin >> matrix[i];
	}
	hasCP = false;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == '#' && !visited[i][j]) {
				//cout << "i,j = " << i << ", " << j << endl;
				dfs (matrix, {i, j});
			}
			if (matrix[i][j] == '#') {
				count++;
			}
		}
	}
	if (count < 3) {
		printf ("-1\n");
	} else if (hasCP) {
		printf ("1\n");
	} else {
		printf ("2\n");
	}
	return 0;
}
