/**
    LeetCode_268
    https://leetcode.com/problems/missing-number/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    using ll = long long;

    int missingNumber(vector<int>& nums) {
        ll n = (ll) nums.size();
        ll sum = n * (n + 1) / 2;
        ll realSum = accumulate(nums.begin(), nums.end(), 0LL);
        return (int) sum - realSum;
    }
};

int main() {
    return 0;
}
