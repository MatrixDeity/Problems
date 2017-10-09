/**
    Codeforces_526B
    http://codeforces.com/contest/526/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, ans(0);
    cin >> n;
    int size = (1 << (n + 1));
    vector<int> vec(size);
    for (int i = 2; i < size; ++i) {
        cin >> vec[i];
    }
    for (int i = (1 << n) - 1; i > 0; --i) {
        int a = vec[2 * i];
        int b = vec[2 * i + 1];
        vec[i] += max(a, b);
        ans += abs(a - b);
    }
    cout << ans;
    return 0;
}
