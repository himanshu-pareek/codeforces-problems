#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

typedef long long ll;

ll power (int n, int k) {
    if (k == 0) {
        return 1;
    }
    ll ans = power (n, k / 2);
    ans = (ans * ans) % MOD;
    if (k % 2) {
        ans = (ans * n) % MOD;
    }
    return ans;
}

int main () {
    int h, w;
    cin >> h >> w;
    int r[h], c[w];
    for (int i = 0; i < h; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < w; i++) {
        cin >> c[i];
    }
    int mat[h][w] = {0};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < r[i]; j++) {
            mat[i][j] = 1;
        }
        if (r[i] < w) {
            mat[i][r[i]] = 2;
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < c[j]; i++) {
            if (mat[i][j] == 2) {
                cout << 0 << endl;
                return 0;
            }
            mat[i][j] = 1;
        }
        if (c[j] < h) {
            if (mat[c[j]][j] == 1) {
                cout << 0 << endl;
                return 0;
            }
            mat[c[j]][j] = 2;
        }
    }
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = r[i]; j < w; j++) {
            count += (mat[i][j] == 0);
        }
    }
    cout << power (2, count) << endl;
    return 0;
}
