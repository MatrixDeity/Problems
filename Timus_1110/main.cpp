/**
    Timus_1110
    http://acm.timus.ru/problem.aspx?space=1&num=1110
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

using ll = long long;

inline ll powm(ll x, ll n, ll m) {
    ll ans = 1;
    for (ll i = 0; i < n; ++i) {
        ans *= x;
        ans %= m;
        if (ans == 0)
            break;
    }
    return ans;
}

// x^n % m == y. Note: x^n can exceed the 'long long' limit!

int main() {
    ll n, m, y;
    bool wasAns = false;
    cin >> n >> m >> y;
    for (ll x = 0; x < m; ++x) {
        bool flag = powm(x, n, m) == y;
        if (flag) {
            wasAns = true;
            cout << x << ' ';
        }
    }
    if (!wasAns)
        cout << -1;
    return 0;
}
