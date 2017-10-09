/**
    Codeforces_598C
    http://codeforces.com/contest/598/problem/C
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

const long double PI = acos(-1.0);

int main() {
    int n;
    cin >> n;
    vector<pair<long double, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        vec[i].first = atan2(y, x);
        vec[i].second = i + 1;
    }
    sort(vec.begin(), vec.end());
    long double ansMin = 2.0 * PI - (vec.back().first - vec.front().first);
    int ans1(vec.back().second), ans2(vec.front().second);
    for (int i = 1; i < n; ++i) {
        long double sub = vec[i].first - vec[i - 1].first;
        if (sub < ansMin) {
            ansMin = sub;
            ans1 = vec[i - 1].second;
            ans2 = vec[i].second;
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}
