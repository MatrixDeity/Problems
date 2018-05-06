/**
    Codeforces_962B
    http://codeforces.com/contest/962/problem/B
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, a, b, ans = 0;
    string str;
    cin >> n >> a >> b >> str;
    if (a < b) {
        swap(a, b);
    }
    for (auto c : str) {
        if (c == '.') {
            if (a > 0) {
                --a;
                ++ans;
            }
            swap(a, b);
        } else if (a < b) {
            swap(a, b);
        }
    }
    cout << ans;
    return 0;
}
