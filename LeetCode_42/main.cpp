/**
    LeetCode_42
    https://leetcode.com/problems/trapping-rain-water/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int lMax = 0, rMax = 0;
        int res = 0;
        while (i < j) {
            lMax = max(height[i], lMax);
            rMax = max(height[j], rMax);
            if (height[i] < height[j])
                res += lMax - height[i++];
            else
                res += rMax - height[j--];
        }
        return res;
    }
};

int main() {
    return 0;
}
