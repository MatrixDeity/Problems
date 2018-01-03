/**
    LeetCode_477
    https://leetcode.com/problems/total-hamming-distance/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int ts = sizeof(int) * 8;
        int n = (int) nums.size();
        for (int i = 0; i < ts; ++i) {
            int ones = 0;
            for (auto num : nums)
                ones += (num >> i) & 1;
            res += ones * (n - ones);
        }
        return res;
    }
};

int main() {
    return 0;
}
