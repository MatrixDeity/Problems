/**
    Codeforces_864C
    http://codeforces.com/contest/864/problem/C
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

int main() {
    int a, b, f, k, ans(0);
    cin >> a >> b >> f >> k;
    if (b < f) {
        cout << -1;
        return 0;
    }
    int fuel = b;
    int dist = f;
    while (k > 0) {
        fuel -= dist;
        int rem = k > 1 ? 2 * (a - dist) : a - dist;
        if (fuel < rem) {
            fuel = b;
            ++ans;
        }
        if (b < rem) {
            cout << -1;
            return 0;
        }
        fuel -= a - dist;
        dist = a - dist;
        --k;
    }
    cout << ans;
    return 0;
}
