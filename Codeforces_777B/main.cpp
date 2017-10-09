/**
    Codeforces_777B
    http://codeforces.com/contest/777/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>
#include <algorithm>

#define all(_) begin(_), end(_)

using namespace std;

int main() {
    int n, loses(0), wins(0);
    string a, b;
    cin >> n >> a >> b;
    sort(all(a), [] (char c1, char c2) { return c1 > c2; });
    sort(all(b));
    string tmp = b;
    for (int i = 0; i < n; ++i) {
        auto itr = lower_bound(all(tmp), a[i]);
        if (itr == tmp.end()) {
            tmp.erase(tmp.begin());
            ++loses;
        }
        else
            tmp.erase(itr);
    }
    tmp = b;
    for (int i = 0; i < n; ++i) {
        auto itr = upper_bound(all(tmp), a[i]);
        if (itr != tmp.end()) {
            tmp.erase(itr);
            ++wins;
        }
        else
            tmp.erase(tmp.begin());
    }
    cout << loses << endl << wins;
    return 0;
}
