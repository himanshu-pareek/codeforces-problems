#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

template <typename T>
void printVector (vector < T > & vec) {
    for (T x : vec) {
        cout << x << "\t";
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
    vector < int > a (3 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i]; a[2 * n + i] = a[i];
    }
    // printVector (a);
    vector < int > m (3 * n);
    vector < int > min_idx, max_idx;
    for (int i = 3 * n - 1; i >= 0; i--) {
		while (!min_idx.empty() && a[min_idx.back()] > a[i]) {
			min_idx.pop_back ();
		}
		while (!max_idx.empty() && a[max_idx.back()] < a[i]) {
			max_idx.pop_back ();
		}
		int j = max_idx.empty() ? 3 * n : max_idx.back ();
		int k;
		int low = 0, high = (int) min_idx.size() - 1;
		while (low <= high){
			int mid = low + ((high - low) / 2);
			if (2 * a[min_idx[mid]] < a[i]){
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		k = (high == -1) ? 3 * n : min_idx[high];
		// cout << i << " " << j << " " << k << endl;
		if (j <= k){
			if (j == 3 * n) {
				m[i] = 3 * n - i;
			} else {
				m[i] = j - i + m[j];
			}
		} else {
			m[i] = k - i;
		}
		min_idx.push_back (i);
		max_idx.push_back (i);
	}
	// printVector (m);
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		if (m[i] + i == 3 * n) cout << -1;
		else cout << m[i];
	}
	cout << endl;
    return 0;
}
