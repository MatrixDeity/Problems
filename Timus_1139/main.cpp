/**
    Timus_1139
    http://acm.timus.ru/problem.aspx?space=1&num=1139
    MatrixDeity, 2017.
*/

#include <iostream>
#include <cmath>

using namespace std;

using ld = long double;

int main() {
    ld n, m;
    int ans(0);
    cin >> n >> m;
    n -= 1.0;
    m -= 1.0;
    ld k = m / n;
    ld x = 0.0, dx = 1.0, y0 = 0.0;
    while (x < n) {
        x += dx;
        ++ans;
        ld y1 = k * x;
        ans += (int) (trunc(y1) - trunc(y0));
        if (y1 == trunc(y1))
            --ans;
        y0 = y1;
    }
    cout << ans;
    return 0;
}
