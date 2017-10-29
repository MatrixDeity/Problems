/**
    Timus_1079
    http://acm.timus.ru/problem.aspx?space=1&num=1079
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

const ll N = 1e5;

int main() {
    ll n;
    vector<ll> dp(N), ans(N);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i < N / 2; ++i) {
        dp[2 * i] = dp[i];
        dp[2 * i + 1] = dp[i] + dp[i + 1];
    }
    for (int i = 1; i < N; ++i) {
        ans[i] = max(dp[i], ans[i - 1]);
    }
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        cout << ans[n] << endl;
    }
    return 0;
}
