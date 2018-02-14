/**
    LeetCode_643
    https://leetcode.com/problems/maximum-average-subarray-i/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), sum = 0, res = INT_MIN;
        while (j < n) {
            if (j - i + 1 == k) {
                sum += nums[j++];
                res = max(sum, res);
                sum -= nums[i++];

            } else {
                sum += nums[j++];
            }
        }
        return (double) res / k;
    }
};

int main() {
    return 0;
}
