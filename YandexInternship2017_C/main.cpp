/**
    YandexInternship2017_C
    https://contest.yandex.ru/contest/4085/problems/C/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double n, m, k;
    cin >> n >> m >> k;
    long double s = n * m;
    long double p = (1 - powl(1 - (1 / s), k)) * s;
    cout.setf(cout.fixed);
    cout.precision(12);
    cout << p;
    return 0;
}
