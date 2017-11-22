/**
    Codeforces_894B
    http://codeforces.com/contest/894/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll powm(ll a, ll p) {
    ll res = 1;
    a %= MOD;
    while (p > 0) {
        if (p % 2 != 0)
            res = (res * a) % MOD;
        p /= 2;
        a = (a * a) % MOD;
    }
    return res;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (n % 2 != m % 2 && k == -1) {
        cout << 0;
        return 0;
    }
    cout << powm(powm(2, n - 1), m - 1);
    return 0;
}
