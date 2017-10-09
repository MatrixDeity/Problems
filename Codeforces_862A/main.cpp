/**
    Cpdeforces_862A
    http://codeforces.com/contest/862/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 111;

int main() {
    int n, x, ans(0);
    cin >> n >> x;
    vector<bool> inds(N);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        inds[a] = true;
    }
    for (int i = 0; i < x; ++i) {
        if (!inds[i])
            ++ans;
    }
    ans += int(inds[x]);
    cout << ans;
    return 0;
}
