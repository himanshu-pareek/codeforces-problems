#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void printVector (const vector < int > &vec) {
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int q, h, n, hei;
    cin >> q;
    while (q--) {
        cin >> h >> n;
        vector < int > x (n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        int ans = 0;
        x.push_back (0);
        for (int i = 0; i < n - 1; i++) {
            if (x[i + 1] == x[i + 2] + 1) {
                i++;
            } else {
                ans++;
            }
        }
        // reverse (x.begin(), x.end());
        // int ans = 0, a = 0, b = 0;
        // int j = 0;
        // while (j < n && x[j] < 2) {
        //     j++;
        // }
        // int k = 0;
        // for (int i = 3; i <= h; i++) {
        //     if (x[j] > i - 1) {
        //         ans = b;
        //     } else {
        //         int y = (i - 2 != x[k]);
        //         ans = min (1 + b, y + a);
        //     }
        //     if (x[j] == i - 1) {
        //         j++;
        //     }
        //     if (x[k] == i - 2) {
        //         k++;
        //     }
        //     a = b;
        //     b = ans;
        // }
        // int ans = max (0, h - n - 1);
        cout << ans << endl;
    }
    return 0;
}
