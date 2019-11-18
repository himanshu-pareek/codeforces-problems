#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

const int D = 4;
int n;
vector < vector < int > > a (50005, vector < int > (D - 1));

void solve (vector < int > & ind, int d) {
    if (d == D - 1) {
    	return;
    }
    map < int, vector < int > > m;
    for (int i : ind) {
    	m[a[i][d]].push_back (i);
    }
    bool flag = false;
    int last;
    for (auto it = m.begin(); it != m.end(); it++) {
    	solve (it -> second, d+ 1);
    	if (!(it -> second).empty()) {
    		if (!flag) {
    			last = (it -> second)[0];
    		} else {
    			cout << (last + 1) << " " << ((it -> second)[0] + 1) << endl;
    		}
    		flag = !flag;
    	}
    }
    ind.clear();
    if (flag) {
    	ind.push_back (last);
    }
}

int main() {
    // int n;
    cin >> n;
    // vector < vector < int > > a (n, 4);
    vector < int > indexes;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        // a[i][3] = i + 1;
        indexes.push_back (i);
    }
    solve (indexes, 0);
    return 0;
}
