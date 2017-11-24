/**
    Timus_2100
    http://acm.timus.ru/problem.aspx?space=1&num=2100
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, ans(0);
    cin >> n;
    ans = n + 2;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if (str[str.size() - 4] == '+')
            ++ans;
    }
    if (ans == 13)
        ++ans;
    cout << ans * 100;
    return 0;
}
