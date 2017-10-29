/**
    Codeforces_1A
    http://codeforces.com/problemset/problem/1/A
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

using ull = unsigned long long;

int main() {
    ull n, m, a, ans(0);
    cin >> n >> m >> a;
    ans = (n / a + (n % a != 0)) * (m / a + (m % a != 0));
    cout << ans;
    return 0;
}
