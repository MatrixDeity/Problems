/**
    LeetCode_1639
    https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
    MatrixDeity, 2023.
*/

#include <functional>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        auto n = words.size(), m = words[0].size();
        vector<vector<int>> counter(m, vector<int>(26));
        vector<vector<int>> dp(m, vector<int>(target.size(), -1));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                char ch = words[i][j];
                ++counter[j][ch - 'a'];
            }
        }

        function<int(size_t, size_t)> impl = [&impl, &dp, &counter, &target, MOD] (size_t i, size_t j) {
            if (j == target.size()) {
                return 1;
            }

            if (i == counter.size()) {
                return 0;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            char targChar = target[j];
            long long notPickWays = impl(i + 1, j);

            int pickWays = 0;
            if (counter[i][targChar - 'a'] != 0) {
                int curr = counter[i][targChar - 'a'];
                int next = impl(i + 1, j + 1);
                pickWays = (curr * static_cast<long long>(next)) % MOD;
            }

            return dp[i][j] = static_cast<int>((pickWays + notPickWays) % MOD);
        };

        return impl(0, 0);
    }
};
