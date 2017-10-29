/**
    Timus_2066
    http://acm.timus.ru/problem.aspx?space=1&num=2066
    MatrixDeity, 2017.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = min(a - b - c, a - b * c);
    cout << ans;
    return 0;
}
