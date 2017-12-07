/**
    LeetCode_35
    https://leetcode.com/problems/search-insert-position/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;

        int i = 0, j = (int) nums.size() - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (target > nums[m])
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

int main() {
    return 0;
}
