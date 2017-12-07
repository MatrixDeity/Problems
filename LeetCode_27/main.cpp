/**
    LeetCode_27
    https://leetcode.com/problems/remove-element/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int) nums.size();
        if (n < 1)
            return 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != val)
                nums[res++] = nums[i];
        }
        return res;
    }
};

int main() {
    return 0;
}
