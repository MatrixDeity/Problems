/**
    LeetCode_485
    https://leetcode.com/problems/max-consecutive-ones/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0;
        for (auto item : nums) {
            cur = item == 1 ? cur + 1 : 0;
            res = max(cur, res);
        }
        return res;
    }
};

int main() {
    return 0;
}
