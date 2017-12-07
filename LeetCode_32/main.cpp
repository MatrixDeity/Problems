/**
    LeetCode_32
    https://leetcode.com/problems/longest-valid-parentheses/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, n = (int) s.size();
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                ++l;
            else
                ++r;
            if (l == r)
                res = max(res, l + r);
            else if (r > l)
                l = r = 0;
        }
        l = r = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(')
                ++l;
            else
                ++r;
            if (l == r)
                res = max(res, l + r);
            else if (l > r)
                l = r = 0;
        }
        return res;
    }
};

int main() {
    return 0;
}
