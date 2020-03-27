/**
 * Contest : Codeforces Round #629 (Div. 3)
 * Contest URL : http://codeforces.com/contest/1328
 * Problem : C - Ternary XOR
 * Problem URL : http://codeforces.com/contest/1328/problem/C
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
	int n; string x;
	cin >> n >> x;
	assert (n == x.length());
	string a, b; // b will be bigger if we have to
	bool same = true;
	for (char c : x) {
		if (c == '0') {
			a += '0'; b += '0';
		} else if (c == '1') {
			if (same) {
				a += '0'; b += '1';
				same = false;
			} else {
				a += '1'; b += '0';
			}
		} else {
			if (same) {
				a += '1'; b += '1';
			} else {
				a += '2'; b += '0';
			}
		}
	}
	cout << a << "\n" << b << "\n";
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

