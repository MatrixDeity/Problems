/**
    Codeforces_894A
    http://codeforces.com/contest/894/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int ans = 0;
    string str;
    cin >> str;
    int n = (int) str.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                if (str[i] == 'Q' && str[j] == 'A' && str[k] == 'Q')
                    ++ans;
    cout << ans;
    return 0;
}
