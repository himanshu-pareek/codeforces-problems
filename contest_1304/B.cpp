#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPalindrome (string & s) {
	int left = 0, right = (int) s.size() - 1;
	while (left < right) {
		if (s[left] != s[right]) return false;
		left++, right--;
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector < string > strs (n);
	for (string & s : strs) cin >> s;
	vector < bool > isPal (n, false);
	map < string, int > st;
	vector < int > indVec;
	stack < int > indSt;
	bool foundPal = false;
	int palIndex = -1;
	for (int i = 0; i < n; i++) {
		string s = strs[i];
		reverse (s.begin(), s.end());
		if (st.count (s)) {
			indVec.push_back (i);
			indSt.push (st[s]);
		} else if (!foundPal && isPalindrome (strs[i])) {
			//cout << i << " " << strs[i] << endl;
			foundPal = true;
			palIndex = i;
		}
		st[strs[i]] = i;
	}
	string res = "";
	for (int ind : indVec) {
		res += strs[ind];
	}
	if (foundPal) {
		//cout << palIndex << endl;
		res += strs[palIndex];
	}
	while (!indSt.empty()) {
		res += strs[indSt.top()];
		indSt.pop();
	}
	cout << res.size() << endl << res << endl;
	return 0;
}
