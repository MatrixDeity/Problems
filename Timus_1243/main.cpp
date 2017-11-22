/**
    Timus_1243
    http://acm.timus.ru/problem.aspx?space=1&num=1243
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int ans(0);
    string str;
    cin >> str;
    for (char chr : str) {
        ans = ans * 10 + int(chr - '0');
        ans %= 7;
    }
    cout << ans;
    return 0;
}
