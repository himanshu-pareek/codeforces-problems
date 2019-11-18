#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

template < typename T>
void printVector (const vector < T > & vec) {
    for (const T x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

template < typename T>
void printMatrix (const vector < vector < T > > & mat) {
    for (const vector < T > vec : mat) {
        printVector (vec);
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector < vector < int > > matrix (n, vector < int > (m, 0));
    int x, y;
    vector < int > rows (n, 0);
    vector < int > cols (m, 0);
    for (int i = 0; i < k; i++)  {
        cin >> x >> y;
        x--; y--;
        matrix[x][y] = 1;
        rows[x]++;
        rows[y]++;
    }
    int N = n, M = m;
    while (n > 0 && rows[n - 1] == M) n--;
    while (m > 0 && cols[m - 1] == N) m--;
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    bool flag = true;
    ll X = n * m;
    while (X > 0) {
        if (flag) {
            X -= (right - left + 1);
            top++;
            X -= (bottom - top + 1);
            right--;
        } else {
            X -= (right - left + 1);
            bottom--;
            X -= (bottom - top + 1);
            left++;
        }
        flag = !flag;
    }
    // cout << flag << " " << top << " " << bottom << " " << left << " " << right;
    // int lastX = flag ? bottom : top;
    // int lastY = flag ? left : right;
    
    bool possible = true;
    // cout << "Here" << endl;
    while (k > 0) {
        if (flag) {
            left--;
            for (int i = top; i <= bottom; i++) {
                if (matrix[i][left] == 0 && k > 0) {
                    possible = false;
                    break;
                }
                k--;
            }
            if (!possible) {
                break;
            }
            bottom++;
            for (int i = left; i <= right; i++) {
                if (matrix[bottom][i] == 0 && k > 0) {
                    possible = false;
                    break;
                }
                k--;
            }
            if (!possible) {
                break;
            }
        } else {
            right++;
            for (int i = bottom; i >= top; i--) {
                if (matrix[i][right] == 0 && k > 0) {
                    possible = false;
                    break;
                }
                k--;
            }
            if (!possible) {
                break;
            }
            top--;
            for (int i = right; i >= left; i--) {
                if (matrix[top][i] == 0 && k > 0) {
                    possible = false;
                    break;
                }
                k--;
            }
            if (!possible) {
                break;
            }
        }
        flag = !flag;
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
