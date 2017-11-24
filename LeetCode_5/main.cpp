/**
    LeetCode_5
    https://leetcode.com/problems/longest-palindromic-substring/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int) s.size();
        vector<int> dp(n);
        int r = -1, l = 0;
        for (int i = 0; i < n; ++i) {
            int k = i <= r ? min(dp[l + r - i], r - i) : 1;
            while (s[i - k] == s[i + k] && i - k >= 0 && i + k < n)
                ++k;
            dp[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }
        int mid1 = max_element(dp.begin(), dp.end()) - dp.begin();
        string ans1 = s.substr(mid1 - dp[mid1] + 1, 2 * dp[mid1] - 1);
        r = -1, l = 0;
        for (int i = 0; i < n; ++i) {
            int k = i <= r ? min(dp[l + r - i + 1], r - i + 1) : 0;
            while (s[i - k - 1] == s[i + k] && i + k < n && i - k - 1 >= 0)
                ++k;
            dp[i] = k;
            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }
        int mid2 = max_element(dp.begin(), dp.end()) - dp.begin();
        string ans2 = s.substr(mid2 - dp[mid2], 2 * dp[mid2]);
        return ans1.size() > ans2.size() ? ans1 : ans2;
    }
};

int main() {
    return 0;
}
