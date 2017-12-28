/**
    LeetCode_219
    https://leetcode.com/problems/contains-duplicate-ii/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0)
            return false;
        int n = (int) nums.size();
        k = min(k, n - 1);
        unordered_set<int> us;
        for (int i = 0; i < n; ++i) {
            if (i > k)
                us.erase(nums[i - k - 1]);
            if (us.find(nums[i]) != us.end())
                return true;
            us.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    return 0;
}
