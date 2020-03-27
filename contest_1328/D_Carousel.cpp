/**
 * Contest : Codeforces Round #629 (Div. 3)
 * Contest URL : http://codeforces.com/contest/1328
 * Problem : D - Carousel
 * Problem URL : http://codeforces.com/contest/1328/problem/D
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// This section is for Policy Based Data Structure, more precisely Ordered Set.
// All Functions of set works here, in addition we have order_of_key() and find_by_order() function. find_by_order() returns iterator
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<functional>
using namespace __gnu_pbds;

// 1. Custom Set
template < class T, class COMP >
using custom_set = tree < T, null_type, COMP, rb_tree_tag, tree_order_statistics_node_update >;

// 2. Ordered Set
template < class T >
using ordered_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;

// 3. Ordered Multi Set
// For storing multiple occurance of same value we need to use pair. In pair first value is our key and second is useless count variable.
// order_of_key(make_pair(key, 0)) returns first occurance of a value, order_of_key(make_pair(key, INT_MAX)) returns last occurance.
template < class T >
using ordered_multiset = tree < pair < T, int >, null_type, less < pair < T, int > >, rb_tree_tag, tree_order_statistics_node_update >;

// 4. Ordered Map
template < class T, class U >
using ordered_map = tree < T, U, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
// Policy End

void solve() {
	int n;
	cin >> n;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector < int > color (n);
	bool allSame = true;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != a[i + 1]) {
			allSame = false;
			break;
		}
	}
	if (allSame) {
		cout << 1 << endl;
		for (int i = 0; i < n; i++) {
			cout << 1 << " ";
		}
		cout << endl;
		return;
	}
	int c = 1;
	if (n % 2 == 0) {
		for (int i = 0; i < n; i++) {
			color[i] = c;
			c = 3 - c;
		}
	} else {
		bool found = false;
		int index = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == a[(i + 1) % n]) {
				found = true;
				index = i;
				break;
			}
		}
		if (found) {
			color[index] = color[(index + 1) % n] = 1;
			c = 2;
			for (int i = (index + 2) % n; i != index; i = (i + 1) % n) {
				color[i] = c;
				c = 3 - c;
			}
		} else {
			c = 1;
			for (int i = 0; i < n; i++) {
				color[i] = c;
				c = 3 - c;
			}
			if (a[0] != a[n - 1] && color[0] == color[n - 1]) {
				color[n - 1] = 3;
			}
		}
	}
	int k = 0;
	for (int c : color) {
		k = max (k, c);
	}
	cout << k << "\n";
	for (int c : color) {
		cout << c << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}

