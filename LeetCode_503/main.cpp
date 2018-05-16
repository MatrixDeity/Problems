/**
    LeetCode_503
    https://leetcode.com/problems/next-greater-element-ii/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> res(n);
        for (int i = 2 * n - 1; i >= 0; --i) {
            int j = i % n;
            while (!stk.empty() && stk.top() <= nums[j]) {
                stk.pop();
            }
            res[j] = !stk.empty() ? stk.top() : -1;
            stk.push(nums[j]);
        }
        return res;
    }
};

int main() {
    return 0;
}
