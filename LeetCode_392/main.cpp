/**
    LeetCode_392
    https://leetcode.com/problems/is-subsequence/
    MatrixDeity, 2022.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t j = 0;

        for (char c : t) {
            if (c == s[j]) {
                ++j;
            }
        }

        return j == s.size();
    }
};
