/**
    LeetCode_162
    https://leetcode.com/problems/find-peak-element/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0, j = (int) nums.size() - 1;
        while (i < j) {
            int m = i + (j - i) / 2;
            if (nums[m] > nums[m + 1])
                j = m;
            else
                i = m + 1;
        }
        return i;
    }
};

int main() {
    return 0;
}
