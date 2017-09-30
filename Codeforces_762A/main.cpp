/**
    Codeforces_762A
    http://codeforces.com/contest/762/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ll n, k;
    vector<ll> divs;
    divs.reserve(9999);
    cin >> n >> k;
    for (ll div = 1LL; div * div <= n; ++div) {
        if (n % div == 0) {
            if (div != n / div)
                divs.push_back(n / div);
            divs.push_back(div);
        }
    }
    sort(divs.begin(), divs.end());
    if (divs.size() >= k) {
        cout << divs[k - 1];
    }
    else
        cout << -1;
    return 0;
}
