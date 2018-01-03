/**
    LeetCode_260
    https://leetcode.com/problems/single-number-iii/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axb = 0;
        vector<int> res(2);
        for (auto num : nums)
            axb ^= num;
        int lb = axb ^ (axb & (axb - 1));
        for (auto num : nums) {
            if ((num & lb) != 0)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};

int main() {
    return 0;
}
