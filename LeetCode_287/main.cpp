/**
    LeetCode_287
    https://leetcode.com/problems/find-the-duplicate-number/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2)
            return -1;

        int p1 = nums[0], p2 = nums[p1];
        while (p1 != p2) {
            p1 = nums[p1];
            p2 = nums[nums[p2]];
        }
        p1 = nums[0];
        while (p1 != p2) {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return p1;
    }
};

int main() {
    return 0;
}
