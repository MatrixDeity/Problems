/**
    LeetCode_347
    https://leetcode.com/problems/top-k-frequent-elements/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> um;
        for (auto item : nums) {
            ++um[item];
        }
        vector<vector<int>> vec(nums.size() + 1);
        for (auto p : um) {
            vec[p.second].push_back(p.first);
        }
        for (int i = vec.size() - 1; i >= 0; --i) {
            for (auto item : vec[i]) {
                if (k-- == 0)
                    return ans;
                ans.push_back(item);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
