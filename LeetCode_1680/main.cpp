/**
  LeetCode_1680
  https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
  MatrixDeity, 2022.
*/

class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        unsigned long long ans = 0;
        int offset = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i-1)) == 0) {
                ++offset;
            }
            
            ans <<= offset;
            ans = (ans | i) % mod;
        }
        return static_cast<int>(ans);
    }
};
