/**
    Codeforces_526A
    http://codeforces.com/contest/526/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, bool> um;
    int n;
    cin >> n;
    cin.ignore(10, '\n');
    for (int i = 0; i < n; ++i) {
        char c = cin.get();
        if (c == '*')
            um[i] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (um[i]) {
            for (int j = 1; j <= n / 4; ++j) {
                if (um[i + j] && um[i + 2 * j] && um[i + 3 * j] && um[i + 4 * j]) {
                    cout << "yes";
                    return 0;
                }
            }
        }
    }
    cout << "no";
    return 0;
}
