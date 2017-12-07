/**
    LeetCode_41
    https://leetcode.com/problems/first-missing-positive/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty())
            return 1;

        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] - 1 != i)
                return i + 1;
        }
        return n + 1;
    }
};

int main() {
    return 0;
}
