/**
    LeetCode_11
    https://leetcode.com/problems/container-with-most-water/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int vol = 0;
        while (i < j) {
            int h = min(height[i], height[j]);
            vol = max((j - i) * h, vol);
            while (i < j && height[i] <= h)
                ++i;
            while (i < j && height[j] <= h)
                --j;
        }
        return vol;
    }
};

int main() {
    return 0;
}
