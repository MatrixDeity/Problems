/**
    Timus_1297
    http://acm.timus.ru/problem.aspx?space=1&num=1297
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string findMaxPoly(const string& str) {
    if (str.size() == 0)
        return 0;

    int l = 0, r = -1, n = (int) str.size();
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        int k = i <= r ? min(dp[r - i + l], r - i) : 1;
        while (i - k >= 0 && i + k < n && str[i - k] == str[i + k])
            ++k;
        dp[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    int mid1 = max_element(dp.begin(), dp.end()) - dp.begin();
    string ans1 = str.substr(mid1 - dp[mid1] + 1, 2 * dp[mid1] - 1);
    l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = i <= r ? min(dp[r - i + l + 1], r - i + 1) : 0;
        while (i + k < n && i - k - 1 >= 0 && str[i + k] == str[i - k - 1])
            ++k;
        dp[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }
    int mid2 = max_element(dp.begin(), dp.end()) - dp.begin();
    string ans2 = str.substr(mid2 - dp[mid2], 2 * dp[mid2]);
    return ans1.size() > ans2.size() ? ans1 : ans2;
}

int main() {
    string str;
    cin >> str;
    cout << findMaxPoly(str);
    return 0;
}
