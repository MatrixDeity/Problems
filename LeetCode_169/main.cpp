/**
    LeetCode_169
    https://leetcode.com/problems/majority-element/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        for (auto num : nums) {
            if (cnt == 0)
                ans = num;
            cnt += ans == num ? +1 : -1;
        }
        return ans;
    }
};

int main() {
    return 0;
}
