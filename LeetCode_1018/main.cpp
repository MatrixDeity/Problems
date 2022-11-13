/**
    LeetCode_1018
    https://leetcode.com/problems/binary-prefix-divisible-by-5/
    MatrixDeity, 2022.
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0;
        vector<bool> res;
        res.reserve(A.size());
        for (auto currNum : A) {
            num = (2 * num + currNum) % 5;
            res.push_back(num == 0);
        }
        return res;
    }
};
