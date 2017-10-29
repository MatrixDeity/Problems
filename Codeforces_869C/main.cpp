/**
    Codeforces_869C
    http://codeforces.com/contest/869/problem/C
    MatrixDeity, 2017.
*/

#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

const ll N = 5001;
const ll MOD = 998244353;

ll calc(ll a, ll b) {
    if (a == 0 || b == 0)
        return 1;

    static ll dp[N][N];
    if (dp[a][b] == 0)
        dp[a][b] = (a * calc(a - 1, b - 1) + calc(a, b - 1)) % MOD;
    return dp[a][b];
}

int main() {
    ll a, b, c, ans(0);
    cin >> a >> b >> c;
    ans = calc(a, b) % MOD *
          calc(b, c) % MOD *
          calc(c, a) % MOD;
    cout << ans;
    return 0;
}
