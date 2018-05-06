/**
    LeetCode_139
    https://leetcode.com/problems/word-break/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] && us.count(s.substr(j, i - j)) != 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

int main() {
    return 0;
}
