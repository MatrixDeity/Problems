/**
    LeetCode_34
    https://leetcode.com/problems/search-for-a-range/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty())
            return res;

        int n = (int) nums.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (target > nums[m])
                i = m + 1;
            else
                j = m - 1;
        }
        if (i >= n || nums[i] != target)
            return res;
        else
            res[0] = i;
        j = n - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (target < nums[m])
                j = m - 1;
            else
                i = m + 1;
        }
        res[1] = j;
        return res;
    }
};

int main() {
    return 0;
}
