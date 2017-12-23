/**
    LeetCode_174
    https://leetcode.com/problems/dungeon-game/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int MAX = 0x7FFFFFFF;

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty())
            return 0;

        int n = (int) dungeon.size();
        int m = (int) dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, MAX));
        dp[n - 1][m] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int hp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = max(hp, 1);
            }
        }
        return dp[0][0];
    }
};

int main() {
    return 0;
}
