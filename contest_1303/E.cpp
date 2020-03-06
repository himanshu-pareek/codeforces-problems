#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define sz(a) int((a).size())
const int inf = 1e8 + 5;

int main() {
    int ct; string s, t;
    scanf ("%d", &ct);
    while (ct--) {
        // string s, t;
        cin >> s >> t;
        // cout << ct << " " << s << " " << t << endl;
        int ns = sz(s);
        int nt = sz(t);

        vector < vector < int > > nextPosition (ns + 1, vector < int > (26, inf));
        for (int i = ns - 1; i >= 0; i--) {
            nextPosition[i] = nextPosition[i + 1];
            nextPosition[i][s[i] - 'a'] = i;
        }

        bool possible = false;
        for (int k = 0; k < nt; k++) {
            string left = t.substr (0, k);
            string right = t.substr (k);
            vector < vector < int > > dp (sz(left) + 1, vector < int > (sz(right) + 1, inf));
            dp[0][0] = 0;
            for (int i = 0; i <= sz(left); i++) {
                for (int j = 0; j <= sz(right); j++) {
                    if (dp[i][j] > sz(s)) continue;
                    int len = dp[i][j];
                    if (i < sz(left) && nextPosition[len][left[i] - 'a'] < inf) {
                        dp[i + 1][j] = min (dp[i + 1][j], 1 + nextPosition[len][left[i] - 'a']);
                    }
                    if (j < sz (right) && nextPosition[len][right[j] - 'a'] < inf) {
                        dp[i][j + 1] = min (dp[i][j + 1], 1 + nextPosition[len][right[j] - 'a']);
                    }
                }
            }
            if (dp[sz(left)][sz(right)] < inf) {
                possible = true;
                break;
            }
        }
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}


