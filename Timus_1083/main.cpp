/**
    Timus_1083
    http://acm.timus.ru/problem.aspx?space=1&num=1083
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

using ll = long long;

int main() {
    ll n, ans(1);
    string fact;
    cin >> n >> fact;
    ll k = fact.size();
    while (n > 1) {
        ans *= n;
        n -= k;
    }
    cout << ans;
    return 0;
}
