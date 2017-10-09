/**
    Codeforces_816B
    http://codeforces.com/contest/816/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 9;

int main() {
    vector<int> nums(N);
    vector<int> sums(N);
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        ++nums[l];
        --nums[r + 1];
    }
    for (int i = 1; i < N; ++i) {
        nums[i] += nums[i - 1];
        sums[i] += sums[i - 1] + int(nums[i] >= k);
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << sums[b] - sums[a - 1] << endl;
    }
    return 0;
}
