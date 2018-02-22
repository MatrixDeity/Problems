/**
    LeetCode_189
    https://leetcode.com/problems/rotate-array/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        function<void(int, int)> rot = [&nums] (int i, int j) {
            while (i < j) {
                swap(nums[i++], nums[--j]);
            }
        };
        rot(0, n);
        rot(0, k);
        rot(k, n);
    }
};

int main() {
    return 0;
}
