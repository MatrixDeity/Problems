/**
    Codeforces_846A
    http://codeforces.com/contest/846/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, ans(0);
    cin >> n;
    vector<int> zeros(n + 2);
    vector<int> ones(n + 2);
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    for (int i = 1; i <= n; ++i) {
        zeros[i] = zeros[i - 1] + int(vec[i] == 0);
    }
    for (int i = n; i >= 0; --i) {
        ones[i] = ones[i + 1] + int(vec[i] == 1);
    }
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, zeros[i] + ones[i]);
    }
    cout << ans;
    return 0;
}
