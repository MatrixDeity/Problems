/**
    Codeforces_915B
    http://codeforces.com/contest/915/problem/B
    MatrixDeity, 2018.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    if (l == 1 && r == n)
        cout << 0;
    else if (l == 1)
        cout << abs(r - pos) + 1;
    else if (r == n)
        cout << abs(l - pos) + 1;
    else
        cout << min(abs(l - pos), abs(r - pos)) + (r - l) + 2;
    return 0;
}
