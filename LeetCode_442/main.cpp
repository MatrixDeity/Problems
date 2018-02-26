/**
    LeetCode_442
    https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                res.push_back(nums[i]);
        }
        return res;
    }
};

int main() {
    return 0;
}
