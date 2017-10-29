/**
    Timus_1073
    http://acm.timus.ru/problem.aspx?space=1&num=1073
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int m = dp[i - 1] + 1;
        for (int j = 1; j * j <= i; ++j) {
            m = min(m, dp[i - j * j] + 1);
        }
        dp[i] = m;
    }
    cout << dp.back();
    return 0;
}
