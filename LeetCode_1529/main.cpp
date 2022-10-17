/**
    LeetCode_1529
    https://leetcode.com/problems/minimum-suffix-flips/
    MatrixDeity, 2022.
*/

#include <string>

using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int res = (target.front() == '1');
        for (size_t i = 1; i < target.size(); ++i) {
            res += (target[i] != target[i - 1]);
        }
        return res;
    }
};
