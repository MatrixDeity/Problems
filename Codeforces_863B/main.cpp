/**
    Codeforces_863B
    http://codeforces.com/contest/863/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, ans(INT_MAX);
    cin >> n;
    n *= 2;
    vector<int> vec(n);
    for (int& item : vec)
        cin >> item;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j) {
            vector<int> temp;
            int sum = 0;
            temp.reserve(n);
            for (int k = 0; k < n; ++k)
                if (k != i && k != j)
                    temp.push_back(vec[k]);
            for (int k = 0; k < (int) temp.size() - 1; k += 2)
                sum += temp[k + 1] - temp[k];
            ans = min(ans, sum);
        }
    cout << ans;
    return 0;
}
