#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

template <typename T>
void printVector (vector < T > & vec) {
    for (T x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
void printMatrix (vector < vector < T > > & matrix) {
    for (vector < T > vec : matrix) {
        printVector (vec);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector < int > a (n), b (n), count  (n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int i = 0, j = 0, ans = 0;
    while (i < n && j < n) {
        if (a[i] == b[j]) {
            i++; j++;
            continue;
        }
        if (count[a[i]]) {
            i++;
        } else {
            ans++;
            count[b[j]] = 1;
            j++;
        }
    }
    // printVector (count);
    cout << ans << endl;
    return 0;
}
