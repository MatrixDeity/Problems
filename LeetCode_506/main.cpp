/**
    LeetCode_506
    https://leetcode.com/problems/relative-ranks/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]] = i;
        }
        int pos = 1;
        for (auto it = mp.rbegin(); it != mp.rend(); ++it, ++pos) {
            if (pos == 1)
                res[it->second] = "Gold Medal";
            else if (pos == 2)
                res[it->second] = "Silver Medal";
            else if (pos == 3)
                res[it->second] = "Bronze Medal";
            else
                res[it->second] = to_string(pos);
        }
        return res;
    }
};

int main() {
    return 0;
}
