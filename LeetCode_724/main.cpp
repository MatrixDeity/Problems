/**
    LeetCode_724
    https://leetcode.com/problems/find-pivot-index/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (size_t i = 0; i < (int) nums.size(); ++i) {
            rightSum -= nums[i];
            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

int main() {
    return 0;
}
