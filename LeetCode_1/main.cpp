/**
    LeetCode_1
    https://leetcode.com/problems/two-sum/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sums;
        vector<int> ans;
        for (int i = 0; i < (int) nums.size(); ++i) {
            sums.emplace(nums[i], i);
        }
        for (int i = 0; i < (int) nums.size(); ++i) {
            auto it = sums.find(target - nums[i]);
            if (it != sums.end() && it->second != i) {
                ans.push_back(min(it->second, i));
                ans.push_back(max(it->second, i));
                break;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
