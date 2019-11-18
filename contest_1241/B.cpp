#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        int count_s[26] = {0}, count_t[26] = {0};
        for (char c : s) {
            count_s[c - 'a'] = 1;
        }
        for (char c : t) {
            count_t[c - 'a'] = 1;
        }

        string ans = "NO";
        for (int i = 0; i < 26; i++) {
            if (count_s[i] && count_t[i]) {
                ans = "YES";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}