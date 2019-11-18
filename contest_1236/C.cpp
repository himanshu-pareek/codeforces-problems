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
    int n;
    cin >> n;
    int m = n * n;
    vector < vector < int > > G(n);
    int i = 1;
    while (i <= m) {
        for (int j = 0; j < n; j++) {
            G[j].push_back (i++);
        }
        if (i > m) break;
        for (int j = n - 1; j >= 0; j--) {
            G[j].push_back (i++);
        }
    }
    printMatrix (G);
    return 0;
}
