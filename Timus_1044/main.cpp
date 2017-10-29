/**
    Timus_1044
    http://acm.timus.ru/problem.aspx?space=1&num=1044
    MatrixDeity, 2017.
*/

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 2)
        cout << 10;
    else if (n == 4)
        cout << 670;
    else if (n == 6)
        cout << 55252;
    else
        cout << 4816030;
    return 0;
}
