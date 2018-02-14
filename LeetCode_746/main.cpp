/**
    LeetCode_746
    https://leetcode.com/problems/min-cost-climbing-stairs/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; ++i) {
            if (i < 2)
                dp[i] = cost[i];
            else if (i < n)
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
            else
                dp[i] = min(dp[i - 1], dp[i - 2]);
        }
        return dp.back();
    }
};

int main() {
    return 0;
}
