/**
    Codeforces_548A
    http://codeforces.com/contest/548/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalid(const string& str, int n) {
    int h = n / 2;
    for (int i = 0; i < h; ++i) {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
}

int main() {
    string str;
    int k;
    cin >> str >> k;
    int len = int(str.size());
    int n = len / k;
    if (len % k != 0) {
        cout << "NO";
        return 0;
    }
    bool ans = true;
    if (n > 1) {
        for (int i = 0; i < len; i += n) {
            ans &= isPalid(str.substr(i, n), n);
        }
    }
    cout << (ans ? "YES" : "NO");
    return 0;
}
