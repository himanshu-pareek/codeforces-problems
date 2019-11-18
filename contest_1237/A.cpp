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
    vector < int > a (n);
    int oddCount = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        oddCount += (a[i] % 2 != 0);
    }
    oddCount /= 2;
    // cout << oddCount << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            cout << (a[i] / 2) << endl;
        } else {
            if (oddCount) {
                cout << ((a[i] - 1) / 2) << endl;
                oddCount--;
            } else {
                cout << ((a[i] + 1) / 2) << endl;
            }
        }
    }
    return 0;
}
