#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Contest : Codeforces Round #626 (Div. 2)
 * Contest URL : https://codeforces.com/contest/1323/
 * Problem : D - Present
 * Problem URL : https://codeforces.com/contest/1323/problem/D
 */

int main() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", &x);
	
	ll answer = 0LL;
	// Iterate over each bit in range [0, 27]
	for (int k = 0; k < 28; k++) {
		// kth bit of sum of two numbers (a and b) depends
		// only on bits from 0 to k
		// So, take each element mod (2^(k + 1))
		vector < int > b (n);
		for (int i = 0; i < n; i++) {
			b[i] = a[i] % (1 << (k + 1));
		}
		sort (b.begin(), b.end());
		
		// Sum kth bit of sum of two elements (a and b) is set
		// iff sum is in [2^k, 2^(k+1) - 1]
		// or sum is in [2^(k+1) + 2^k, 2^(k+2) - 1]
		// Since, a and b both are less than 2^(k+ 1)
		// => sum is less than 2^(k + 1)
		
		ll count = 0;
		for (int i = 0; i < n; i++) {
			int l = lower_bound (b.begin() + i + 1, b.end(), (1 << k) - b[i]) - b.begin();
			int r = lower_bound (b.begin() + i + 1, b.end(), (1 << (k + 1)) - b[i]) - b.begin();
			count += r - l;
			
			l = lower_bound (b.begin() + i + 1, b.end(), (1 << (k + 1)) + (1 << k) - b[i]) - b.begin();
			count += n - l;
		}
		
		if (count & 1) {
			// is count is even then xor of all the bits will be zero
			// So, we will set kth bit of answer if count is odd
			answer |= (1 << k);
		}
	}
	printf ("%lld\n", answer);
	return 0;
}
