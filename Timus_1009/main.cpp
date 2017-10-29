/**
    Timus_1009
    http://acm.timus.ru/problem.aspx?space=1&num=1009
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> dp(n);
    dp[0] = k - 1;
    dp[1] = k * (k - 1);
    for (ll i = 2; i < n; ++i) {
        dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
    }
    cout << dp.back();
    return 0;
}
