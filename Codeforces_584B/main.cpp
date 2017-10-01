/**
    Codeforces_584B
    http://codeforces.com/contest/584/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    ll n, ans(1), sub(1), notVal(0);
    cin >> n;
    for (int i = 0; i < 3 * n; ++i)
        ans = (ans * 3) % MOD;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            for (int k = 1; k <= 3; ++k) {
                int sum = i + j + k;
                if (sum == 6)
                    ++notVal;
            }
    for (int i = 0; i < n; ++i)
        sub = (sub * notVal) % MOD;
    ans = (ans - sub + MOD) % MOD;
    cout << ans;
    return 0;
}
