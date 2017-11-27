/**
    Codeforces_895B
    http://codeforces.com/contest/895/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define all(X) begin(X), end(X)

using namespace std;

using ll = long long;

int main() {
    ll n, x, k, ans(0);
    cin >> n >> x >> k;
    vector<ll> vec(n);
    for (auto& item : vec)
        cin >> item;
    sort(vec.begin(), vec.end());
    for (auto item : vec) {
        ll rem = (item - 1) / x;
        ll low = max((k + rem) * x, item);
        ll upp = max((k + rem + 1) * x, item);
        ans += lower_bound(all(vec), upp) - lower_bound(all(vec), low);
    }
    cout << ans;
    return 0;
}
