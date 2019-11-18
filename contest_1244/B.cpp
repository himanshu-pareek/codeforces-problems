#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int left = n, right = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                left = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                right = i;
                break;
            }
        }
        int ans = max (2 * (n - left), 2 * (right + 1));
        if (ans < n) {
            ans = n;
        }
        cout << ans << endl;
    }
    return 0;
}
