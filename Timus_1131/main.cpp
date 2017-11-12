/**
    Timus_1131
    http://acm.timus.ru/problem.aspx?space=1&num=1131
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

int main() {
    int n, k, ans(0);
    cin >> n >> k;
    --n;
    int d = 1;
    while (n > 0) {
        n -= d;
        if (2 * d < k)
            d *= 2;
        else {
            d = k;
            ans += n / d + (n % d != 0) + 1;
            break;
        }
        ++ans;
    }
    cout << ans;
    return 0;
}
