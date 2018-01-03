/**
    LeetCode_560
    https://leetcode.com/problems/subarray-sum-equals-k/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using ll = long long;

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, ll> um;
        ll sum = 0;
        int res = 0;
        for (int num : nums) {
            ++um[sum];
            sum += num;
            res += um[sum - k];
        }
        return res;
    }
};

int main() {
    return 0;
}
