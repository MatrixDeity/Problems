/**
    Timus_1224
    http://acm.timus.ru/problem.aspx?space=1&num=1224
    MatrixDeity, 2017.
*/

#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    if (n == 1)
        cout << 0;
    else if (m == 1)
        cout << 1;
    else
        cout << min(2 * n - 2, 2 * m - 1);
    return 0;
}
