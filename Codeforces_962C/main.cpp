/**
    Codeforces_962C
    http://codeforces.com/contest/962/problem/C
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <functional>

using namespace std;

int main() {
    string str, cur;
    cin >> str;
    int n = str.size();
    int ans = INT_MAX;
    function<void(int)> impl = [&] (int ind) {
        if (cur.empty() && str[ind] == '0') {
            return;
        }
        cur.push_back(str[ind]);
        double num = stod(cur);
        if (fmod(sqrt(num), 1.0) == 0.0) {
            ans = min(n - (int)cur.size(), ans);
        }
        for (int i = ind + 1; i < n; ++i) {
            impl(i);
        }
        cur.pop_back();
    };
    for (int i = 0; i < n; ++i) {
        impl(i);
    }
    cout << (ans != INT_MAX ? ans : -1);
    return 0;
}
