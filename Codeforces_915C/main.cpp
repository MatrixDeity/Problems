/**
    Codeforces_915C
    http://codeforces.com/contest/915/problem/C
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    string s, b;
    cin >> s >> b;
    if (s.size() < b.size()) {
        sort(s.begin(), s.end(), greater<char>());
        cout << s;
        return 0;
    }
    int n = (int) s.size();
    sort(s.begin(), s.end(), less<char>());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] < s[j])
                swap(s[i], s[j]);
            if (s > b)
                swap(s[i], s[j]);
        }
    }
    cout << s;
    return 0;
}
