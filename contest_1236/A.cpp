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
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int ans = 0;
        for (int x = 0; x <= a; x++) {
            int y = min (c / 2, b - 2 * x);
            if (y < 0) {
                break;
            }
            ans = max (ans, 3 * (x + y));
        }
        cout << ans << endl;
    }
    return 0;
}
