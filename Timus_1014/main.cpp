/**
    Timus_1014
    http://acm.timus.ru/problem.aspx?space=1&num=1014
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ll n, ans(0), mul(1);
    cin >> n;
    if (n < 10) {
        cout << (n > 0 ? n : 10);
        return 0;
    }
    for (ll i = 9; i > 1; --i) {
        while (n % i == 0) {
            n /= i;
            ans += i * mul;
            mul *= 10;
        }
    }
    cout << (n == 1 ? ans : -1);
    return 0;
}
