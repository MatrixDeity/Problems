/**
    Codeforces_864A
    http://codeforces.com/contest/864/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++mp[a];
    }
    if (mp.size() != 2) {
        cout << "NO";
        return 0;
    }
    auto f = mp.begin();
    auto s = f;
    ++s;
    if (f->second != s->second) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n" << f->first << ' ' << s->first;
    return 0;
}
