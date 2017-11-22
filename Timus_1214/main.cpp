/**
    Timus_1214
    http://acm.timus.ru/problem.aspx?space=1&num=1214
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0 && x % 2 != y % 2)
        cout << y << ' ' << x;
    else
        cout << x << ' ' << y;
    return 0;
}
