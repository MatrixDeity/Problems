/**
    Codeforces_869B
    http://codeforces.com/contest/869/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ll a, b, ans(1);
    cin >> a >> b;
    for (ll i = a + 1; i <= b; ++i) {
        ans = (ans * i) % 10;
        if (ans == 0)
            break;
    }
    cout << ans;
    return 0;
}
