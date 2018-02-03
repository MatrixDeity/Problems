/**
    LeetCode_561
    https://leetcode.com/problems/array-partition-i/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0, n = (int) nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2) {
            res += nums[i];
        }
        return res;
    }
};

int main() {
    return 0;
}
