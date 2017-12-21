/**
    LeetCode_697
    https://leetcode.com/problems/degree-of-an-array/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;

        unordered_map<int, vector<int>> um;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            um[nums[i]].push_back(i);
        }
        int len = 0;
        for (auto& p : um) {
            len = max((int) p.second.size(), len);
        }
        int ans = 0x7FFFFFFF;
        for (auto& p : um) {
            if (p.second.size() == len)
                ans = min((int) p.second.back() - p.second.front() + 1, ans);
        }
        return ans;
    }
};

int main() {
    return 0;
}
