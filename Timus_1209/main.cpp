/**
    Timus_1209
    http://acm.timus.ru/problem.aspx?space=1&num=1209
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

using ll = long long;

const ll N = 1LL << 32LL;

int main() {
    unordered_set<ll> us;
    ll d = 0, k = 1;
    while (k + d <= N) {
        k += d;
        us.insert(k);
        ++d;
    }
    ll n;
    cin >> n;
    vector<bool> ans;
    ans.reserve(n);
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        ans.push_back(us.find(a) != us.end());
    }
    for (ll item : ans) {
        cout << item << ' ';
    }
    return 0;
}
