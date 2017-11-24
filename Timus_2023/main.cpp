/**
    Timus_2023
    http://acm.timus.ru/problem.aspx?space=1&num=2023
    MatrixDeity, 2017.
*/

#include <iostream>
#include <cmath>

using namespace std;

int getCase(char c) {
    switch (c) {
        case 'A':
        case 'P':
        case 'O':
        case 'R':
            return 1;
        case 'B':
        case 'M':
        case 'S':
            return 2;
        default:
            return 3;
    }
}

int main() {
    int n, ans(0), pos(1);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        int tar = getCase(str[0]);
        ans += abs(pos - tar);
        pos = tar;
    }
    cout << ans;
    return 0;
}
