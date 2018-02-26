/**
    LeetCode_413
    https://leetcode.com/problems/arithmetic-slices/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            dp[i] = A[i] - A[i - 1] == A[i - 1] - A[i - 2] ? dp[i - 1] + 1 : 0;
            res += dp[i];
        }
        return res;
    }
};

int main() {
    return 0;
}
