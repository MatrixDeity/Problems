/**
    LeetCode_167
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int n = (int) numbers.size();
        int i = 0, j = n - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                res.push_back(i + 1); // Counting from ONE!
                res.push_back(j + 1); // Counting from ONE!
                return res;
            }
            if (sum < target)
                ++i;
            else
                --j;
        }
        return res;
    }
};

int main() {
    return 0;
}
