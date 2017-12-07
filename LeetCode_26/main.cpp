/**
    LeetCode_26
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int) nums.size();
        if (n < 2)
            return n;
        int res = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] != nums[i])
                nums[res++] = nums[i];
        }
        return res;
    }
};

int main() {
    return 0;
}
