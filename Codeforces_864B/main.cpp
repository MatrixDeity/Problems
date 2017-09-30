/**
    Codeforces_864B
    http://codeforces.com/contest/864/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<char> us;
    int ans = 0;
    for (char c : s) {
        if (!isupper(c))
            us.insert(c);
        else
            us.clear();
        ans = max(ans, (int) us.size());
    }
    cout << ans;
    return 0;
}
