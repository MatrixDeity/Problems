/**
    LeetCode_136
    https://leetcode.com/problems/single-number/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums)
            res ^= num;
        return res;
    }
};

int main() {
    return 0;
}
