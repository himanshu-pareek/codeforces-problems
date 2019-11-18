#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    scanf ("%d", &n);
    vector < int > a (n);
    for (int & x : a) scanf ("%d", & x);
    set < int > s;
    vector < int > nums;
    int count = 0;
    long sum = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (a[i] > 0) {
            if (s.find(a[i]) != s.end() || s.find(-a[i]) != s.end()) {
                cout << "-1" << endl;
                return 0;
            } else {
                s.insert (a[i]);
            }
            sum += a[i];
        } else {
            if (s.find(-a[i]) == s.end() || s.find(a[i]) != s.end()) {
                cout << -1 << endl;
                return 0;
            }
            sum += a[i];
            if (sum == 0) {
                s.clear();
                nums.push_back (count);
                count = 0;
            }
            
        }
    }
    if (sum != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << nums.size() << endl;
    for (int num : nums) {
        printf ("%d ", num);
    }
    printf ("\n");
    return 0;
}
