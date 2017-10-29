/**
    Codeforces_520B
    http://codeforces.com/contest/520/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

int main() {
    int n, m, ans(0);
    cin >> n >> m;
    while (n < m) {
        if (m % 2 == 1) {
            m = (m + 1) / 2;
            ans += 2;
        } else {
            m /= 2;
            ++ans;
        }
    }
    ans += n - m;
    cout << ans;
    return 0;
}
