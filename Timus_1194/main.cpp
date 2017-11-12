/**
    Timus_1194
    http://acm.timus.ru/problem.aspx?space=1&num=1194
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    cout << n * (n - 1) / 2 - k;
    return 0;
}
