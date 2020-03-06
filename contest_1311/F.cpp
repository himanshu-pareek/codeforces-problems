#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n), b (n);
	for (int & y : a) scanf ("%d", &y);
	for (int & u : b) scanf ("%d", &u);
	vector < pii > A;
	for (int i = 0; i < n; i++) {
		A.push_back (make_pair (a[i], b[i]));
	}
	sort (A.begin(), A.end(), [&] (const pii & p1, const pii & p2) {
		if (p1.first == p2.first) return p1.second < p2.second;
		return p1.first < p2.first;
	});
	multiset < int > v_so_far;
	vector < int > count (n);
	for (int i = 0; i < n; i++) {
		//cout << A[i].first << ", " << A[i].second << endl;
		if (!v_so_far.empty()) {
			multiset < int > :: iterator it = v_so_far.upper_bound (A[i].second);
			//if (it != v_so_far.end()) {
				//cout << i << ", " << *it << ", ";
				count[i] = distance (v_so_far.begin(), it);
				//cout << count[i] << endl;
			//}	
		}
		v_so_far.insert (A[i].second);
	}
	v_so_far.clear();
	for (int i = n - 1; i >= 0; i--) {
		//cout << A[i].first << ", " << A[i].second << endl;
		if (!v_so_far.empty()) {
			multiset < int > :: iterator it = v_so_far.lower_bound (A[i].second);
			count[i] -= distance (it, v_so_far.end());
		}
		v_so_far.insert (A[i].second);
	}
	ll answer = 0LL;
	for (int i = 0; i < n; i++) {
		// cout << "count[" << i << "] = " << count[i] << endl;
		answer += 1LL * A[i].first * count[i];
	}
	printf ("%lld\n", answer);
	return 0;
}
	
