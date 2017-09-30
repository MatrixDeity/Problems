/**
    Codeforces_762B
    http://codeforces.com/contest/762/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

using ll = long long;

ll sumFirstN(ll n, vector<ll>& vec, ll& ans) {
    ll result = 0;
    while (!vec.empty() && n > 0) {
        result += vec.back();
        vec.pop_back();
        --n;
        ++ans;
    }
    return result;
}

int main() {
    ll a, b, c, m;
    ll ans(0), sum(0);
    cin >> a >> b >> c >> m;
    vector<ll> usb, ps2, both;
    usb.reserve(m);
    ps2.reserve(m);
    both.reserve(m);
    for (int i = 0; i < m; ++i) {
        ll price;
        string type;
        cin >> price >> type;
        if (type == "USB")
            usb.push_back(price);
        else
            ps2.push_back(price);
    }
    sort(usb.begin(), usb.end(), greater<ll>());
    sort(ps2.begin(), ps2.end(), greater<ll>());
    sum += sumFirstN(a, usb, ans);
    sum += sumFirstN(b, ps2, ans);
    merge(usb.begin(), usb.end(), ps2.begin(), ps2.end(), back_inserter(both), greater<ll>());
    sum += sumFirstN(c, both, ans);
    cout << ans << ' ' << sum;
    return 0;
}
