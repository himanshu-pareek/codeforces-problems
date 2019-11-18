#include <iostream>

using namespace std;

typedef long long ll;

int main () {

	int n;
	cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	ll s1, s2, s3, s4, s;
	s1 = 0;
	s2 = 0;
	s3 = 0;
	s4 = 0;
	for (int i = 2; i < n; i += 2) {
		s3 += a[i];
	}
	for (int i = 1; i < n; i += 2) {
		s4 += a[i];
	}
	
	int count = 0;
	if (s1 + s3 == s2 + s4) {
		count++;
	}
	
	for (int i = 0; i < n - 1; i++) {
		s = s2 + a[i];
		s2 = s1;
		s1 = s;
		s = s4 - a[i + 1];
		s4 = s3;
		s3 = s;
		if (s1 + s3 == s2 + s4) count++;
	}
	
	cout << count << endl;

	return 0;
}
