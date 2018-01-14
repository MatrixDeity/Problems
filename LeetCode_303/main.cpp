/**
    LeetCode_303
    https://leetcode.com/problems/range-sum-query-immutable/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    using ll = long long;

    vector<ll> sums;
    int n;

public:
    NumArray(vector<int> nums) :
    sums(nums.size()),
    n(nums.size()) {
        ll sum = 0LL;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            sums[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        int a = sums[j];
        int b = i > 0 ? sums[i - 1] : 0;
        return a - b;
    }
};

int main() {
    return 0;
}
