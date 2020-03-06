#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

vector < pii > toAdd ({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
vector < char > chars;

int getNextIndex (vector < int > & count, int current) {
	int next = (count[current] > 0) ? current : (1 + current);
	count[next]--;
	return next;
}

void solve() {
    int r, c, k;
    scanf ("%d %d %d", &r, &c, &k);
    vector  < string > mat (r);
    for (int i = 0; i < r; i++) {
        cin >> mat[i];
    }
    
    vector < int > count (k);
    int R = 0;
    for (string s : mat) {
        for (char d : s) {
            R += (d == 'R');
        }
    }
    
    for (int i = 0; i < k; i++) {
        // cout << "R = " << R << endl;
        count[i] = ceil ((float) R / (k - i));
        R -= count[i];
    }
    
    int left = 0, top = 0;
    int right = c - 1, bottom = r - 1;
    int TOTAL = r * c;
    bool flag = true;
    int index = 0;
    while (TOTAL > 0) {
        if (flag) {
			// Go from left to right and then from top to bottom
			for (int j = left; j <= right; j++) {
				if (mat[top][j] == 'R') {
					index = getNextIndex (count, index);
				}
				mat[top][j] = chars[index];
				TOTAL--;
			}
			top++;
			for (int i = top; i <= bottom; i++) {
				if (mat[i][right] == 'R') {
					index = getNextIndex (count, index);
				}
				mat[i][right] = chars[index];
				TOTAL--;
			}
			right--;
		} else {
			// Go from right to left and then from bottom to up
			for (int j = right; j >= left; j--) {
				if (mat[bottom][j] == 'R') {
					index = getNextIndex (count, index);
				}
				mat[bottom][j] = chars[index];
				TOTAL--;
			}
			bottom--;
			for (int i = bottom; i >= top; i--) {
				if (mat[i][left] == 'R') {
					index = getNextIndex (count, index);
				}
				mat[i][left] = chars[index];
				TOTAL--;
			}
			left++;
		}
		flag = !flag;
    }
    for (int i = 0; i < r; i++) {
        cout << mat[i] << endl;
    }
}

int main() {
    int T;
    for (char c = 'a'; c <= 'z'; c++) {
        chars.push_back (c);
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        chars.push_back (c);
    }
    for (char c = '0'; c <= '9'; c++) {
        chars.push_back (c);
    }
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
}
