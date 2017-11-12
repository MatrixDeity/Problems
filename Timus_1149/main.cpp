/**
    Timus_1149
    http://acm.timus.ru/problem.aspx?space=1&num=1149
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

string getA(int n, int i = 1) {
    if (i == n)
        return "sin(" + to_string(i) + ")";
    return "sin(" + to_string(i) + (i % 2 == 0 ? "+" : "-") + getA(n, i + 1) + ")";
}

string getS(int n, int i = 1) {
    if (i == n)
        return getA(n - i + 1) + "+" + to_string(i);
    return "(" + getS(n, i + 1) + ")" + getA(n - i + 1) + "+" + to_string(i);
}

int main() {
    int n;
    cin >> n;
    cout << getS(n);
    return 0;
}
