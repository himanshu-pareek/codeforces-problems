/**
 * Contest : Codeforces Round #629 (Div. 3)
 * Contest URL : http://codeforces.com/contest/1328
 * Problem : F - Make k Equal
 * Problem URL : http://codeforces.com/contest/1328/problem/F
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

const ll inf = 1e18;

void solve() {
	int n, k;
	cin >> n >> k;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort (a.begin(), a.end());
	
	vector < ll > P (n + 1);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i - 1] + a[i - 1];
	}
	
	ll answer = inf;
	
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && a[i] == a[j]) j++;
		
		int same_count = j - i;
		ll cost_left = (ll)i * (a[i] - 1) - P[i];
		ll cost_right = P[n] - P[j] - (ll) (n - j) * (a[i] + 1);
		
		if (same_count >= k) {
			answer = 0LL;
		}
		
		if (same_count + i >= k) {
			answer = min (answer, cost_left + k - same_count);
		}
		
		if (same_count + n - j >= k) {
			answer = min (answer, cost_right + k - same_count);
		}
		
		answer = min (answer, cost_left + cost_right + k - same_count);
		
		i = j;
	}
	
	cout << max (answer, 0LL) << endl;
}

int main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}

