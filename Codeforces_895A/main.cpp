#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, ans(500);
    cin >> n;
    vector<int> vec(n);
    for (int& item : vec)
        cin >> item;
    for (int i = 0; i < n; ++i) {
        int rem = 360;
        int half = 0;
        int k = i;
        for (int j = 0; j < n; ++j, ++k) {
            rem -= vec[k % n];
            half += vec[k % n];
            ans = min(ans, abs(rem - half));
        }
    }
    cout << ans;
    return 0;
}
