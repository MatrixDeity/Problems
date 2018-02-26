/**
    LeetCode_453
    https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        int mn = *min_element(nums.begin(), nums.end());
        for (auto item : nums) {
            res += item - mn;
        }
        return res;
    }
};

int main() {
    return 0;
}
