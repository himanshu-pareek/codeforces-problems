#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
	    long long n;
	    int a, b;
	    cin >> n >> a >> b;
	    long long ans = 0;
	    if (n%2) {
	        ans = a;
	        n--;
	    }
	    if (b < 2 * a) {
	        ans += b * (n / 2);
	    } else {
	        ans += a * n;
	    }
	    cout << ans << endl;
	}
	return 0;
}
