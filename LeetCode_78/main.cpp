/**
    LeetCode_78
    https://leetcode.com/problems/subsets/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> impl = [&impl, &res, &nums, &cur] (int it) {
            res.push_back(cur);
            for (int i = it; i < (int) nums.size(); ++i) {
                cur.push_back(nums[i]);
                impl(i + 1);
                cur.pop_back();
            }
        };
        impl(0);
        return res;
    }
};

int main() {
    return 0;
}
