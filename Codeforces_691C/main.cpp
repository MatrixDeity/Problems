/**
    Codeforces_691C
    http://codeforces.com/contest/691/problem/C
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int n = (int) str.size();
    int pnt(n), beg(0), end(0);
    for (int i = 0; i < n; ++i) {
        if (str[i] == '.') {
            pnt = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (str[i] != '0' && str[i] != '.') {
            beg = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (str[i] != '0' && str[i] != '.') {
            end = i;
            break;
        }
    }
    int exp = pnt - beg;
    if (exp >= 0)
        --exp;
    if (beg < end) {
        cout << str[beg] << '.';
        for (int i = beg + 1; i <= end; ++i)
            if (str[i] != '.')
                cout << str[i];
    } else {
        cout << str[beg];
    }
    if (exp != 0)
        cout << 'E' << exp;
    return 0;
}
