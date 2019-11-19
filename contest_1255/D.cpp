#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

vector < pii > toAdd ({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
vector < char > chars;

void solve() {
    int r, c, k;
    scanf ("%d %d %d", &r, &c, &k);
    vector  < string > mat (r);
    for (int i = 0; i < r; i++) {
        cin >> mat[i];
    }
    // for (int i = 0; i < r; i++) {
    //     cout << mat[i] << endl;
    // }
    // return;
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
    // cout << "here" << endl;
    // return;
    // for (int i = 0; i < k; i++) {
    //     cout << count[i] << " ";
    // }
    // cout << endl;
    // return;
    vector < vector < bool > > visited (r, vector < bool > (c, false));
    for (int x = 0; x < k; x++) {
        int max_count = count[x];
        queue < pii > q;
        while (max_count) {
            pii start;
            for (int i = 0; i < r; i++) {
                bool found = false;
                for (int j = 0; j < c; j++) {
                    if (!visited[i][j]) {
                        start = {i, j};
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            q.push (start);
            visited[start.first][start.second] = true;
            if (mat[start.first][start.second] == 'R') {
                max_count--;
            }
            while (!q.empty()) {
                pii p = q.front(); q.pop();
                mat[p.first][p.second] = chars[x];
                for (pii add : toAdd) {
                    int x = p.first + add.first;
                    int y = p.second + add.second;
                    if (x >= 0 && y >= 0 && x < r && y < c && !visited[x][y]) {
                        if (max_count == 0) {
                            break;
                        }
                        q.push ({x, y});
                        visited[x][y] = true;
                        if (mat[x][y] == 'R') {
                            max_count--;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == '.') {
                mat[i][j] = chars[0];
            }
        }
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
