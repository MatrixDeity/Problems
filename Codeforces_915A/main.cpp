/**
    Codeforces_915A
    http://codeforces.com/contest/915/problem/A
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

int main() {
    int n, k, ans(0x7FFFFFFF);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (k % a == 0)
            ans = min(k / a, ans);
    }
    cout << ans;
    return 0;
}
