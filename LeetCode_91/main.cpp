/**
    LeetCode_91
    https://leetcode.com/problems/decode-ways/
    MatrixDeity, 2022.
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size());
        dp[0] = (s[0] != '0');

        for(size_t i = 1; i < dp.size(); ++i) {
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] += (i > 1 ? dp[i - 2] : 1);
            }
        }

        return dp.back();
    }
};
