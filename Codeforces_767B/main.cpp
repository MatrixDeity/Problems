/**
    Codeforces_767B
    http://codeforces.com/contest/767/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

using ull = unsigned long long;

const ull MAX = 0xFFFFFFFFFFFFFFFF;

int main () {
    ull s, f, t, n, ans, wt(MAX);
    cin >> s >> f >> t >> n;
    ull now = ans = s;
    for (ull i = 0; i < n && now + t <= f; ++i) {
        ull a;
        cin >> a;
        if (a <= now) {
            ull d = now - a;
            if (d < wt) {
                ans = a - 1;
                wt = d;
            }
            now += t;
        } else {
            break;
        }
    }
    if (now + t <= f)
        ans = now;
    cout << ans;
    return 0;
}
