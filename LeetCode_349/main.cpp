/**
    LeetCode_349
    https://leetcode.com/problems/intersection-of-two-arrays/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> us(nums1.begin(), nums1.end());
        for (auto num : nums2) {
            if (us.find(num) != us.end()) {
                us.erase(num);
                res.push_back(num);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
